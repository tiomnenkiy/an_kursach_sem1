#include "PowerSupply.h"

int SearchSupply (vector<PowerSupply>& arr, int left, int right, int key) {
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

bool PowerSupply::Plug(int gadget_voltage, int gadget_power, vector<string>& lines) {
    if (gadget_voltage == Voltage) {
        if (Power - gadget_power < 0) {
            cout << lines.at(120) << endl;
            return false;
        } else {
            Power -= gadget_power;
            ++(*this);
            cout << lines.at(122) << Power << endl;
            return true;
        }
    } else {
        cout << lines.at(121) << endl;
        return false;
    }
}

bool PowerSupply::Unplug(int gadget_power, vector<string>& lines) {
    if (GadgetsNum > 0) {
        Power -= (-gadget_power);
        cout << lines.at(122) << GetPower() << endl;
        --(*this);
        return true;
    }
    return false;
}