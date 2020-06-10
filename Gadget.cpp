#include "Gadget.h"

Computer::Computer(int data_price, int data_mass, int data_length, int data_width, int data_hight,
         int data_voltage, int data_power, int data_performance, int data_id)
        : Gadget(data_price, data_mass, data_length, data_width, data_hight, data_id) {
    Voltage = data_voltage;
    Power = data_power;
    Performance = data_performance;
}

void Computer::Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) {
    int x = SearchSupply(p, 0, p.size()-1, supply_id);
    if (x == -1) {
        cout << lines.at(118) << endl;
        return;
    }
    if (p[x].GetVoltage() != GetVoltage()) {
        cout << lines.at(119) << endl;
        return;
    }
    int res = p[x].Plug(GetVoltage(), GetPower(), lines);
    if (res) {
        On();
        SetPowerSupplyId(p[x].GetId());
    }
}

void Computer::Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) {
    Off();
    int x = SearchSupply(p, 0, p.size()-1, supply_id);
    if (x == -1) {
        cout << lines.at(118) << endl;
        return;
    }
    p[x].Unplug(GetPower(), lines);
    SetPowerSupplyId(0);
    SetPowerSupplyType(0);
}

int SearchComputer (vector<Computer>& arr, int left, int right, int key) {
    int mid = 0;
    while (1)
    {
        mid = (left + right) / 2;

        if (key < arr[mid].GetId())
            right = mid - 1;
        else if (key > arr[mid].GetId())
            left = mid + 1;
        else if (key == arr[mid].GetId())
            return mid;

        if (left > right)
            return -1;
    }
}