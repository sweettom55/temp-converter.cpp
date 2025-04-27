/*
 * TempConverter.cpp
 *
 *  Date: 04/02/2025
 *  Author: Thomas Sweet
 *  Description: Reads city and temperature in Fahrenheit from a file,
 *               converts to Celsius, and writes to a new file.
 */

#include <iostream>
#include <fstream> // Needed for file operations
#include <string>  // Needed for string handling

using namespace std;

int main() {
    // Declare input file stream for reading Fahrenheit temperatures
    ifstream inputFile("FahrenheitTemperature.txt");

    // Check if the input file opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open FahrenheitTemperature.txt" << endl;
        return 1;
    }

    // Declare output file stream for writing Celsius temperatures
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if the output file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Could not create CelsiusTemperature.txt" << endl;
        return 1;
    }

    string city;     // To store the city name
    int fahrenheit;  // To store the Fahrenheit temperature

    // Read each city and temperature from the file
    while (inputFile >> city >> fahrenheit) {
        // Convert Fahrenheit to Celsius using the formula
        double celsius = (fahrenheit - 32) * 5.0 / 9.0;

        // Write the result to the output file
        outputFile << city << " " << celsius << endl;

        // Optional: Display result to console as well (for testing)
        cout << city << " " << celsius << "°C" << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    cout << "Temperature conversion complete. Results saved to CelsiusTemperature.txt" << endl;

    return 0;
}

