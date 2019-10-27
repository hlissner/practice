#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define MAX 256

int board[MAX][MAX] = {};

// Helpers
void _set(int x, int value, bool isCol) {
    for (int i = 0; i < MAX; ++i) {
        if (isCol)
            board[i][x] = value;
        else
            board[x][i] = value;
    }
}
int _sum(int x, bool isCol) {
    int sum = 0;
    for (int i = 0; i < MAX; ++i) {
        sum += (isCol ? board[i][x] : board[x][i]);
    }
    return sum;
}

//
void setCol(int j, int x) { _set(j, x, true); }
void setRow(int i, int x) { _set(i, x, false); }
void queryCol(int j) { cout << _sum(j, true)  << endl; }
void queryRow(int i) { cout << _sum(i, false) << endl; }

//
int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);

        string command;
        if (getline(ss, command, ' ')) {
            if (command == "SetRow") {
                int i, x;
                ss >> i >> x;
                setRow(i, x);
            } else if (command == "SetCol") {
                int j, x;
                ss >> j >> x;
                setCol(j, x);
            } else if (command == "QueryRow") {
                int i;
                ss >> i;
                queryRow(i);
            } else if (command == "QueryCol") {
                int j;
                ss >> j;
                queryCol(j);
            }
        }
    }

    return 0;
}
