#include <stdio.h>
#include <string.h>

const char slang[][32] = {
    ", yeah!",
    ", this is crazy, I tell ya.",
    ", can U believe this?",
    ", eh?",
    ", aw yea.",
    ", yo.",
    "? No way!",
    ". Awesome!"
};

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    short slang_id = 0;
    short other = 0;

    char buf[128];
    char c;
    while (fgets(buf, sizeof buf, file) != NULL) {
        for (int i = 0; i < (int) strlen(buf); ++i) {
            c = buf[i];
            if (c == '.' || c == '?' || c == '!') {
                if (other) {
                    printf("%s", slang[slang_id++]);
                    if (slang_id > 7) {
                        slang_id = 0;
                    }
                } else {
                    putchar(c);
                }
                other = !other;
            } else {
                putchar(c);
            }
        }
    }
    return 0;
}
