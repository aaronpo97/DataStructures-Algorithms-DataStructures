#pragma once

#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

//@todo restrict to random access containers using c++ concepts

template <typename T>
inline bool is_sorted(T const &container) {
    for (auto i = 1; i < container.size(); ++i)
        if (container[i] < container[i - 1])
            return false;

    return true;
}

template <typename C>
void shuffle(C &container, size_t shuffle_count = 1) {
    if (container.size() < 2)
        return;

    std::random_device rd;
    std::mt19937       gen(rd());

    for (size_t i{0}; i < shuffle_count; ++i) {
        for (size_t i = container.size() - 1; i > 0; --i) {
            std::uniform_int_distribution<size_t> distrib(0, i);
            size_t                                j = distrib(gen);
            std::swap(container[i], container[j]);
        }
    }
}

#if (defined(SORTED_ASC) + defined(SORTED_DESC) + defined(UNSORTED)) != 1
#error "Define exactly one of SORTED_ASC, SORTED_DESC, or UNSORTED"
#endif
#if defined(SORTED_ASC)
std::array<char, 26> array_tester{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                                  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::vector<char>    vector_tester(std::begin(array_tester),
                                   std::end(array_tester));
std::deque<char> deque_tester(std::begin(array_tester), std::end(array_tester));
#elif defined(SORTED_DESC)
std::array<char, 26> array_tester{'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R',
                                  'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I',
                                  'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
std::vector<char>    vector_tester(std::begin(array_tester),
                                   std::end(array_tester));
std::deque<char> deque_tester(std::begin(array_tester), std::end(array_tester));

#elif defined(UNSORTED)
std::array<char, 26> array_tester{'M', 'A', 'R', 'C', 'H', 'I', 'N', 'G', 'T',
                                  'O', 'W', 'N', 'X', 'Y', 'Z', 'B', 'E', 'F',
                                  'G', 'H', 'J', 'K', 'L', 'P', 'Q'};
std::vector<char>    vector_tester(std::begin(array_tester),
                                   std::end(array_tester));
std::deque<char> deque_tester(std::begin(array_tester), std::end(array_tester));
#else
#error "Define exactly one of SORTED_ASC, SORTED_DESC, or UNSORTED"
#endif

template <typename T, size_t L>
std::ostream &operator<<(std::ostream &os, std::array<T, L> const &container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        os << *it << ' ';
    }
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        os << *it << ' ';
    }
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::deque<T> const &container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        os << *it << ' ';
    }
    return os;
}