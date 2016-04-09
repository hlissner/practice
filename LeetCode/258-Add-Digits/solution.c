#include <stdio.h>
#include <stdlib.h>


// Naive solution: O(n log n)
int naiveAddDigits(int num) {
    if (num < 0) num = abs(num);
    if (num < 10) return num;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return naiveAddDigits(sum);
}

// O(1) solution
int addDigits(int num) {
    return 1 + ((abs(num)-1) % 9);
}


int main() {
    // Positive
    printf("%d %d\n", addDigits(38),   naiveAddDigits(38) );
    printf("%d %d\n", addDigits(199),  naiveAddDigits(199));
    printf("%d %d\n", addDigits(4),    naiveAddDigits(4)  );
    // Negatives
    printf("%d %d\n", addDigits(-38),  naiveAddDigits(-38) );
    printf("%d %d\n", addDigits(-199), naiveAddDigits(-199));
    printf("%d %d\n", addDigits(-4),   naiveAddDigits(-4)  );
    return 0;
}
