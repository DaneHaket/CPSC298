#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const long long max_n = 1048576;  // The maximum value for n, 2^20

    // Print the header for the output
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "n\t\tPi Approximation\tError\n";

    for (long long n = 2; n <= max_n; n *= 2) {  // Start from n=2, double n each iteration
        double piOver4 = 0.0;

        // Calculate pi using the Leibnitz formula
        for (long long k = 0; k <= n; ++k) {
            piOver4 += pow(-1.0, k) / (2 * k + 1);  // Accumulate the sum for pi/4
        }

        double pi = 4 * piOver4;  // Calculate pi

        // Calculate and print the error
        double error = std::abs(pi - 3.141592653589793);

        std::cout << std::setw(7) << n << "\t\t" << pi << "\t\t" << error << std::endl;
    }

    return 0;
}
