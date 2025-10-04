
#include "./Queue.hpp"
#include <iostream>

int main() {
    // Create a queue
    Queue<int> queue;

    try {
        // Report if empty, report size and print
        std::cout << "Queue is empty? " << (queue.empty() ? "Yes" : "No")
                  << "\n";
        std::cout << "Size is " << queue.size() << "\n";
        std::cout << queue << "\n";

        // Add some elements to the rear, report size and print
        std::cout << "\n" << "Enqueuing elements..." << "\n";
        queue.enqueue(2);
        queue.enqueue(4);
        queue.enqueue(3);
        queue.enqueue(7);
        std::cout << "Size is " << queue.size() << "\n";
        std::cout << queue << "\n";

        // Remove elements from the front, report size and print
        std::cout << "\n" << "Dequeuing elements..." << "\n";
        queue.dequeue();
        queue.dequeue();
        std::cout << "Size is " << queue.size() << "\n";
        std::cout << queue << "\n";

        // Peek at the front element and report size
        std::cout << "\n" << "Front element is " << queue.peek() << "\n";
        std::cout << "Size is " << queue.size() << "\n";
    } catch (std::invalid_argument &e) {
        std::cerr << "ERROR: " << e.what() << "\n";
    }

    // Add memory leak checking code
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    return EXIT_SUCCESS;
}