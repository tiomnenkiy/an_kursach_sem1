#include "Menu.h"

int& NewBatAANum() {static int c = 1; return c;}
int& NewBatAAANum() {static int c = 1; return c;}
int& NewNetworkNum() {static int c = 1; return c;}
int& NewLampNum() {static int c = 1; return c;}
int& NewMonitorNum() {static int c = 1; return c;}
int& NewComputerNum() {static int c = 1; return c;}

bool MainMenu (bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
               vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
               ifstream& file_eng, ifstream& file_rus, string& eng, string& rus,
               string& eng_about, string& rus_about, string& eng_prog, string& rus_prog, string& eng_screen, string& rus_screen, string& out) {
    PrintFile(eng_screen, lines);
    string conf_path("/home/merso/CLionProjects/kurs/config.txt");
    ofstream file_out(out);
    int k=10;
    do {
        cout << lines.at(0) << endl;
        cout << lines.at(1) << endl;
        cout << lines.at(2) << endl;
        cout << lines.at(3) << endl;
        cout << lines.at(4) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputDigit(lang, lines);
        cout << endl << endl;
        if (k == 0) {
            return lang;
        } else if (k == 1) {
            if (lang) {
                PrintFile(eng_screen, lines);
            } else {
                PrintFile(rus_screen, lines);
            }
        } else if (k == 2) {
            if (lang) {
                PrintFile(eng_prog, lines);
            } else {
                PrintFile(rus_prog, lines);
            }
        } else if (k == 3) {
            if (lang) {
                PrintFile(eng_about, lines);
            } else {
                PrintFile(rus_about, lines);
            }
        } else if (k == 4) {
            lang = Menu(lang, lines, bat_aa, bat_aaa, network, lamps, monitors, computers, file_eng, file_rus, eng, rus, file_out, out);
        } else if (k == 5) {
            string conf_path = GetConfPath();
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
        }
    } while (k);
    return lang;
}

bool Menu(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
          vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
          ifstream& file_eng, ifstream& file_rus, string& eng, string& rus, ofstream& file_out, string out) {
    int k=10;
    do {
        if (k) {
            cout << lines.at(7) << endl;
            cout << lines.at(8) << endl;
            cout << lines.at(9) << endl;
            cout << lines.at(10) << endl;
            cout << lines.at(11) << endl;
            cout << lines.at(12) << endl;
            cout << lines.at(5) << endl;
            cout << lines.at(6);
            k = InputDigit(lang, lines);
            cout << endl << endl;
            if (k == 0) {
                return lang;
            } else if (k == 1) {
                lang = CreatePowerSupply(lang, lines, bat_aa, bat_aaa, network, file_eng, file_rus, eng, rus);
            } else if (k == 2) {
                lang = CreateGadget(lang, lines, lamps, monitors, computers, file_eng, file_rus, eng, rus);
            } else if (k == 3) {
                lang = ManageGadgets(lang, lines, bat_aa, bat_aaa, network, lamps, monitors, computers, file_eng, file_rus, eng, rus);
            } else if (k == 4) {
                lang = DeletePowerSupply(lang, lines, bat_aa, bat_aaa, network, lamps, monitors, computers, file_eng, file_rus, eng, rus);
            } else if (k == 5) {
                lang = Save(lang, bat_aa, bat_aaa, network, lamps, monitors, computers, lines, file_out, out);
            } else if (k == 6) {
                string conf_path = GetConfPath();
                lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
            }
        }
    } while (k);
    return lang;
}

bool CreatePowerSupply(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                       vector<PowerSupply>& network, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k=10;
    do {
        if (k) {
            cout << lines.at(13) << endl;
            cout << lines.at(14) << endl;
            cout << lines.at(15) << endl;
            cout << lines.at(16) << endl;
            cout << lines.at(17) << endl;
            cout << lines.at(5) << endl;
            cout << lines.at(6);
            k = InputDigit(lang, lines);
            cout << endl << endl;
            if (k == 0) {
                return lang;
            } else if (k > 0 && k < 4) {
                cout << lines.at(18);
                int power = InputDigit(lang, lines);
                cout << endl << lines.at(19);
                int voltage = InputDigit(lang, lines);
                cout << endl;

                if (k == 1) {
                    PowerSupply new_supply(voltage, power, NewBatAANum());
                    bat_aa.push_back(new_supply);
                    ++NewBatAANum();
                } else if (k == 2) {
                    PowerSupply new_supply(voltage, power, NewBatAAANum());
                    bat_aaa.push_back(new_supply);
                    ++NewBatAAANum();
                } else if (k == 3) {
                    PowerSupply new_supply(voltage, power, NewNetworkNum());
                    network.push_back(new_supply);
                    ++NewNetworkNum();
                }

            }  else if (k == 4) {
                string conf_path = GetConfPath();
                lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
            }
        }
    } while (k);
    return lang;
}

bool CreateGadget(bool lang, vector<string>& lines, vector<Lamp>& lamps, vector<Monitor>& monitors,
                  vector<Computer>& computers, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k=10;
    do {
        if (k) {
            cout << lines.at(20) << endl;
            cout << lines.at(21) << endl;
            cout << lines.at(22) << endl;
            cout << lines.at(23) << endl;
            cout << lines.at(17) << endl;
            cout << lines.at(5) << endl;
            cout << lines.at(6);
            k = InputDigit(lang, lines);
            cout << endl << endl;
            if (k == 0) {
                return lang;
            } if (k == 1) {
                cout <<  lines.at(24);
                int power = InputDigit(lang, lines);
                cout << endl << lines.at(25);
                int voltage = InputDigit(lang, lines);
                int color;
                while(1) {
                    cout << endl << lines.at(26);
                    cout << endl << lines.at(27);
                    cout << endl << lines.at(28);
                    cout << endl << lines.at(29);
                    cout << endl << lines.at(30);
                    cout << endl << lines.at(31);
                    cout << endl << lines.at(32);
                    cout << endl << lines.at(33) << endl;
                    cout << lines.at(6);
                    color = InputDigit(lang, lines);
                    if (color < 1 || color > 7) {
                        cout << endl << lines.at(34) << endl;
                    } else {
                        break;
                    }
                }
                cout << endl << lines.at(35);
                int price = InputDigit(lang, lines);
                Lamp new_lamp(1000, power, voltage, color, price,
                        100, 5, 5, 10, NewLampNum());
                lamps.push_back(new_lamp);
                ++NewLampNum();
            } else if (k == 2) {
                cout << lines.at(36);
                int power = InputDigit(lang, lines);
                cout << endl << lines.at(37);
                int voltage = InputDigit(lang, lines);
                cout << endl << lines.at(38);
                int price = InputDigit(lang, lines);
                string type;
                while(1) {
                    cout << endl << lines.at(39);
                    cout << endl << lines.at(40);
                    cout << endl << lines.at(41);
                    cout << endl << lines.at(42) << endl;
                    cout << lines.at(6);
                    k = InputDigit(lang, lines);
                    cout << endl;
                    if (k < 1 || k > 3) {
                        cout << lines.at(34) << endl;
                    } else {
                        if (k == 1) {
                            type = lines.at(43);
                        } else if (k == 2) {
                            type = lines.at(44);
                        } else if (k == 3) {
                            type = lines.at(45);
                        }
                        break;
                    }
                }
                Monitor new_monitor(500, power, voltage, price, 500, 100, 15, 50, NewMonitorNum(), type);
                monitors.push_back(new_monitor);
                ++NewMonitorNum();
            } else if (k == 3) {
                cout << lines.at(46);
                int power = InputDigit(lang, lines);
                cout << endl << lines.at(47);
                int voltage = InputDigit(lang, lines);
                cout << endl << lines.at(48);
                int performance = InputDigit(lang, lines);
                cout << endl << lines.at(49);
                int price = InputDigit(lang, lines);
                Computer new_computer(price, 8000, 30, 50, 100, voltage, power, performance, NewComputerNum());
                computers.push_back(new_computer);
                ++NewComputerNum();
            }  else if (k == 4) {
                string conf_path = GetConfPath();
                lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
            }
        }
    } while (k);
    return lang;
}

bool ShowSupplies (bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                   vector<PowerSupply>& network, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    if(bat_aa.empty() && bat_aaa.empty() && network.empty()) {
        cout << lines.at(50) << endl;
        return 0;
    }
    if (!bat_aa.empty()) {
        cout << lines.at(51) << endl;
        cout << lines.at(52) << bat_aa.size() << endl << endl;
        for (int i = 0; i < bat_aa.size(); ++i) {
            cout << endl << lines.at(53) << bat_aa[i].GetId() << endl << lines.at(54) << bat_aa[i].GetPower() << endl
                 << lines.at(55) << bat_aa[i].GetVoltage() << endl << endl;
        }
    }
    if (!bat_aaa.empty()) {
        cout << lines.at(56) << endl;
        cout << lines.at(52) << bat_aaa.size() << endl << endl;
        for (int i = 0; i < bat_aaa.size(); ++i) {
            cout << endl << lines.at(53) << bat_aaa[i].GetId() << endl << lines.at(54) << bat_aaa[i].GetPower() << endl
                 << lines.at(55) << bat_aaa[i].GetVoltage() << endl << endl;
        }
    }
    if (!network.empty()) {
        cout << lines.at(57) << endl;
        cout << lines.at(52) << network.size();
        for (int i = 0; i < network.size(); ++i) {
            cout << endl << lines.at(53) << network[i].GetId() << endl << lines.at(54) << network[i].GetPower() << endl
                 << lines.at(55) << network[i].GetVoltage() << endl << endl;
        }
    }
    return 1;
}

bool ShowGadgets (bool lang, vector<string>& lines, vector<Lamp>& lamps, vector<Monitor>& monitors,
                  vector<Computer>& computers, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    if(lamps.empty() && monitors.empty() && computers.empty()) {
        cout << lines.at(58) << endl;
        return 0;
    }
    if (!lamps.empty()) {
        cout << lines.at(59) << endl;
        cout << lines.at(52) << lamps.size() << endl;
        for (int i = 0; i < lamps.size(); ++i) {
            cout << endl << lines.at(53) << lamps[i].GetId() << endl << lines.at(54) << lamps[i].GetPower() << endl
                 << lines.at(55) << lamps[i].GetVoltage() << endl << lines.at(60) << lamps[i].GetPrice() << endl;
            switch (lamps[i].GetColor()) {
                case 1:
                    cout << lines.at(61) << endl;
                    break;
                case 2:
                    cout << lines.at(62) << endl;
                    break;
                case 3:
                    cout << lines.at(63) << endl;
                    break;
                case 4:
                    cout << lines.at(64) << endl;
                    break;
                case 5:
                    cout << lines.at(65) << endl;
                    break;
                case 6:
                    cout << lines.at(66) << endl;
                    break;
                case 7:
                    cout << lines.at(67) << endl;
                    break;
            }
            cout << endl;
        }
    }
    if (!monitors.empty()) {
        cout << endl << endl << lines.at(68) << endl;
        cout << lines.at(52) << monitors.size() << endl;
        for (int i = 0; i < monitors.size(); ++i) {
            cout << endl << lines.at(53) << monitors[i].GetId() << endl << lines.at(54)<< monitors[i].GetPower() << endl
                 << lines.at(55) << monitors[i].GetVoltage() << endl << lines.at(69) << monitors[i].GetType() << endl << lines.at(60) << monitors[i].GetPrice() << endl;
        }
    }
    if (!computers.empty()) {
        cout << endl << endl << lines.at(70) << endl;
        cout << lines.at(52) << computers.size() << endl;
        for (int i = 0; i < computers.size(); ++i) {
            cout << endl << lines.at(53) << computers[i].GetId() << endl << lines.at(54) << computers[i].GetPower() << endl
                 << lines.at(55) << computers[i].GetVoltage() << endl << lines.at(71) << computers[i].GetPerformance() << endl
                 << lines.at(60) << computers[i].GetPrice() << endl;
        }
    }
    return 1;
}

bool ManageGadgets(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                   vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
                   ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k = 10;
    int pos;
    int gadget_type;
    Gadget* cur = nullptr;
    cout << lines.at(72) << endl;
    if (ShowGadgets(lang, lines, lamps, monitors, computers, file_eng, file_rus, eng, rus) == 0) {
        cout << lines.at(73) << endl;
        return lang;
    }
    do {
        if (k) {
            cout << endl;
            cout << lines.at(74) << endl;
            cout << lines.at(75) << endl;
            cout << lines.at(76) << endl;
            cout << lines.at(77) << endl;
            cout << lines.at(78) << endl;
            cout << lines.at(79) << endl;
            cout << lines.at(80) << endl;
            cout << lines.at(81) << endl;
            cout << lines.at(5) << endl;
            cout << lines.at(6);
            k = InputDigit(lang, lines);
            cout << endl << endl;
            if (k == 0) {
                continue;
            } else if (k == 1) {
                if (ShowGadgets(lang, lines, lamps, monitors, computers, file_eng, file_rus, eng, rus) == 0) {
                    cout << lines.at(73) << endl;
                }
                //ShowSupplies() == 0 => cout << "create any supply first" << endl;
            } else if (k == 2) {
                cout << lines.at(82) << endl;
                cout << lines.at(21) << endl;
                cout << lines.at(22) << endl;
                cout << lines.at(23) << endl;
                cout << lines.at(17) << endl;
                cout << lines.at(5) << endl;
                cout << lines.at(6);
                int l = InputDigit(lang, lines);
                if ((l == 1 && lamps.size() == 0) || (l == 2 && monitors.size() == 0) || (l == 3 && computers.size() == 0)) {
                    cout << lines.at(83) << endl;
                    continue;
                }
                cout << endl << endl;
                if (l == 0) {
                    continue;
                } else if (l == 1) {
                    cout << lines.at(84);
                    pos = InputDigit(lang, lines);
                    int x = SearchLamp(lamps, 0, lamps.size()-1, pos);
                    if (x == -1) {
                        cout << lines.at(85) << endl;
                        continue;
                    }
                    cur = &lamps[x];
                    gadget_type = 1;
                    cout << lines.at(86) << endl << lines.at(53) << lamps[x].GetId() << endl
                    << lines.at(54) << lamps[x].GetPower() << endl << lines.at(55) << lamps[x].GetVoltage() << endl;
                } else if (l == 2) {
                    cout << lines.at(87);
                    pos = InputDigit(lang, lines);
                    int x = SearchMonitor(monitors, 0, monitors.size()-1, pos);
                    if (x == -1) {
                        cout << lines.at(88) << endl;
                        continue;
                    }
                    cur = &monitors[x];
                    gadget_type = 2;
                    cout << lines.at(89) << endl << lines.at(53) << monitors[x].GetId() << endl
                         << lines.at(54) << monitors[x].GetPower() << endl << lines.at(55) << monitors[x].GetVoltage() << endl;
                } else if (l == 3) {
                    cout << lines.at(90);
                    pos = InputDigit(lang, lines);
                    int x = SearchComputer(computers, 0, computers.size()-1, pos);
                    if (x == -1) {
                        cout << lines.at(91) << endl;
                    }
                    cur = &computers[x];
                    gadget_type = 3;
                    cout << lines.at(92) << endl << lines.at(53) << computers[x].GetId() << endl
                         << lines.at(54) << computers[x].GetPower() << endl << lines.at(55) << computers[x].GetVoltage() << endl;
                } else if (l == 4) {
                    string conf_path = GetConfPath();
                    lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
                } else {
                    cout << lines.at(93) << endl;
                }
            } else if (k == 3) {
                if (cur == nullptr) {
                    cout << lines.at(94) << endl;
                    continue;
                }
                if (cur->GetPowerSupplyId() == 0) {
                    cout << lines.at(95) << endl << lines.at(96) << endl;
                    continue;
                }
                cur->On();
                cout << lines.at(97) << endl;
            } else if (k == 4) {
                if (cur == nullptr) {
                    cout << lines.at(94) << endl;
                    continue;
                }
                cur->Off();
                cout << lines.at(98) << endl;
            } else if (k == 5) {
                if (cur == nullptr) {
                    cout << lines.at(94) << endl;
                    continue;
                }
                if (cur->GetPowerSupplyId()) {
                    cout << lines.at(99);
                    if (cur->GetPowerSupplyType() == 1) {
                        cout << lines.at(100) << cur->GetPowerSupplyId() << endl;
                        cur->Unsetup(bat_aa, cur->GetPowerSupplyId(), lines);
                    } else if (cur->GetPowerSupplyType() == 2) {
                        cout << lines.at(101) << cur->GetPowerSupplyId() << endl;
                        cur->Unsetup(bat_aaa, cur->GetPowerSupplyId(), lines);
                    } else if (cur->GetPowerSupplyType() == 3) {
                        cout << lines.at(102) << cur->GetPowerSupplyId() << endl;
                        cur->Unsetup(network, cur->GetPowerSupplyId(), lines);
                    }
                    cout << endl;
                }
                cout << lines.at(103) << endl;
                ShowSupplies(lang, lines, bat_aa, bat_aaa, network, file_eng, file_rus, eng, rus);
                cout << lines.at(104) << endl;
                cout << lines.at(14) << endl;
                cout << lines.at(15) << endl;
                cout << lines.at(16) << endl;
                cout << lines.at(6);
                int supply = InputDigit(lang, lines);
                if (supply > 3) {
                    cout << lines.at(105) << endl;
                    continue;
                }
                if (supply == 1 && bat_aa.empty()) {
                    cout << lines.at(106) << endl;
                    continue;
                } else if (supply == 2 && bat_aaa.empty()) {
                    cout << lines.at(106) << endl;
                    continue;
                } else if (supply == 3 && network.empty()) {
                    cout << lines.at(106) << endl;
                    continue;
                }

                cout << lines.at(114);
                int supply_num = InputDigit(lang, lines);
                if (supply == 1) {
                    cur->Setup(bat_aa, supply_num, lines);
                    cur->SetPowerSupplyType(1);
                } else if (supply == 2) {
                    cur->Setup(bat_aaa, supply_num, lines);
                    cur->SetPowerSupplyType(2);
                } else if (supply == 3) {
                    cur->Setup(network, supply_num, lines);
                    cur->SetPowerSupplyType(3);
                }
            } else if (k == 6) {
                if (cur == nullptr) {
                    cout << lines.at(94) << endl;
                    continue;
                }
                if (cur->GetPowerSupplyId() == 0) {
                    cout << lines.at(107) << endl;
                }
                if (cur->GetPowerSupplyType() == 1) {
                    cur->Unsetup(bat_aa, cur->GetPowerSupplyId(), lines);
                } else if (cur->GetPowerSupplyType() == 2) {
                    cur->Unsetup(bat_aaa, cur->GetPowerSupplyId(), lines);
                } else if (cur->GetPowerSupplyType() == 3) {
                    cur->Unsetup(network, cur->GetPowerSupplyId(), lines);
                }
                cur->SetPowerSupplyId(0);
                cur->SetPowerSupplyType(0);
            } else if (k == 7) {
                if (cur == nullptr) {
                    cout << lines.at(94) << endl;
                    continue;
                }
                if (cur->GetPowerSupplyId() != 0) {
                    if (cur->GetPowerSupplyType() == 1) {
                        cur->Unsetup(bat_aa, cur->GetPowerSupplyId(), lines);
                    } else if (cur->GetPowerSupplyType() == 2) {
                        cur->Unsetup(bat_aaa, cur->GetPowerSupplyId(), lines);
                    } else if (cur->GetPowerSupplyType() == 3) {
                        cur->Unsetup(network, cur->GetPowerSupplyId(), lines);
                    }
                }
                cout << endl;
                if (gadget_type == 1) {
                    int x = SearchLamp(lamps, 0, lamps.size()-1, cur->GetId());
                    if (x == -1) {
                        cout << lines.at(85) << endl;
                        continue;
                    }
                    cout << lines.at(108) << endl << lines.at(53) << lamps[x].GetId() << endl
                        << lines.at(54) << lamps[x].GetPower() << endl
                        << lines.at(55) << lamps[x].GetVoltage() << endl << lines.at(109) << endl;
                    lamps.erase(lamps.begin() + x);
                } else if (gadget_type == 2) {
                    int x = SearchMonitor(monitors, 0, monitors.size()-1, cur->GetId());
                    if (x == -1) {
                        cout << lines.at(110) << endl;
                        continue;
                    }
                    cout << lines.at(111) << endl << lines.at(53) << monitors[x].GetId() << endl
                         << lines.at(54) << monitors[x].GetPower() << endl
                         << lines.at(55) << monitors[x].GetVoltage() << endl << lines.at(109) << endl;
                    monitors.erase(monitors.begin() + x);
                } else if (gadget_type == 3) {
                    int x = SearchComputer(computers, 0, computers.size()-1, cur->GetId());
                    if (x == -1) {
                        cout << lines.at(112) << endl;
                        continue;
                    }
                    cout << lines.at(113) << endl << lines.at(53) << computers[x].GetId() << endl
                         << lines.at(54) << computers[x].GetPower() << endl
                         << lines.at(55) << computers[x].GetVoltage() << endl << lines.at(109) << endl;
                    computers.erase(computers.begin() + x);
                }
                cout << endl;
                cur = nullptr;
            } else if (k == 8) {
                string conf_path = GetConfPath();
                lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
            }
        }
    } while (k);
    return lang;
}

bool DeletePowerSupply(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                       vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
                       ifstream& file_eng, ifstream& file_rus, string& eng, string& rus) {
    int k = 10;
    do {
        cout << lines.at(103) << endl;
        ShowSupplies(lang, lines, bat_aa, bat_aaa, network, file_eng, file_rus, eng, rus);
        cout << lines.at(104) << endl;
        cout << lines.at(14) << endl;
        cout << lines.at(15) << endl;
        cout << lines.at(16) << endl;
        cout << lines.at(17) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        int supply = InputDigit(lang, lines);
        if ((supply == 1 && bat_aa.empty()) || (supply == 2 && bat_aaa.empty()) || (supply == 3 && network.empty())) {
            cout << lines.at(106) << endl;
            continue;
        }
        if (supply == 0) {
            return lang;
        } else if (supply == 4) {
            string conf_path = GetConfPath();
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
            continue;
        }
        if (supply > 3) {
            cout << lines.at(105) << endl;
            continue;
        }
        cout << lines.at(114);
        int supply_num = InputDigit(lang, lines);
        int x;
        if (supply == 1) {
            x = SearchSupply(bat_aa, 0, bat_aa.size()-1, supply_num);
            if (x == -1) {
                cout << lines.at(34) << endl;
                continue;
            }
            if (bat_aa[x].GetGadgetsNum() > 0) {
                for (int i = 0; i < lamps.size(); ++i) {
                    if (lamps[i].GetPowerSupplyType() == 1 && lamps[i].GetPowerSupplyId() == supply_num) {
                        lamps[i].Unsetup(bat_aa, supply_num, lines);
                    }
                }
                for (int i = 0; i < monitors.size(); ++i) {
                    if (monitors[i].GetPowerSupplyType() == 1 && monitors[i].GetPowerSupplyId() == supply_num) {
                        monitors[i].Unsetup(bat_aa, supply_num, lines);
                    }
                }
                for (int i = 0; i < computers.size(); ++i) {
                    if (computers[i].GetPowerSupplyType() == 1 && computers[i].GetPowerSupplyId() == supply_num) {
                        computers[i].Unsetup(bat_aa, supply_num, lines);
                    }
                }
            }
            cout << lines.at(115) << endl << lines.at(53) << bat_aa[x].GetId() << endl << lines.at(54) << bat_aa[x].GetPower()
            << endl << lines.at(55) << bat_aa[x].GetVoltage() << endl << lines.at(109) << endl;
            bat_aa.erase(bat_aa.begin() + x);
        } else if (supply == 2) {
            x = SearchSupply(bat_aaa, 0, bat_aaa.size()-1, supply_num);
            if (x == -1) {
                cout << lines.at(34) << endl;
                continue;
            }
            if (bat_aaa[x].GetGadgetsNum() > 0) {
                for (int i = 0; i < lamps.size(); ++i) {
                    if (lamps[i].GetPowerSupplyType() == 1 && lamps[i].GetPowerSupplyId() == supply_num) {
                        lamps[i].Unsetup(bat_aaa, supply_num, lines);
                    }
                }
                for (int i = 0; i < monitors.size(); ++i) {
                    if (monitors[i].GetPowerSupplyType() == 1 && monitors[i].GetPowerSupplyId() == supply_num) {
                        monitors[i].Unsetup(bat_aaa, supply_num, lines);
                    }
                }
                for (int i = 0; i < computers.size(); ++i) {
                    if (computers[i].GetPowerSupplyType() == 1 && computers[i].GetPowerSupplyId() == supply_num) {
                        computers[i].Unsetup(bat_aaa, supply_num, lines);
                    }
                }
            }
            cout << lines.at(116) << endl << lines.at(53) << bat_aaa[x].GetId() << endl << lines.at(54) << bat_aaa[x].GetPower()
                 << endl << lines.at(55) << bat_aaa[x].GetVoltage() << endl << lines.at(109) << endl;
            bat_aaa.erase(bat_aaa.begin() + x);
        } else if (supply == 3) {
            x = SearchSupply(network, 0, network.size() - 1, supply_num);
            if (x == -1) {
                cout << lines.at(34) << endl;
                continue;
            }
            if (network[x].GetGadgetsNum() > 0) {
                for (int i = 0; i < lamps.size(); ++i) {
                    if (lamps[i].GetPowerSupplyType() == 1 && lamps[i].GetPowerSupplyId() == supply_num) {
                        lamps[i].Unsetup(network, supply_num, lines);
                    }
                }
                for (int i = 0; i < monitors.size(); ++i) {
                    if (monitors[i].GetPowerSupplyType() == 1 && monitors[i].GetPowerSupplyId() == supply_num) {
                        monitors[i].Unsetup(network, supply_num, lines);
                    }
                }
                for (int i = 0; i < computers.size(); ++i) {
                    if (computers[i].GetPowerSupplyType() == 1 && computers[i].GetPowerSupplyId() == supply_num) {
                        computers[i].Unsetup(network, supply_num, lines);
                    }
                }
            }
            cout << lines.at(117) << endl << lines.at(53) << network[x].GetId() << endl << lines.at(54) << network[x].GetPower()
                 << endl << lines.at(55) << network[x].GetVoltage() << endl << lines.at(109) << endl;
            network.erase(network.begin() + x);
        }
    } while (k);
    return lang;
}