#include "Files.h"

bool ChangeLang (bool lang, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus, string& conf) {
    lines.clear(); // тут нельзя использовать lines
    string line;
    ifstream file_conf(conf);
    if (!file_conf.is_open()) {
        file_conf.open(eng);
        if(!file_conf.is_open()) {
            cout << "we can't open file " << eng << endl;
            exit(-1);
        }
    }
    file_conf >> line;
    file_conf >> eng;
    file_conf >> rus;
    file_conf.close();

    if (!lang) {
        lang = 1;
        FileManager(lang, file_eng, eng, 155, lines);
        if (!file_eng.is_open()) {
            file_eng.open(eng);
            if(!file_eng.is_open()) {
                cout << "we can't open file " << eng << endl;
                exit(-1);
            }
        }

        while (file_eng) {
            getline(file_eng, line);
            lines.push_back(line);
        }
        file_eng.close();
    } else {
        lang = 0;
        FileManager(lang, file_rus, rus, 155, lines);
        if (!file_rus.is_open()) {
            file_rus.open(rus);
            if(!file_rus.is_open()) {
                cout << "не можем открыть файл " << rus << endl;
                exit(-1);
            }
        }

        while (file_rus) {
            getline(file_rus, line);
            lines.push_back(line);
        }
        file_rus.close();
    }
    return lang;
}

bool FileManager(bool lang, ifstream& file, string name, int stringInFile, vector<string>& lines) {
    if (!file.is_open()) {
        file.open(name);
        if(!file.is_open()) {
            cout << lines.at(134) << name << endl;
            exit(-1);
        }
    }

    string str;
    file.unsetf(std::ios_base::skipws);

    unsigned line_count = count(istream_iterator<char>(file), istream_iterator<char>(), '\n');
    line_count++;
    if (line_count< stringInFile) {
        cout << "File " << name << " has not enough lines" << endl;
        exit(-1);
    }
    if (line_count > stringInFile) {
        cout << "File " << name << " has to many lines" << endl;
        exit(-1);
    }
    file.close();
    return lang;
}

void PrintFile(string path, vector<string>& lines) {
    ifstream file(path);
    if (!file.is_open()) {
        file.open(path);
        if(!file.is_open()) {
            cout << lines.at(134) << path << endl;
            exit(-1);
        }
    }
    string str;
    getline(file, str);
    while (file) {
        cout << str << endl;
        getline(file, str);
    }
    file.close();
}

string Configuration(bool lang, string& eng, string& rus,
                     string& eng_about, string& rus_about, string& eng_prog,
                     string& rus_prog, string& eng_screen, string& rus_screen,
                     string& output, vector<string>& lines) {
    int k = 10;
    string path;
    ifstream file_eng(eng);
    ifstream file_rus(rus);
    string conf_path = GetConfPath();
    lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
    do {
        ifstream conf("/home/merso/CLionProjects/kul/configuration.txt");
        if (!conf.is_open()) {
            conf.open("/home/merso/CLionProjects/kul/configuration.txt");
            if(!conf.is_open()) {
                cout << lines.at(134) << "/home/merso/CLionProjects/kul/configuration.txt" << endl;
                exit(-1);
            }
        }
        conf >> output;
        conf >> eng;
        conf >> rus;
        conf >> eng_about;
        conf >> rus_about;
        conf >> eng_prog;
        conf >> rus_prog;
        conf >> eng_screen;
        conf >> rus_screen;

        cout << lines.at(123) << endl;
        cout << lines.at(124) << endl;
        cout << lines.at(125) << endl;
        cout << lines.at(126) << endl;
        cout << lines.at(127) << endl;
        cout << lines.at(128) << endl;
        cout << lines.at(129) << endl;
        cout << lines.at(130) << endl;
        cout << lines.at(131) << endl;
        cout << lines.at(132) << endl;
        cout << lines.at(133) << endl;
        cout << lines.at(5) << endl;
        cout << lines.at(6);
        k = InputDigit(lang, lines);

        if (k == 0) {
            return output;
        } else if (k == 1) {
            ChangePath(lang, k, output, lines);
        } else if (k == 2) {
            ChangePath(lang, k, eng, lines);
        } else if (k == 3) {
            ChangePath(lang, k, rus, lines);
        } else if (k == 4) {
            ChangePath(lang, k, eng_about, lines);
        } else if (k == 5) {
            ChangePath(lang, k, rus_about, lines);
        } else if (k == 6) {
            ChangePath(lang, k, eng_prog, lines);
        } else if (k == 7) {
            ChangePath(lang, k, rus_prog, lines);
        } else if (k == 8) {
            ChangePath(lang, k, eng_screen, lines);
        } else if (k == 9) {
            ChangePath(lang, k, rus_screen, lines);
        } else if (k == 10) {
            ifstream file_eng(eng);
            ifstream file_rus(rus);
            string conf_path = GetConfPath();
            lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
            file_eng.close();
            file_rus.close();
        }

        conf.close();
        ofstream conf_out("/home/merso/CLionProjects/kul/configuration.txt");
        if (!conf_out.is_open()) {
            conf_out.open("/home/merso/CLionProjects/kul/configuration.txt");
            if(!conf_out.is_open()) {
                cout << lines.at(134) << "/home/merso/CLionProjects/kul/configuration.txt" << endl;
                exit(-1);
            }
        }
        conf_out << output << endl;
        conf_out << eng << endl;
        conf_out << rus << endl;
        conf_out << eng_about << endl;
        conf_out << rus_about << endl;
        conf_out << eng_prog << endl;
        conf_out << rus_prog << endl;
        conf_out << eng_screen << endl;
        conf_out << rus_screen;
        conf_out.close();
    } while (k);

    return path;
}

void ChangePath (bool lang, int key, string& path, vector<string>& lines) {
    string new_path;
    cout << lines.at(135) << endl;
    cin.ignore(32767, '\n');
    getline(cin, new_path);
    while (new_path.empty()) {
        cout << lines.at(34) << endl << lines.at(136);
    }
    path = new_path;
    ifstream file(path);
    if(key == 2 || key == 3) {
        FileManager(lang, file, path, 155, lines);
    } else {
        if (!file.is_open()) {
            file.open(path);
            if(!file.is_open()) {
                cout << lines.at(134) << path << endl;
                exit(-1);
            }
        }
    }
    file.close();
    cout << lines.at(137) << endl;
}

string GetConfPath() {
    return "/home/merso/CLionProjects/kul/configuration.txt";
}

bool Save (bool lang, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa, vector<PowerSupply>& network,
           vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
           vector<string>& lines, ofstream& file_out, string out) {
    if (!file_out.is_open()) {
        file_out.open(out);
        if(!file_out.is_open()) {
            cout << lines.at(134) << out << endl;
            exit(-1);
        }
    }


    if(!bat_aa.empty() || !bat_aaa.empty() || !network.empty()) {
        file_out << lines.at(138) << endl;
        if(!bat_aa.empty()) {
            file_out << lines.at(51) << endl;
            file_out << lines.at(52) << bat_aa.size() << endl;
            for (int i = 0; i < bat_aa.size(); ++i) {
                file_out << lines.at(53) << bat_aa[i].GetId() << endl << lines.at(54) << bat_aa[i].GetPower() << endl
                    << lines.at(55) << bat_aa[i].GetVoltage() << endl << lines.at(139) << bat_aa[i].GetGadgetsNum()
                    << endl << endl;
            }
        }
        if(!bat_aaa.empty()) {
            file_out << lines.at(56) << endl;
            file_out << lines.at(52) << bat_aaa.size() << endl;
            for (int i = 0; i < bat_aaa.size(); ++i) {
                file_out << lines.at(53) << bat_aaa[i].GetId() << endl << lines.at(54) << bat_aaa[i].GetPower() << endl
                     << lines.at(55) << bat_aaa[i].GetVoltage() << endl << lines.at(139) << bat_aaa[i].GetGadgetsNum()
                     << endl << endl;
            }
        }
        if(!network.empty()) {
            file_out << lines.at(57) << endl;
            file_out << lines.at(52) << network.size() << endl;
            for (int i = 0; i < network.size(); ++i) {
                file_out << lines.at(53) << network[i].GetId() << endl << lines.at(54) << network[i].GetPower() << endl
                     << lines.at(55) << network[i].GetVoltage() << endl << lines.at(139) << network[i].GetGadgetsNum()
                     << endl << endl;
            }
        }
    }
    
    if(!lamps.empty() || !monitors.empty() || !computers.empty()) {
        file_out << lines.at(140) << endl;
        if(!lamps.empty()) {
            file_out << lines.at(59) << endl;
            file_out << lines.at(52) << lamps.size() << endl;
            for (int i = 0; i < lamps.size(); ++i) {
                file_out << lines.at(53) << lamps[i].GetId() << endl << lines.at(54) << lamps[i].GetPower() << endl
                     << lines.at(55) << lamps[i].GetVoltage() << endl << lines.at(141) << lamps[i].GetLight() << endl
                     << lines.at(142);
                if (lamps[i].GetState()) {
                    file_out << lines.at(143);
                } else {
                    file_out << lines.at(144);
                }
                file_out << endl;
                switch (lamps[i].GetColor()) {
                    case 1:
                        file_out << lines.at(61) << endl;
                        break;
                    case 2:
                        file_out << lines.at(62) << endl;
                        break;
                    case 3:
                        file_out << lines.at(63) << endl;
                        break;
                    case 4:
                        file_out << lines.at(64) << endl;
                        break;
                    case 5:
                        file_out << lines.at(65) << endl;
                        break;
                    case 6:
                        file_out << lines.at(66) << endl;
                        break;
                    case 7:
                        file_out << lines.at(67) << endl;
                        break;
                }   
                file_out << lines.at(145) << lamps[i].GetLength() << endl << lines.at(146) << lamps[i].GetWidth() << endl
                    << lines.at(147) << lamps[i].GetHight() << endl << lines.at(148) << lamps[i].GetMass() << endl 
                    << lines.at(60) << lamps[i].GetPrice() << endl << lines.at(149);
                switch (lamps[i].GetPowerSupplyType()) {
                    case 1:
                        file_out << lines.at(150) << endl;
                        break;
                    case 2:
                        file_out << lines.at(151) << endl;
                        break;
                    case 3:
                        file_out << lines.at(152) << endl;
                        break;
                }
                file_out << lines.at(153) << lamps[i].GetPowerSupplyId() << endl << endl;
            }
        }
        if(!monitors.empty()) {
            file_out << lines.at(68) << endl;
            file_out << lines.at(52) << monitors.size() << endl;
            for (int i = 0; i < monitors.size(); ++i) {
                file_out << lines.at(53) << monitors[i].GetId() << endl << lines.at(54) << monitors[i].GetPower() << endl
                     << lines.at(55) << monitors[i].GetVoltage() << endl << lines.at(141) << monitors[i].GetLight() << endl
                     << lines.at(142);
                if (monitors[i].GetState()) {
                    file_out << lines.at(143);
                } else {
                    file_out << lines.at(144);
                }
                file_out << endl;
                file_out << "type:" << monitors[i].GetType() << endl;
                file_out << lines.at(145) << monitors[i].GetLength() << endl << lines.at(146) << monitors[i].GetWidth() << endl
                     << lines.at(147) << monitors[i].GetHight() << endl << lines.at(148) << monitors[i].GetMass() << endl
                     << lines.at(60) << monitors[i].GetPrice() << endl << lines.at(149);
                switch (monitors[i].GetPowerSupplyType()) {
                    case 1:
                        file_out << lines.at(150) << endl;
                        break;
                    case 2:
                        file_out << lines.at(151) << endl;
                        break;
                    case 3:
                        file_out << lines.at(152) << endl;
                        break;
                }
                file_out << lines.at(153) << monitors[i].GetPowerSupplyId() << endl << endl;
            }
        }
        if(!computers.empty()) {
            file_out << lines.at(70) << endl;
            file_out << lines.at(52) << computers.size() << endl;
            for (int i = 0; i < computers.size(); ++i) {
                file_out << lines.at(53) << computers[i].GetId() << endl << lines.at(54) << computers[i].GetPower() << endl
                     << lines.at(55) << computers[i].GetVoltage() << endl << lines.at(142);
                if (computers[i].GetState()) {
                    file_out << lines.at(143);
                } else {
                    file_out << lines.at(144);
                }
                file_out << endl;
                file_out << lines.at(154) << computers[i].GetPerformance() << endl;
                file_out << lines.at(145) << computers[i].GetLength() << endl << lines.at(146) << computers[i].GetWidth() << endl
                     << lines.at(147) << computers[i].GetHight() << endl << lines.at(148) << computers[i].GetMass() << endl
                     << lines.at(60) << computers[i].GetPrice() << endl << lines.at(149);
                switch (computers[i].GetPowerSupplyType()) {
                    case 1:
                        file_out << lines.at(150) << endl;
                        break;
                    case 2:
                        file_out << lines.at(151) << endl;
                        break;
                    case 3:
                        file_out << lines.at(152) << endl;
                        break;
                }
                file_out << lines.at(153) << computers[i].GetPowerSupplyId() << endl << endl;
            }
        }
    }

    file_out.close();
    return lang;
}