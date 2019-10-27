#include <iostream>
#include <fstream>

using namespace std;

struct Coin {
    // Why not a string? To align the struct to 16 bytes. Premature optimization
    // isn't the root of all evil, I am!
    char  label[12];
    float value;
};

// Why a C-style array and not a vector? Just cause.
const Coin COINS[] = {
    {"ONE HUNDRED",  100.00},
    {"FIFTY",        50.00},
    {"TWENTY",       20.00},
    {"TEN",          10.00},
    {"FIVE",         5.00},
    {"TWO",          2.00},
    {"ONE",          1.00},
    {"HALF DOLLAR",  .50},
    {"QUARTER",      .25},
    {"DIME",         .10},
    {"NICKEL",       .05},
    {"PENNY",        .01}
};

//////////////////////////////////////

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    float price, paid;
    char c;
    while (infile >> price >> c >> paid) {
        if (paid < price) {
            cout << "ERROR" << endl;
            continue;
        } else if (paid == price) {
            cout << "ZERO" << endl;
            continue;
        }

        // If you extract the loop into a function measuring a C-style array's
        // length like this won't work. Arrays degrade into pointers as
        // arguments.
        short length = (sizeof(COINS)/sizeof(*COINS));
        float diff = (paid - price) + 0.001;
        for (int i = 0; i < length; ++i) {
            int coins = (diff / COINS[i].value) + 0.001;
            if (coins) {
                for (int j = 0; j < coins; ++j)
                    cout << (j != 0 ? "," : "") << COINS[i].label;
                diff -= coins * COINS[i].value;
                if (diff >= COINS[length-1].value) cout << ",";
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
