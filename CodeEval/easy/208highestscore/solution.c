#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    char buf[128];
    while (fgets(buf, sizeof buf, file)) {
        char score[5];
        int scores[20][10];

        int i = 0;
        while (i < (int) sizeof buf) {
            
        }
    }
    return 0;
}
