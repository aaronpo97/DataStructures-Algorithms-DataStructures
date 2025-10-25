#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <format>

namespace recusion {

    /**
     * Computes x raised to the power of n (x^n)
     *
     * Example stack calls for power(2, 4):
     * power(2, 4)
     * -> 2 * power(2, 3)
     * -> 2 * (2 * power(2, 2))
     * -> 2 * (2 * (2 * power(2, 1)))
     * -> 2 * (2 * (2 * (2 * power(2, 0))))
     * -> 2 * (2 * (2 * (2 * 1)))
     */
    constexpr double power(int x, unsigned int n) {
        if (n == 0)
            return 1.0;

        return x * power(x, --n);
    }

    /**
     * Computes the factorial of a number n (n!)
     *
     * Example stack calls for factorial(4):
     * factorial(4)
     * -> factorial(3)
     * -> factorial(2)
     * -> factorial(1)
     * -> factorial(0)
     * -> returns 1
     * <- returns 1 * 1 = 1
     * <- returns 2 * 1 = 2
     * <- returns 3 * 2 = 6
     * <- returns 4 * 6 = 24
     * <- returns 24
     */

    template <typename NumType>
        requires std::is_integral<NumType>::value
    constexpr long long factorial(NumType const n) {
        if (n == 0)
            return 1;

        return n * factorial(n - 1);
    }

    /**
     * Computes the n-th Fibonacci number
     *
     * Example stack calls for fibonacci(5):
     * fibonacci(5)
     * -> fibonacci(4) + fibonacci(3)
     * -> (fibonacci(3) + fibonacci(2)) + (fibonacci(2) + fibonacci(1))
     * -> ((fibonacci(2) + fibonacci(1)) + (fibonacci(1) + fibonacci(0))) +
     * ((fibonacci(1) + fibonacci(0)) + 1)
     * -> (((fibonacci(1) + fibonacci(0)) + 1) + (1 + 0)) + ((1 + 0) + 1)
     * -> (((1 + 0) + 1) + (1 + 0)) + ((1 + 0) + 1)
     * -> ((1 + 1) + 1) + (1 + 1)
     * -> (2 + 1) + 2
     * -> 3 + 2
     * -> 5
     */
    template <typename NumType>
        requires std::is_integral<NumType>::value
    constexpr long long fibonacci(NumType n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
} // namespace recusion

namespace iteration {
    constexpr int64_t power(int64_t x, int64_t n) {
        int acc = x;
        for (size_t i = 1; i <= n; ++i)
            acc *= x;

        return acc;
    }

    // 5! = 5 * 4 * 3 * 2 * 1
    constexpr int64_t factorial(int64_t x) {
        int64_t acc = x;
        for (int64_t i = x - 1; i >= 1LL; --i) {
            acc *= i;
        }

        return acc;
    }
} // namespace iteration

int main() {
    constexpr int64_t n = 19;

    std::cout << std::format("{:>5}! (recursion) = {:<30}\n", n,
                             recusion::factorial(n));

    std::cout << std::format("{:>5}! (iteration) = {:<30}\n", n,
                             iteration::factorial(n));

    constexpr int64_t a = 2;
    constexpr int64_t b = 12;
    std::cout << std::format("{:>5} ^ {:<5} = {:<30}", a, b, recusion::power(a, b));
    return EXIT_SUCCESS;
}
