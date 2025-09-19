#include "../include/Vector.hpp"
#include <iostream>
#include <stdexcept>
#include <memory>
#include <limits>
#include <sstream>
#include <algorithm>
#include "../include/Polygon.hpp"

constexpr std::size_t elements_per_line = 10;

template <typename T>
std::ostream &operator<<(std::ostream &os, Vector<T> const &vec) {
    os << "{ ";

    for (std::size_t i = 0; i < vec.size(); ++i) {
        os << vec.at(i);

        if (i + 1 != vec.size()) {
            os << ", ";
        }

        // line break
        if ((i + 1) % elements_per_line == 0 && i + 1 != vec.size()) {
            os << "\n  ";
        }
    }

    os << " }\n\n";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream                     &os,
                         Vector<std::shared_ptr<T>> const &vec) {
    os << "\n{ ";

    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i)) {
            os << *vec.at(i);
        } else {
            os << "nullptr";
        }

        if (i + 1 != vec.size()) {
            os << ", ";
        }
        // line break
        if ((i + 1) % elements_per_line == 0 && i + 1 != vec.size()) {
            os << "\n  ";
        }
    }

    os << " }\n\n";
    return os;
}




int main() {
    #ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    #endif

    std::cout << "Testing Vector<int> operations\n";
    {
        std::cout << "Using default constructor\n";
        Vector<int> vec;
        std::cout << "Empty vector:\n";
        std::cout << vec;

        for (int i = 1; i <= 5; ++i)
            vec.push_back(i * 10);

        std::cout << "After push_back:\n";
        std::cout << vec;

        std::cout << "After pop_back:\n";
        vec.pop_back();
        std::cout << vec;

        vec.resize(8);
        std::cout << "After resize(8):\n";
        std::cout << "(size: " << vec.size() << ", capacity: " << vec.capacity()
                  << ")\n";
        std::cout << vec;

        vec.reserve(20);
        std::cout << "After reserve(20): size=" << vec.size()
                  << ", capacity=" << vec.capacity() << "\n";
        std::cout << vec;

        vec[0] = 99;
        std::cout << "After vi[0]=99: ";
        std::cout << vec;

        try {
            std::cout << "vi.at(100): ";
            std::cout << vec.at(100) << "\n";
        } catch (std::out_of_range const &e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
    }

    std::cout << "\n\n";

    std::cout << "Testing Vector<Rectangle> operations\n";
    {
        Vector<Rectangle> vec;

        std::cout << "Empty vector: ";
        std::cout << vec;

        std::cout << "After push_back: Rectangle(10, 10)";
        vec.push_back(Rectangle(10, 10));
        std::cout << vec;
        
        std::cout << "After push_back: Rectangle(20, 10) ";
        vec.push_back(Rectangle(20,10));
        std::cout << vec;

        std::cout << "After pop_back:";
        vec.pop_back();
        std::cout << vec;

        std::cout << "After resize(8): (size=" << vec.size()
                  << ", capacity=" << vec.capacity() << ")\n";

        std::cout << vec;
    }

    // Test polymorphic vector
    std::cout << "Testing Vector<Polygon> - polymorphic\n";
    {
        Vector<std::shared_ptr<Polygon>> vec;


        
        std::cout << "Empty vector: ";
        std::cout << vec;

       
        std::cout << "After push_back: std::make_shared<Rectangle>(Rectangle(10, 10))\n";
        vec.push_back(std::make_shared<Rectangle>(Rectangle(10, 10)));
       
        std::cout << vec;
        std::cout << "\n";
        

        std::cout
            << "After push_back: std::make_shared<Triangle>(Triangle(10, 20)\n";
        vec.push_back(std::make_shared<Triangle>(Triangle(10, 10)));
        
        std::cout << vec;
        std::cout << "\n";

        vec.resize(8);
        std::cout << "After resize(8): ";
        std::cout << "(size: " << vec.size() << ", capacity: " << vec.capacity()
                  << ")\n";
        std::cout << vec;

        vec.reserve(20);
        std::cout << "After reserve(20): size=" << vec.size()
                  << ", capacity=" << vec.capacity() << "\n";
        std::cout << vec;

        vec.resize(20);
        std::cout
            << "After vec[12] = std::make_shared<Triangle>(Triangle(30,40))\n";
        vec[12] = std::make_shared<Triangle>(Triangle(30, 40));

        std::cout << vec;
    }

    {
        Vector<uint16_t> v(100);

        v.resize(100);

        std::cout << "Testing STL algorithm std::fill with custom vector\n";
        std::fill(std::begin(v), std::end(v),
                  std::numeric_limits<uint64_t>::max());

        std::cout << v;
    }


    #ifdef _DEBUG
    _CrtDumpMemoryLeaks();
    #endif
    return EXIT_SUCCESS;
}