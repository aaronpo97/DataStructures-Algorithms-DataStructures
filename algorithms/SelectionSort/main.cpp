#define UNSORTED
#include <array>
#include "../sort_utils.hpp"



template <typename T>
void selection_sort(T &container)
{
    // starting from the first element
    for (size_t i=0; i < container.size(); ++i)
    {
        auto idx = i;
        for (size_t j = i + 1; j < container.size(); ++j){
            // compare all elements after i, check if they are smaller. If so, swap
            if (container[i] > container[j]) {
                std::swap(container[i], container[j]);
            }
        }
    }

}

int main() {

    selection_sort(array_tester);

    std::cout << array_tester << '\n';

}