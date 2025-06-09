#include <iostream>

// Tail-recursive helper function
int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacciTail(n - 1, b, a + b);
}

// Main function wrapper
int fibonacci(int n) {
    return fibonacciTail(n);
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}
