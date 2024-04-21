#include <iostream>

int main() {
    const int ARRAY_SIZE = 10;
    const int LAST_ARRAY_ELEM_INDEX = 9;
    
    char* p_aChars = new char[ARRAY_SIZE];
    int* p_aIntegers = new int[ARRAY_SIZE];

    // Disable brute force initialization
    #if 0
    p_aChars[0] = 'A'; 
    p_aChars[1] = 'B'; 
    p_aChars[2] = 'C'; 
    p_aChars[3] = 'D'; 
    p_aChars[4] = 'E'; 
    p_aChars[5] = 'F'; 
    p_aChars[6] = 'G'; 
    p_aChars[7] = 'H'; 
    p_aChars[8] = 'I'; 
    p_aChars[9] = 'J'; 

    p_aIntegers[0] = 100; 
    p_aIntegers[1] = 101; 
    p_aIntegers[2] = 102; 
    p_aIntegers[3] = 103; 
    p_aIntegers[4] = 104; 
    p_aIntegers[5] = 105; 
    p_aIntegers[6] = 106; 
    p_aIntegers[7] = 107; 
    p_aIntegers[8] = 108; 
    p_aIntegers[9] = 109; 
    #endif

    // Initialize character array with a while loop
    char* p_c = p_aChars;
    char c = 'A';
    while (p_c <= &p_aChars[LAST_ARRAY_ELEM_INDEX]) {
        *p_c = c;
        p_c++;
        c++;
    }

    // Initialize integer array with a while loop
    int* p_i = p_aIntegers;
    int i = 100;
    while (p_i <= &p_aIntegers[LAST_ARRAY_ELEM_INDEX]) {
        *p_i = i;
        p_i++;
        i++;
    }

    // Reset pointers to start of the arrays
    p_c = p_aChars;
    p_i = p_aIntegers;

    // Output character array
    while (p_c <= &p_aChars[LAST_ARRAY_ELEM_INDEX]) {
        std::cout << "p_c: " << static_cast<void*>(p_c) << ":  *p_c: " << *p_c << std::endl;
        p_c++;
    }

    // Output integer array
    while (p_i <= &p_aIntegers[LAST_ARRAY_ELEM_INDEX]) {
        std::cout << "p_i: " << static_cast<void*>(p_i) << ":  *p_i: " << *p_i << std::endl;
        p_i++;
    }

    delete[] p_aChars;
    delete[] p_aIntegers;
    return 0;
}
