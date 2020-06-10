#include "Input.h"

int InputDigit (bool lang, vector<string>& lines) {
    while (true) {
        int a;
        cin >> a;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "wrong input" << endl << "try again:";
        } else if (a < 0) {
            cout << "negative numbers are forbidden" << endl;
            cout << "try again:";
        } else {
            return a;
        }
    }
}

