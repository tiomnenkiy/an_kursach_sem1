#include "LightDevice.h"

LightDevice::LightDevice(int data_light, int data_power, int data_voltage)
    : Light(data_light), Power(data_power), Voltage(data_voltage) {}

Lamp::Lamp(int data_light, int data_power, int data_voltage, int data_color,
     int data_price, int data_mass, int data_length, int data_width, int data_hight, int data_id)
     : Gadget(data_price, data_mass, data_length, data_width, data_hight, data_id),
     LightDevice(data_light, data_power, data_voltage) {
    Color = data_color;
}

Monitor::Monitor(int data_light, int data_power, int data_voltage,
                 int data_price, int data_mass, int data_length, int data_width, int data_hight,int data_id, string data_type)
        : Gadget(data_price, data_mass, data_length, data_width, data_hight, data_id),
          LightDevice(data_light, data_power, data_voltage) {
    Type = data_type;
}

Monitor Monitor::operator+ (int value) {
    SetLight(GetLight() + value);
    return *this;
}

void Monitor::ChangeLight(int delta) {
    if (delta + GetLight() < 0) {
        SetLight(0);
    } else {
        *this + delta;
    }
}

void Lamp::Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) {
    int x = SearchSupply(p, 0, p.size()-1, supply_id);
    if (x == -1) {
        cout << lines.at(118) << endl;
    }
    int res = p[x].Plug(GetVoltage(), GetPower(), lines);
    if (res) {
        On();
        SetPowerSupplyId(p[x].GetId());
    }
}

void Monitor::Setup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) {
    int x = SearchSupply(p, 0, p.size()-1, supply_id);
    if (x == -1) {
        cout << lines.at(118) << endl;
    }
    int res = p[x].Plug(GetVoltage(), GetPower(), lines);
    if (res) {
        On();
        SetPowerSupplyId(p[x].GetId());
    }
}

void Lamp::Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) {
    Off();
    int x = SearchSupply(p, 0, p.size()-1, supply_id);
    if (x == -1) {
        cout << lines.at(118) << endl;
    }
    p[x].Unplug(GetPower(), lines);
    SetPowerSupplyId(0);
    SetPowerSupplyType(0);
}

void Monitor::Unsetup(vector<PowerSupply>& p, int supply_id, vector<string>& lines) {
    Off();
    int x = SearchSupply(p, 0, p.size()-1, supply_id);
    if (x == -1) {
        cout << lines.at(118) << endl;
    }
    p[x].Unplug(GetPower(), lines);
    SetPowerSupplyId(0);
    SetPowerSupplyType(0);
}

int SearchLamp (vector<Lamp>& arr, int left, int right, int key) {
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

int SearchMonitor (vector<Monitor>& arr, int left, int right, int key) {
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