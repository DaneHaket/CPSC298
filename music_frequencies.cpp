#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the frequency of a note
double calculateFrequency(int k, int nu) {
    double fR = 16.35; // Reference frequency in Hz
    return fR * pow(2, nu) * pow(pow(2, 1.0/12), k);
}

// Function to calculate the wavelength of a note
double calculateWavelength(double frequency) {
    double speedOfSound = 34500; // Speed of sound in cm/s
    return speedOfSound / frequency;
}

int main() {
    // Display the reference frequency and the speed of sound
    cout << "Reference Frequency, fR: 16.35 Hz" << endl;
    cout << "Speed of Sound in Air: 34500 cm/s" << endl << endl;

    // Array of notes to calculate frequency and wavelength for
    // Each note is represented by a pair {k, nu}
    int notes[][2] = {
        {1, 0}, // C#0
        {2, 0}, // D0
        {2, 3}, // D3
        {0, 4}, // C4
        {3, 7}, // D#7
        {0, 8}  // C8
    };
    // Names of the notes for display
    string noteNames[] = {"C#0", "D0", "D3", "C4", "D#7", "C8"};

    for (int i = 0; i < 6; i++) {
        // Calculate the frequency and wavelength for each note
        double frequency = calculateFrequency(notes[i][0], notes[i][1]);
        double wavelength = calculateWavelength(frequency);

        // Display the results
        cout << "Note: " << noteNames[i]
             << ", Octave: " << notes[i][1]
             << ", Half-tone offset: " << notes[i][0]
             << ", Frequency: " << frequency << " Hz"
             << ", Wavelength: " << wavelength << " cm" << endl;
    }

    return 0;
}
