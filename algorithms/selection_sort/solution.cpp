#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int *items, const int len) {
    for (int i = 0; i < len-1; ++i) {
        int min = i;
        for (int j = i+1; j < len; ++j) {
            if (items[min] > items[j]) {
                min = j;
            }
        }

        if (items[i] != items[min]) {
            swap(items[i], items[min]);
        }
    }
}

int main(int argc, char *argv[]) {
    int A[] = {4, 8, 2, 1, 5, 3, 6, 9, 7, 10};
    const int len = (sizeof(A)/sizeof(*A));

    selection_sort(A, len);
    for (int i = 0; i < len; ++i)
        cout << A[i] << ' ';

    return 0;
}
