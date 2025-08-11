#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessTheNumber() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int attempts = 0;

    cout << "Welcome to the number guessing game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    while (true) {
        int userGuess;
        cout << "Take a guess: ";
        cin >> userGuess;
        attempts++;

        // Check for valid input
        if (cin.fail()) {
            cout << "Invalid input! Please enter a whole number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            attempts--; // Don't count invalid input as an attempt
            continue;
        }

        // Check if the guess is correct
        if (userGuess == numberToGuess) {
            cout << "Congratulations! You found the number in " << attempts << " attempts." << endl;
            break;
        } else if (userGuess < numberToGuess) {
            cout << "Your guess is too low. Try again!" << endl;
        } else {
            cout << "Your guess is too high. Try again!" << endl;
        }
    }
}

int main() {
    guessTheNumber();
    return 0;
}