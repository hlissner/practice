#include <stdio.h>

#define MAXLEN 192

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    char buf[MAXLEN];
    while(fgets(buf, sizeof buf, file) != NULL) {
        int arrows = 0;
        for (int i = 0; i < (MAXLEN-5) && buf[i] != '\0'; ++i) {
            char c = buf[i];
            if ((c == '<' && buf[i+1] == '-' && buf[i+2] == '-' && buf[i+3] == c && buf[i+4] == c)
                 || (c == '>' && buf[i+1] == c && buf[i+2] == '-' && buf[i+3] == '-' && buf[i+4] == c)) {
                ++arrows;
            }
        }
        printf("%d\n", arrows);
    }

    return 0;
}
