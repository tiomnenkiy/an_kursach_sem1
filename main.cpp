#include <iostream>
#include <vector>
#include "LightDevice.h"
#include "Files.h"
#include "Menu.h"
using namespace std;

int main() {
    vector<string> lines;
    vector<PowerSupply> bat_aa;
    vector<PowerSupply> bat_aaa;
    vector<PowerSupply> network;
    vector<Lamp> lamps;
    vector<Monitor> monitors;
    vector<Computer> computers;

    bool lang = 0;
    string eng;
    string rus;
    string conf_path;
    string eng_about;
    string rus_about;
    string eng_prog;
    string rus_prog;
    string eng_screen;
    string rus_screen;
    string out;

    out = Configuration(lang, eng, rus, eng_about, rus_about, eng_prog, rus_prog, eng_screen, rus_screen, out, lines);
    ifstream file_eng(eng);
    ifstream file_rus(rus);
    conf_path = GetConfPath();
    lang = ChangeLang(lang, lines, file_eng, file_rus, eng, rus, conf_path);
    MainMenu(lang, lines, bat_aa, bat_aaa, network, lamps, monitors, computers, file_eng, file_rus, eng, rus, eng_about, rus_about, eng_prog, rus_prog, eng_screen, rus_screen, out);

    return 0;
}
