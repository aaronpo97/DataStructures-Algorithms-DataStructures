#pragma once

#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <random>
#include <vector>
#include <list>

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

    for (size_t pass = 0; pass < shuffle_count; ++pass) {
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
 
constexpr static inline std::array<char, 26> const alphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


#if defined(SORTED_ASC)
inline std::array<char, 26> array_tester = alphabet;
#elif defined(SORTED_DESC)
inline std::array<char, 26> array_tester = ([](){ 
        auto copy = alphabet;
        std::reverse(std::begin(copy), std::end(copy));
        return copy;
    })();

#elif defined(UNSORTED)
inline std::array<char, 26> array_tester = ([]() {
    auto copy = alphabet;
    shuffle(copy);
    return copy;
})();


#endif

inline std::vector<char> vector_tester(std::begin(array_tester),
                                       std::end(array_tester));

inline std::deque<char>  deque_tester(std::begin(array_tester),
                                      std::end(array_tester));

inline std::list<char> list_tester(std::begin(array_tester),
                                   std::end(array_tester));

template <typename It>
static std::ostream &print_range(std::ostream &os, It first, It last) {
    for (auto it = first; it != last; ++it)
        os << *it << ' ';
    return os;
}

template <typename T, std::size_t L>
std::ostream &operator<<(std::ostream &os, std::array<T, L> const &container) {
    return print_range(os, std::begin(container), std::end(container));
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &container) {
    return print_range(os, std::begin(container), std::end(container));
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::deque<T> const &container) {
    return print_range(os, std::begin(container), std::end(container));
}
template <typename T>
std::ostream &operator<<(std::ostream &os, std::list<T> const &container) {
    return print_range(os, std::begin(container), std::end(container));
}