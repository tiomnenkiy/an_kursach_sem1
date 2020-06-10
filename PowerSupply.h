#pragma once

#include <iostream>
#include <vector>
using namespace std;

class PowerSupply {
    int Voltage; // 240 V
    int Power;
    int Id;
    int GadgetsNum;
public:
    PowerSupply(int data_voltage, int data_power, int data_id)
        : Voltage(data_voltage), Power(data_power), Id(data_id) {GadgetsNum = 0;};
    ~PowerSupply() = default;
    int GetVoltage() const {return Voltage;}
    int GetPower() const {return Power;}
    int GetId() const {return Id;}
    int GetGadgetsNum() const {return GadgetsNum;}
    void SetId(int data) {Id = data;}
    void SetPower(int data) {Power = data;}
    bool Plug(int gadget_voltage, int gadget_power, vector<string>& lines);
    bool Unplug(int gadget_power, vector<string>& lines);
    PowerSupply operator++ () {++GadgetsNum; return *this;}
    PowerSupply operator-- () {--GadgetsNum; return *this;}
};

int SearchSupply(vector<PowerSupply>& arr, int left, int right, int key);

