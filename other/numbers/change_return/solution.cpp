#include <iostream>
#include <iomanip>

using namespace std;

struct Coin {
    // Why not a string? To align the struct to 16 bytes. Premature optimization
    // isn't the root of all evil, I am!
    char  label[12];
    float base_value;

    int how_many_for(float amount) const {
        return (int) (amount / base_value);
    }

    float how_much_for(int count) const {
        return count * base_value;
    }
};

// Why a C-style array and not a vector? Just cause.
const Coin coins[] = {
    {"Toonies",   2.00},
    {"Loonies",   1.00},
    {"Quarters",  .25},
    {"Dimes",     .10},
    {"Nickels",   .05},
    {"Pennies",   .01}
};

//////////////////////////////////////

void print_row(const char label[], int count, float value) {
    cout.precision(2);
    cout << setw(25) << left << label
         << setw(5)  << count
         << setw(10) << fixed << right << value
         << endl;
}

void print_div() {
    cout << setw(40) << setfill('=') << "" << setfill(' ') << "" << endl;
}

void print_header() {
    cout << setw(25) << left << "Coin "
         << setw(5) << left << "QTY"
         << setw(10) << right << "Value" << endl;
    print_div();
}

void print_footer(float total) {
    print_div();
    cout << setw(40) << right << total << endl;
}

//////////////////////////////////////

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // add 0.001 to fix miniscule precision loss
        float amount = atof(argv[1]) + 0.001;
        float total = amount;

        // If you extract the loop into a function measuring a C-style array's
        // length like this won't work. Arrays degrade into pointers as
        // arguments.
        short length = (sizeof(coins)/sizeof(*coins));

        print_header();
        for (int i = 0; i < length; ++i) {
            if (amount <= 0.00) break;
            int count = coins[i].how_many_for(amount);
            if (count != 0) {
                float value = coins[i].how_much_for(count);
                print_row(coins[i].label, count, value);
                amount -= value;
            }
        }
        print_footer(total);
    } else {
        cout << "Usage: " << argv[0] << " [amount]" << endl;
        return 1;
    }
    return 0;
}
