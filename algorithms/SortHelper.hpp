/*
        T. Haworth
        September 2025

        Module containing shared declarations and logic for sort demonstrations
*/

#pragma once

#include <iostream>

// Array size constant expressions
constexpr size_t ArraySizeSmall = 5;
constexpr size_t ArraySizeLarge = 10;

// Best case arrays (already sorted)
#ifdef ARRAY_SORTED_ASC
int arr_5[ArraySizeSmall]{1, 2, 3, 4, 5};
int arr_10[ArraySizeLarge]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Worst case (already sorted in descending order)
#elif defined(ARRAY_SORTED_DESC)
int arr_5[ArraySizeSmall]{5, 4, 3, 2, 1};
int arr_10[ArraySizeLarge]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

// Average case (pseudo-randomly unsorted)
#elif defined(ARRAY_MIXED)
int arr_5[ArraySizeSmall]{5, 1, 2, 4, 3};
int arr_10[ArraySizeLarge]{5, 1, 2, 4, 3, 10, 8, 7, 6, 9};
#endif

// Given references to two int references, swaps the values stored by each at
// their original memory addresses
inline void swap(int &lhs, int &rhs) {
    int temp = lhs;
    lhs      = rhs;
    rhs      = temp;
}

// Dump the contents of an array to the console
inline void printArray(int *arr, size_t const size) {
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << (i < size - 1 ? ", " : "");
    std::cout << std::endl;
}
