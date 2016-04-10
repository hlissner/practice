#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Note: If you want simpler solutions, look at the other solutions I've done,
// like the python one. I am intentionally being pedantic here.

////////////////////////////////////////
// Helpers /////////////////////////////
////////////////////////////////////////

// Superior to (sizeof(array)/sizeof(*array)) because it fails to compile for
// non array types. Visual studio has _countof, but emacs mastah race.
// Note: C++11's std::array exposes its length with no additional overhead over
// C arrays.
template <typename T,unsigned S>
inline unsigned array_size(const T (&v)[S]) { return S; }

void print_inline(const std::string label, const uint objects[], uint length) {
    cout << setw(16) << label << ": ";
    for (uint i = 0; i < length; ++i)
        cout << objects[i] << " ";
    cout << endl;
}

void swap(uint * a, uint * b) {
    if (a == NULL || b == NULL)
        return;
    uint *temp = b;
    b = a;
    a = temp;
}

// std::copy does _exactly_ this.
template <typename T>
void copy_array(T *a, T *end, T b[]) {
    int length = end - a;
    for (int i = 0; i < length; ++i)
        b[i] = a[i];
}


////////////////////////////////////////
// Implementations /////////////////////
////////////////////////////////////////

// Pre-incrementing is slightly more preformant than post. However, the benefit
// is negligable for primitive types like ints, so I'm just being pedantic. The
// beneit is more pronounced for class objects that override operator++;

void insertion_sort(uint objects[], const uint length) {
    for (uint i = 1, j; i < length; ++i) {
        uint x = objects[i];
        for (j = i; j > 0 && objects[j-1] > x; --j)
            objects[j] = objects[j-1];
        objects[j] = x;
    }
}

void bubble_sort(uint objects[], int length) {
    bool sorted;
    // After each iteration the last j elements are sorted, so we stop the loop
    // j elements early to save time.
    int j = 0;
    do {
        sorted = false;
        for (int i = 0; i < length-j; ++i) {
            if (objects[i] > objects[i+1]) {
                swap(objects[i], objects[i+1]);
                sorted = true;
            }
        }
        ++j;
    } while (sorted);
}

// The challenge is to partition virtually, with indicies, rather than using
// local arrays everywhere.
//   TODO: Do a median-of-three implementation (maybe?)
void quick_sort(uint objects[], const uint left, const uint right) {
    uint pivot = objects[(int) ((left+right) / 2)];
    uint i = left;
    uint j = right;
    while (i <= j) {
        // Find next elements to swap
        while (pivot > objects[i]) ++i;
        while (pivot < objects[j]) --j;
        if (i <= j) {
            swap(objects[i], objects[j]);
            ++i;
            --j;
        }
    }

    // Divide and conquer
    if (left < j)  quick_sort(objects, left, j);
    if (right > i) quick_sort(objects, i, right);
}

// std::array or std::vector would make this much easier, but that would be
// *too* easy.
void merge_sort(uint objects[], const uint length, uint *result) {
    // The base case
    if (length <= 1) {
        if (result != NULL)
            result[0] = objects[0];
        return;
    }

    const uint pivot = length / 2;
    const uint right_length = length - pivot;
    uint left[pivot];
    uint right[right_length];

    // Divide and conquer
    merge_sort(&objects[0], pivot, left);
    merge_sort(&objects[pivot], right_length, right);

    // Bring it all together
    if (result == NULL)
        return;
    for (uint i = 0, ai = 0, bi = 0; i < pivot + right_length; ++i) {
        result[i] = ai < pivot && (bi >= right_length || left[ai] < right[bi])
                         ? left[ai++]
                         : right[bi++];

    }
}


////////////////////////////////////////
// Bootstrap ///////////////////////////
////////////////////////////////////////

int main() {
    uint values[] = {6,5,12,3,11,1,8,7,2,3,10,4,9,13};
    uint length = array_size(values);
    uint result[length];

    uint *end = values + length;

    print_inline("Original", values, length); // before

    copy_array(values, end, result);
    insertion_sort(result, length);
    print_inline("Insertion Sort", result, length); // after

    copy_array(values, end, result);
    quick_sort(result, 0, length);
    print_inline("Quick Sort", result, length); // after

    copy_array(values, end, result);
    bubble_sort(result, length);
    print_inline("Bubble Sort", result, length); // after

    merge_sort(values, length, result);
    print_inline("Merge Sort", result, length); // after

    return 0;
}
