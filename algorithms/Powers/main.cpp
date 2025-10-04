#include <iostream>
#include <cstdlib>


constexpr double power(int x, unsigned int n) {
    if (n == 0)
        return 1.0;

    return x * power(x, --n);
}

int main(void) {
    std::cout << "Using recursive function...\n";
    std::cout << "2 ^ 8 = " << power(2, 128) << "\n";
    std::cout << "5 ^ 4 = " << power(5, 4) << "\n";

	return EXIT_SUCCESS;
}

