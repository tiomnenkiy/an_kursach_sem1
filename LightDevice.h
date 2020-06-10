#ifndef KUL_LIGHTDEVICE_H
#define KUL_LIGHTDEVICE_H

#include <string>
#include <vector>
#include "Gadget.h"
#include "PowerSupply.h"
using namespace std;
// abstract class
class LightDevice {
    int Light;
    int Power;
    int Voltage;
    //resistance
public:
    LightDevice(int data_light, int data_power, int data_voltage);
    int GetLight() const {return Light;}
    int GetPover() const {return Power;}
    int GetVoltage() const {return Voltage;}
    void SetLight(int data_light) {Light = data_light;}
    ~LightDevice() = default;
};

class Lamp : public LightDevice, public Gadget {
    int Color;
public:
    Lamp(int data_light, int data_power, int data_voltage, int data_color,
            int data_price, int data_mass, int data_length, int data_width, int data_hight, int data_id);
    ~Lamp() = default;
    int GetPower() const {return GetPover();}
    Lamp operator++ () {SetLight(GetLight()+1); return *this;}
    int GetColor() const {return Color;}
    void Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) override;
    void Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) override;
};

class Monitor : public LightDevice, public Gadget {
    string Type;
public:
    Monitor(int data_light, int data_power, int data_voltage,
            int data_price, int data_mass, int data_length,
            int data_width, int data_hight, int data_id, string data_type);
    ~Monitor() = default;
    int GetPower() const {return GetPover();}
    Monitor operator+ (int value);
    string GetType() const {return Type;}
    void ChangeLight(int delta);
    void Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) override;
    void Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) override;
};

int SearchLamp (vector<Lamp>& arr, int left, int right, int key);

int SearchMonitor (vector<Monitor>& arr, int left, int right, int key);

#endif //KUL_LIGHTDEVICE_H