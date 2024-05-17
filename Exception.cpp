#include <iostream>
#include <stdexcept>

unsigned long sigma(unsigned long n) {
    // Check precondition: n should be at least 1
    if (n < 1) {
        throw std::runtime_error("Precondition violation: n must be >= 1. "
                                 "File: " __FILE__ ", Line: " + std::to_string(__LINE__) + 
                                 ", Value of n: " + std::to_string(n));
    }

    // Compute the sum of integers from 1 to n
    unsigned long sum = 0;
    for (unsigned long i = 1; i <= n; ++i) {
        sum += i;
    }

    // Check post-condition: sum should be equal to n(n + 1) / 2
    if (sum != n * (n + 1) / 2) {
        throw std::runtime_error("Postcondition violation: computed sum does not match expected sum. "
                                 "File: " __FILE__ ", Line: " + std::to_string(__LINE__) + 
                                 ", Computed sum: " + std::to_string(sum));
    }

    return sum;
}

int main() {
    try {
        std::cout << "Sigma(5) = " << sigma(5) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Sigma(0) = " << sigma(0) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Injecting a fault to test post-condition
    try {
        // Temporary modification of the sigma function to create a fault
        auto faultySigma = [](unsigned long n) {
            if (n < 1) {
                throw std::runtime_error("Precondition violation: n must be >= 1. "
                                         "File: " __FILE__ ", Line: " + std::to_string(__LINE__) + 
                                         ", Value of n: " + std::to_string(n));
            }
            unsigned long sum = 0;
            for (unsigned long i = 1; i < n; ++i) { // Faulty loop condition (i < n)
                sum += i;
            }
            if (sum != n * (n + 1) / 2) {
                throw std::runtime_error("Postcondition violation: computed sum does not match expected sum. "
                                         "File: " __FILE__ ", Line: " + std::to_string(__LINE__) + 
                                         ", Computed sum: " + std::to_string(sum));
            }
            return sum;
        };

        std::cout << "Faulty Sigma(5) = " << faultySigma(5) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
