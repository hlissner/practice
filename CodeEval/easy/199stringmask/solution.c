#include <stdio.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[48];
    while (fgets(line, 48, file)) {
        int i = 0, j = 0, end;
        while (line[j] != ' ') ++j;
        end = j;
        ++j;

        for (int i = 0; line[i] != '\0'; ++i, ++j) {
            if (line[j] == '1')
                line[i] = toupper(line[i]);
        }

        printf("%.*s\n", end, line);
    }
    return 0;
}
