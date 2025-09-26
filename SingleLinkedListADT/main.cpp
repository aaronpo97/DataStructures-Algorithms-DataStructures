
#include "SingleLinkedList.hpp"
#include <iomanip>
#include <iostream>
#include <string>

void print_section(std::string const &title, std::ostream &os = std::cout) {
    os << "\n";
    os << std::setfill('=') << std::setw(40) << "" << "\n";
    os << title << "\n";
    os << std::setfill('=') << std::setw(40) << "=" << "\n";
    os << "\n";
}

template <typename T>
void print_list(SingleLinkedList<T> &ll, std::string const &label = "List") {
    std::cout << label << " (size=" << ll.size() << "):\n" << ll;
}

int main() {
    print_section("Default Constructor & Empty List");
    SingleLinkedList<std::string> ll;
    std::cout << "List is empty: " << std::boolalpha << ll.empty() << "\n";
    print_list(ll);

    print_section("push_front and insert_after");
    ll.push_front("Hello");
    print_list(ll, "After push_front('Hello')");

    auto it = ll.insert_after(ll.begin(), "World");
    print_list(ll, "After insert_after(begin, 'World')");

    ll.insert_after(it, "Hi");
    print_list(ll, "After insert_after(it, 'Hi')");

    print_section("Iterator-based Traversal");
    std::cout << "Elements: ";
    for (auto const &val : ll)
        std::cout << val << " ";
    std::cout << "\n";

    print_section("erase_after (remove 3rd element)");
    auto iter = ll.begin();
    ++iter;               // move to 2nd node
    ll.erase_after(iter); // remove 3rd node
    print_list(ll, "After erase_after(2nd node)");

    print_section("insert_middle at index 1");
    ll.insert_middle(1, "TEST");
    print_list(ll, "After insert_middle(1, 'TEST')");

    print_section("erase_middle at index 1");
    ll.erase_middle(1);
    print_list(ll, "After erase_middle(1)");

    print_section("pop_front");
    ll.pop_front();
    print_list(ll, "After pop_front");

    print_section("clear");
    ll.clear();
    print_list(ll, "After clear");

    print_section("All tests complete");
    return 0;
}