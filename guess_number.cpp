#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I've picked a number between 1 and 100. Try to guess it!\n";

    // Keep asking the player to guess until they get it right
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        // Check if the guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!\n";
            break;
        } else if (guess < secretNumber) {
            cout << "Too low. Try again!\n";
        } else {
            cout << "Too high. Try again!\n";
        }
    }

    return 0;
}
