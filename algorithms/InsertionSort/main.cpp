// #define ARRAY_SORTED_ASC
// #define ARRAY_SORTED_DESC
#define ARRAY_MIXED

#define USE_ARRAY_SMALL
// #define USE_ARRAY_LARGE

#include "../SortHelper.hpp"

void insertionSort(int *arr, size_t size, int &comparisons, int &swaps) {
    // start at the second element
    for (size_t i = 1; i < size; ++i) {
        // store a copy of the key
        int key = arr[i];
        // iterate through all the elements on the left to see where it goes
        size_t j;

        // Look at elements to the left of i, as long as j >= 0 and current
        // element at j > key
        for (j = i - 1; (j >= 0 && arr[j] > key); --j) {
            ++comparisons;

            // shift the element at j to the right 1 position
            arr[j + 1] = arr[j];
        }

        // Add one if an element comparison causes the loop exit

        comparisons += (j < 0) ? 0 : 1;

        // copy the key into its sorted position
        if (j + 1 != i) {
            arr[j + 1] = key;
            ++swaps;
        }
    }
}

int main(int argc, char **argv) {

    int comparisons{0};
    int swaps{0};

    std::cout << "Insertion Sort Algorithm Test\n";

    // init array variables
    int   *array = nullptr;
    size_t size{};

#ifdef USE_ARRAY_SMALL
    array = arr_5;
    size  = ArraySizeSmall;
#elif defined(USE_ARRAY_LARGE)
    array = arr_10;
    size  = ArraySizeLarge;
#endif
    // Print the original array
    std::cout << "Array input:\t";
    printArray(array, size);

    // Sort
    insertionSort(array, size, comparisons, swaps);

    printArray(array, size);

    std::cout << "Number of comparisons " << comparisons << "\n";
    std::cout << "Number of swaps " << swaps << "\n";
    return EXIT_SUCCESS;
}