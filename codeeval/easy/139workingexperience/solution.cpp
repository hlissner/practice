#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

map<string, int> months = {
    {"Jan", 0},
    {"Feb", 1},
    {"Mar", 2},
    {"Apr", 3},
    {"May", 4},
    {"Jun", 5},
    {"Jul", 6},
    {"Aug", 7},
    {"Sep", 8},
    {"Oct", 9},
    {"Nov", 10},
    {"Dec", 11}
};

struct Date {
    short month;
    int year;

    Date(string str) {
        istringstream ss(str);
        string month;
        ss >> month;
        ss >> this->year;

        this->month = months[month];
    }
};

int main(int, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        istringstream ss(line);

        string date;
        int months = 0;
        while (getline(ss, date, ';')) {
            ss.ignore(); // ignore whitespace

            istringstream dss(date);

            string str;
            getline(dss, str, '-');
            Date from(str);

            getline(dss, str, '\n');
            Date to(str);

            months += (abs(to.year - from.year) * 12) + (to.month - from.month);
        }

        cout << floor(months / 12) << endl;
    }
    return 0;
}
