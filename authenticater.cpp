#include <iostream>
#include <string>

// Part I: Entering and Displaying the Codes
const char kAuthenticatorCode[3] = {'E', 'C', 'A'};

int main() {
    char messageCode[3];
    std::string authenticatorCode(kAuthenticatorCode, kAuthenticatorCode + 3);
    std::string enteredCode;

    // Prompt the user to enter the three letter message code
    std::cout << "Enter the three-letter message code, one letter at a time:\n";
    for (int i = 0; i < 3; ++i) {
        std::cin >> messageCode[i];
        enteredCode += messageCode[i]; // Concatenate characters into a string
    }

    // Display the message and Authenticator codes
    std::cout << "Message Code: " << enteredCode << "\n";
    std::cout << "Authenticator Code: " << authenticatorCode << "\n";

    // Part II: Character-by-Character Comparison
    bool isAuthentic = true;
    for (int i = 0; i < 3; ++i) {
        if (messageCode[i] != kAuthenticatorCode[i]) {
            isAuthentic = false;
            break;
        }
    }
    std::cout << (isAuthentic ? "Message is authentic." : "Message is invalid.") << "\n";

    // Part III: String Comparison
    std::cout << "Concurrence: " << (enteredCode == authenticatorCode ? "message is authentic." : "message is invalid.") << "\n";

    // Part IV: Characterizing the Received Message Code
    int checksum = (static_cast<int>(messageCode[0]) + static_cast<int>(messageCode[1]) + static_cast<int>(messageCode[2])) % 7;
    const int kValidCodeChecksum = 5;
    std::cout << "Checksum: " << (checksum == kValidCodeChecksum ? "Valid" : "Invalid") << "\n";

    // Display the ASCII values of each character and their sum
    int sumASCII = 0;
    std::cout << "ASCII values: ";
    for (int i = 0; i < 3; ++i) {
        int asciiValue = static_cast<int>(messageCode[i]);
        std::cout << asciiValue << " ";
        sumASCII += asciiValue;
    }
    std::cout << "\nSum of ASCII values: " << sumASCII << "\n";

    return 0;
}
