#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int comp(const void *a, const void *b) {
   return (*(int*)b - *(int*)a);
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[512];
    while (fgets(line, 512, f)) {
        int occurrences[26] = {0};

        int len = strlen(line);
        for (size_t i = 0; i < len; ++i) {
            if (isalpha(line[i])) {
                occurrences[tolower(line[i]) - 'a']++;
            }
        }

        qsort(occurrences, 26, sizeof(int), comp);

        int beauty = 0;
        int score = 26;
        for (size_t i = 0; i < 26; ++i) {
            if (occurrences[i] > 0) {
                beauty += score * occurrences[i];
                --score;
            }
        }

        printf("%d\n", beauty);
    }

    return 0;
}
