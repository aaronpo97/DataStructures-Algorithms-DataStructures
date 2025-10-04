#pragma once

/*
 * General algorithm:
 *
 * Repeat for [elements - 1] times
 *   For each element pair:
 *       compare K[i] with K[i+1]
 *           if out of order, swap
 */
namespace bubblesort::bidirectional_iterators {

    template <typename Iter>
    void standard(Iter begin, Iter end) {
        auto firstPair = std::next(begin);
        while (firstPair != end) {
            auto previous = begin;
            auto current  = firstPair;
            while (current != end) {
                if (*current < *previous) {
                    std::swap(*current, *previous);
                }
                previous = current;
                current  = std::next(current);
            }
            end = std::prev(end);
        }
    }

    template <typename Iter>
    void short_circuit(Iter begin, Iter end) {
        auto firstPair   = std::next(begin);
        bool has_swapped = true;

        while (firstPair != end && has_swapped) {
            has_swapped   = false;
            auto previous = begin;
            auto current  = firstPair;

            while (current != end) {
                if (*current < *previous) {
                    std::swap(*current, *previous);
                    has_swapped = true;
                }

                previous = current;
                current  = std::next(current);
            }
            end = std::prev(end);
        }
    }
} // namespace bubblesort::bidirectional_iterators

namespace bubblesort::random_access_container {
    // this will always run cont.size() times, even if list is already sorted

    template <typename C>
    void bruteforce(C &cont) {
        // Outer loop: passes
        for (size_t i = 1; i < cont.size(); ++i) {
            // Inner loop: brute-force, always goes to end
            for (size_t j = 1; j < cont.size(); ++j) {
                if (cont[j] < cont[j - 1]) {
                    std::swap(cont[j], cont[j - 1]);
                }
            }
        }
    }
    template <typename C>
    void standard_1(C &cont) {
        for (size_t i = 1; i < cont.size(); ++i) {
            for (size_t j = 1; j < (cont.size() - i + 1); ++j) {
                if (cont[j] < cont[j - 1]) {
                    std::swap(cont[j], cont[j - 1]);
                }
            }
        }
    }

    // calculate upper bound each time the outer loop passes, shrink each time
    template <typename C>
    void standard_2(C &cont) {
        for (size_t i = cont.size() - 1; i >= 1; --i) {
            for (size_t j = 1; j <= i; ++j) {
                if (cont[j] < cont[j - 1]) {
                    std::swap(cont[j], cont[j - 1]);
                }
            }
        }
    }

    template <typename C>
    void short_circuit(C &cont) {
        for (size_t i = cont.size() - 1; i >= 1; --i) {
            bool has_swapped = false;
            for (size_t j = 1; j <= i; ++j) {
                if (cont[j] < cont[j - 1]) {
                    std::swap(cont[j], cont[j - 1]);
                    has_swapped = true;
                }
            }

            if (!has_swapped)
                return;
        }
    }
} // namespace bubblesort::random_access_container