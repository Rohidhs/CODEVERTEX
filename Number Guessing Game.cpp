#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void number_guessing_game() {

    srand(time(0));

    int random_number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    while (true) {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        attempts++;

        if (guess < random_number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > random_number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number " << random_number;
            cout << " in " << attempts << " attempts." << endl;
            break;
        }
    }
}

int main() {

    number_guessing_game();
    return 0;
}
