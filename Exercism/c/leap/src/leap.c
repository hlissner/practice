#include "leap.h"

int is_leap_year(int y) {
    return y % 4 == 0 && ((y % 100 != 0) || (y % 400 == 0));
}
