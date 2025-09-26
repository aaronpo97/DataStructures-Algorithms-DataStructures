#include "../include/Stack.hpp"
#include <iostream>

// a sample struct to test using user-defined types with the stack
// implementation
struct Vec3 {
    float x, y, z;

    friend std::ostream &operator<<(std::ostream &os, Vec3 const &v) {
        os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
        return os;
    }
};

int main() {
    std::cout << "Testing Stack<int> with initial capacity 2...\n";
    Stack<int> s(2);
    std::cout << "Is empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    s.push(10);
    std::cout << "Pushed 10. Stack now:\n" << s;
    s.push(20);
    std::cout << "Pushed 20. Stack now:\n" << s;
    std::cout << "Pop: " << s.pop() << "\n";
    std::cout << "Stack after pop:\n" << s;
    std::cout << "Pop: " << s.pop() << "\n";
    std::cout << "Stack after pop:\n" << s;
    std::cout << "Is empty after pops? " << (s.isEmpty() ? "Yes" : "No")
              << "\n";

    std::cout << "\nTesting capacity extension...\n";
    Stack<int> s2(1);
    s2.push(1);
    std::cout << "Pushed 1. Stack now:\n" << s2;
    s2.push(2); // should trigger extendCapacity
    std::cout << "Pushed 2. Stack now:\n" << s2;
    s2.push(3);
    std::cout << "Pushed 3. Stack now:\n" << s2;
    std::cout << "Size after pushes: " << s2.size()
              << ", Capacity: " << s2.capacity() << "\n";
    std::cout << "Pop: " << s2.pop() << "\n";
    std::cout << "Stack after pop:\n" << s2;
    std::cout << "Pop: " << s2.pop() << "\n";
    std::cout << "Stack after pop:\n" << s2;
    std::cout << "Pop: " << s2.pop() << "\n";
    std::cout << "Stack after pop:\n" << s2;
    std::cout << "Is empty after pops? " << (s2.isEmpty() ? "Yes" : "No")
              << "\n";

    std::cout << "\nTesting pop on empty stack (should show error)...\n";
    Stack<int> s3(1);
    try {
        s3.pop();
    } catch (std::out_of_range const &e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\nAll Stack tests completed.\n";
    std::cout << "\nTesting Stack<Vec3>...\n";
    Stack<Vec3> vstack(2);
    vstack.push({1.0f, 2.0f, 3.0f});
    std::cout << "Pushed Vec3{1,2,3}. Stack now:\n" << vstack;
    vstack.push({4.0f, 5.0f, 6.0f});
    std::cout << "Pushed Vec3{4,5,6}. Stack now:\n" << vstack;
    std::cout << "Size: " << vstack.size()
              << ", Capacity: " << vstack.capacity() << "\n";
    std::cout << "Pop: " << vstack.pop() << "\n";
    std::cout << "Stack after pop:\n" << vstack;
    std::cout << "Pop: " << vstack.pop() << "\n";
    std::cout << "Stack after pop:\n" << vstack;
    std::cout << "Is empty after pops? " << (vstack.isEmpty() ? "Yes" : "No")
              << "\n";
}
