#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    int number = rand() % 100 + 1;  // random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Guess the number (between 1 and 100):" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < number)
            cout << "Too low! Try again.\n";
        else if (guess > number)
            cout << "Too high! Try again.\n";
        else
            cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts.\n";

    } while (guess != number);

    return 0;
}
