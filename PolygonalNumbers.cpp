#include <iostream>
#include <fstream>
#include <string>

// Class definition for Central Polygonal Numbers
class CentralPolygonalNumbers {
private:
    int* mp_iNumbers; // Pointer to the array of integers
    int m_nMax;       // Maximum number of cuts

public:
    // Default constructor
    CentralPolygonalNumbers() : m_nMax(0) {
        mp_iNumbers = new int[1];
        mp_iNumbers[0] = 1;
    }

    // Overloaded constructor
    CentralPolygonalNumbers(int nMax) : m_nMax(nMax) {
        mp_iNumbers = new int[nMax + 1];
        for (int n = 0; n <= m_nMax; ++n) {
            mp_iNumbers[n] = (n * (n + 1)) / 2 + 1;
        }
    }

    // Destructor
    ~CentralPolygonalNumbers() {
        delete[] mp_iNumbers;
        std::cout << "Memory deallocated for CentralPolygonalNumbers." << std::endl;
    }

    // Function to display the sequence
    void display() const {
        for (int n = 0; n <= m_nMax; ++n) {
            std::cout << mp_iNumbers[n] << " ";
        }
        std::cout << std::endl;
    }

    // Function to save the sequence to a file
    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (int n = 0; n <= m_nMax; ++n) {
                outFile << mp_iNumbers[n] << std::endl;
            }
            outFile.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
};

// Main function to test the class
int main() {
    // Create an instance of the class with the sequence up to n = 10
    CentralPolygonalNumbers sequence(10);

    // Display the sequence
    sequence.display();

    // Save the sequence to a file
    sequence.saveToFile("CentralPolygonalNumbers.txt");

    return 0;
}
