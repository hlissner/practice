#include <iostream>
#include <fstream>

using namespace std;

// Why a C-style array and not a vector? Just cause.
const int COINS[] = {5, 3, 1};
const int COINSC = (sizeof(COINS)/sizeof(*COINS));

int main(int argc, char *argv[]) {
    if (argc > 1) {
        ifstream infile(argv[1]);
        int amount;
        while (infile >> amount) {
            int coins = 0;
            for (int i = 0; i < COINSC; ++i) {
                if (amount <= 0) break;
                int count = (int) amount / COINS[i];
                coins += count;
                if (count != 0) {
                    amount -= COINS[i] * count;
                }
            }
            cout << coins << endl;
        }
    } else {
        cout << "Usage: " << argv[0] << " [data-file]" << endl;
        return 1;
    }
    return 0;
}
