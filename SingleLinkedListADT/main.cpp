#include <iostream>

#include "SingleLinkedList.hpp"


int main(int, char **) {
    {
        std::cout << "Testing the default constructor with std::string:\n";
    SingleLinkedList<std::string> test_ll;
        
        std::cout << "\ttest_ll has size 0 when first constructed: " << std::boolalpha << (test_ll.size() == 0) << "\n";


        std::cout << "\tPushing \"Hello\" to test_ll using .push_front()\n";
        test_ll.push_front("Hello");   

        std::cout << "\tPushing \"World\" to test_ll using "
                     ".insert_after(std::begin(test_ll))\n";

        SingleLinkedList<std::string>::iterator it = 
            test_ll.insert_after(std::begin(test_ll), "world");


        std::cout << "\tNow with the iterator to the \"world\"'s node, use "
                     "insert_after to push a new string\n";

        test_ll.insert_after(it, "Hi");

        std::cout << "\tPrint all elements of the linked list using an iterator-based for loop:\n";

        for (auto it = std::begin(test_ll); it != std::end(test_ll); ++it) {
            std::cout << "\t\t- " << *it << '\n';
        }

        std::cout << "Remove the third element:\n";

        size_t it_count{};
        auto   iter = std::begin(test_ll);
        size_t index_to_delete{3};
        // get the index before index 3
        while (it_count != (index_to_delete - 1)) {
            ++iter;
            ++it_count;
        }

    
        std::cout << *iter << " " << it_count << "\n";

        test_ll.erase_after(iter);
      
        
        std::cout << test_ll.size();

        

    }

}