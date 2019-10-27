#include <stdio.h>
int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char buf[96], str[96], sub;
    int n;
    while (fgets(buf, sizeof buf, file) != NULL) {
        sscanf(buf, "%99[^,]%n,%c", str, &n, &sub);
        if (sub == '\n') {
            printf("-1\n");
            continue;
        }
        int found = 0;
        for (int i = n; i >= 0 && !found; --i) {
            if (str[i] == sub) {
                printf("%i\n", i);
                found = 1;
            }
        }
        if (!found) printf("-1\n");
    }
    return 0;
}
