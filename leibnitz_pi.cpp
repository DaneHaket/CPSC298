#include <iostream>
#include <iomanip>
#include <cmath>  // Include cmath for power function

int main() {
    // Declare variables
    long long n;  // Upper bound for the summation, to be input by the user
    double piOver4 = 0.0;  // This will hold the sum of the series which approximates π/4

    // Input
    std::cout << "Enter the upper bound for the summation (n): ";
    std::cin >> n;  // Read the upper bound from the user

    // Calculation using Leibnitz formula
    for (long long k = 0; k <= n; ++k) {
        piOver4 += pow(-1.0, k) / (2 * k + 1);  // Each term of the series is added to piOver4
    }

    double pi = 4 * piOver4;  // Multiply the summation result by 4 to get π

    // Output formatting
    std::cout << std::fixed << std::setprecision(15);  // Set the precision for floating point output
    std::cout << "PI (approx): " << pi << "; n: " << std::setw(7) << n << std::endl;  // Output the approximated π and n
    std::cout << "PI (actual): 3.141592653589793" << std::endl;  // Output the known value of π for comparison

    return 0;  // Exit the program
}
