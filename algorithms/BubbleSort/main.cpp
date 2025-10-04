#define SORTED_DESC
#include "../sort_utils.hpp"
#include "./bubblesort.hpp"
#include <iostream>

int main(int argc, char **argv) {
    std::cout << array_tester << '\n';
    std::cout << vector_tester << '\n';
    std::cout << deque_tester << '\n';

    bubblesort::random_access_container::short_circuit(array_tester);

    bubblesort::bidirectional_iterators::short_circuit(std::begin(deque_tester),
                                                       std::end(deque_tester));

    std::cout << array_tester << '\n';
    std::cout << deque_tester << '\n';

    shuffle(array_tester, 3000);
    std::cout << array_tester << '\n';
}