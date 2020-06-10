#pragma once

#include <vector>
#include "PowerSupply.h"
#include "LightDevice.h"
#include "Gadget.h"
#include "Files.h"
#include "Input.h"

int Search (vector<PowerSupply>& arr, int left, int right, int key);

bool MainMenu (bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
               vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
               ifstream& file_eng, ifstream& file_rus, string& eng, string& rus,
               string& eng_about, string& rus_about, string& eng_prog, string& rus_prog,
               string& eng_screen, string& rus_screen, string& out);

bool Menu(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
          vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
          ifstream& file_eng, ifstream& file_rus, string& eng, string& rus, ofstream& file_out, string out);

bool CreatePowerSupply(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                       vector<PowerSupply>& network, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool CreateGadget(bool lang, vector<string>& lines, vector<Lamp>& lamps, vector<Monitor>& monitors,
        vector<Computer>& computers, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool ManageGadgets(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
              vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
              ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool ShowSupplies (bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                   vector<PowerSupply>& network, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool ShowGadgets (bool lang, vector<string>& lines, vector<Lamp>& lamps, vector<Monitor>& monitors,
                  vector<Computer>& computers, ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);

bool DeletePowerSupply(bool lang, vector<string>& lines, vector<PowerSupply>& bat_aa, vector<PowerSupply>& bat_aaa,
                       vector<PowerSupply>& network, vector<Lamp>& lamps, vector<Monitor>& monitors, vector<Computer>& computers,
                       ifstream& file_eng, ifstream& file_rus, string& eng, string& rus);
