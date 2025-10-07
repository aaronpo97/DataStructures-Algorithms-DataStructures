#define UNSORTED

#include "../sort_utils.hpp"

namespace insertion_sort::random_access_container {
    template<typename C> 
    void standard(C &container) {
        for (size_t i = 1; i < container.size(); ++i ) {
            size_t j = i;

            while (j > 0 && container[j] < container[j - 1]) {
                std::swap(container[j], container[j - 1]);
              
                --j;
            }

              std::cout << container << '\n';
        }
    }
}

int main(int argc, char **argv) {
    std::cout << array_tester << '\n';

    insertion_sort::random_access_container::standard(array_tester);
    
    std::cout << array_tester << '\n';
}