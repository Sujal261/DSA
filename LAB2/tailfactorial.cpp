#include <iostream>

// Tail-recursive helper function
long long factorialTail(int n, long long accumulator = 1) {
    if (n <= 1)
        return accumulator;
    return factorialTail(n - 1, n * accumulator);
}

// Main function wrapper
long long factorial(int n) {
    return factorialTail(n);
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Factorial is not defined for negative numbers.\n";
    } else {
        std::cout << "Factorial(" << n << ") = " << factorial(n) << std::endl;
    }

    return 0;
}
