#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Input.h"
#include "PowerSupply.h"
#include "Gadget.h"
#include "LightDevice.h"

using namespace std;

bool FileManager(bool lang, ifstream& file, string name, int stringInFile, vector<string>& lines);

bool ChangeLang(bool lang, vector<string>& lines, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus, string& conf);

void PrintFile(string path, vector<string>& lines);

string Configuration(bool lang, string& eng, string& rus,
                     string& eng_about, string& rus_about, string& eng_prog,
                     string& rus_prog, string& eng_screen, string& rus_screen,
                     string& output, vector<string>& lines);

void ChangePath (bool lang, int key, string& path, vector<string>& lines);

string GetConfPath();


bool Save (bool lang, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa, vector<PowerSupply>& network,
        vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
        vector<string>& lines, ofstream& file_out, string out);
