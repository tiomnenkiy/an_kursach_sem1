#ifndef KUL_GADGET_H
#define KUL_GADGET_H

#include <vector>
#include "PowerSupply.h"

class Gadget {
    int Price;
    int Mass;
    int Length;
    int Width;
    int Hight;
    int State;
    int Id;
    int PowerSupplyId;
    int PowerSupplyType;
public:
    Gadget(int data_price, int data_mass, int data_length, int data_width, int data_hight, int data_id)
        : Price(data_price), Mass(data_mass), Length(data_length), Width(data_width), Hight(data_hight), Id(data_id) {
        State = 0;
        PowerSupplyId = 0;
        PowerSupplyType = 0;
    };
    int GetPrice() const {return Price;}
    int GetMass() const {return Mass;}
    int GetLength() const {return Length;}
    int GetWidth() const {return Width;}
    int GetHight() const {return Hight;}
    int GetState() const {return State;}
    int GetId() const {return Id;}
    virtual int GetPower() {return 0;};
    int GetPowerSupplyId() const {return PowerSupplyId;}
    int GetPowerSupplyType() const {return PowerSupplyType;}
    void SetId(int data) {Id=data;}
    void SetPowerSupplyId(int data) {PowerSupplyId = data;}
    void SetPowerSupplyType(int data) {PowerSupplyType = data;}
    virtual void Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) = 0;
    virtual void Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) = 0;
    void On() {State = 1;}
    void Off() {State = 0;}
    ~Gadget() = default;
};

class Computer : public Gadget {
    int Voltage;
    int Power;
    int Performance;
public:
    Computer(int data_price, int data_mass, int data_length, int data_width, int data_hight,
            int data_voltage, int data_power, int data_performance, int data_id);
    ~Computer() = default;
    int GetVoltage() const {return Voltage;}
    int GetPower() const {return Power;}
    int GetPerformance() const {return Performance;}
    void Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) override;
    void Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) override;
};

int SearchComputer (vector<Computer>& arr, int left, int right, int key);

#endif //KUL_GADGET_H
