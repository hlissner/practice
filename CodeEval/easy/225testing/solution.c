#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char buf[128];
    while (fgets(buf, 128, f)) {
        int j = 0;
        while (buf[j] != '|') ++j;
        int end = j - 1;
        j += 2;

        int bugs = 0;
        for (int i = 0; i < end; ++i, ++j) {
            if (buf[i] != buf[j]) ++bugs;
        }

        if (bugs > 6) {
            printf("Critical");
        } else if (bugs > 4) {
            printf("High");
        } else if (bugs > 2) {
            printf("Medium");
        } else if (bugs > 0) {
            printf("Low");
        } else {
            printf("Done");
        }
        printf("\n");
    }

    return 0;
}
