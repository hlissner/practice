#include <iostream>
#include <cctype>

using namespace std;

class bob {
public:
    static string hey(const string);
private:
    // Why the OCD const-ness? Because these methods aren't supposed to tamper with input,
    // but if I somehow still manage to, the compiler will warn me.
    static bool is_addressing(const string * const input);
    static bool is_questioning(const string * const input);
    static bool is_shouting(const string * const input);
};
