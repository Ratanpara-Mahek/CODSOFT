//NUMBER GUESSING GAME

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{

    cout << "\n\t\t\tWelcome to the NumberGuesser game!"
         << endl;
    cout << "You need to guess a number between 1 and 100. "
            "You'll have a limited number of attempts based on the "
            "difficulty level you choose. Good luck!"
         << endl;

    while (true) {
        cout << "\nChoose your difficulty level: \n";
        cout << "1 for easy!\t";
        cout << "2 for medium!\t";
        cout << "3 for hard!\t";
        cout << "0 to exit the game!\n" << endl;

        int levelChoice;
        cout << "Enter your choice: ";
        cin >> levelChoice;

        srand(time(0));
        int hiddenNumber = 1 + (rand() % 100);
        int userGuess;

        if (levelChoice == 1) {
            cout << "\nYou have 10 attempts to guess the "
                    "hidden number between 1 and 100.";
            int attemptsLeft = 10;
            for (int i = 1; i <= 10; i++) {
                cout << "\n\nMake your guess: ";
                cin >> userGuess;

                if (userGuess == hiddenNumber) {
                    cout << "Congratulations! You guessed correctly, "
                         << userGuess
                         << " is the hidden number!" << endl;
                    cout << "\t\t\t Thanks for playing!"
                         << endl;
                    cout << "Feel free to play again!\n\n"
                         << endl;
                    break;
                }
                else {
                    cout << "Sorry, " << userGuess
                         << " is not the hidden number.\n";
                    if (userGuess > hiddenNumber) {
                        cout << "Hint: The hidden number is "
                                "smaller than your guess."
                             << endl;
                    }
                    else {
                        cout << "Hint: The hidden number is "
                                "larger than your guess."
                             << endl;
                    }
                    attemptsLeft--;
                    cout << "You have " << attemptsLeft << " attempts left."
                         << endl;
                    if (attemptsLeft == 0) {
                        cout << "You've run out of attempts. The hidden number was "
                             << hiddenNumber
                             << ". Better luck next time!\n\n";
                        cout << "Try again to see if you can guess it!\n\n";
                    }
                }
            }
        }

        else if (levelChoice == 2) {
            cout << "\nYou have 7 attempts to guess the "
                    "hidden number between 1 and 100.";
            int attemptsLeft = 7;
            for (int i = 1; i <= 7; i++) {

                cout << "\n\nMake your guess: ";
                cin >> userGuess;

                if (userGuess == hiddenNumber) {
                    cout << "Congratulations! You guessed correctly, "
                         << userGuess
                         << " is the hidden number!" << endl;
                    cout << "\t\t\t Thanks for playing!"
                         << endl;
                    cout << "Feel free to play again!\n\n"
                         << endl;
                    break;
                }
                else {
                    cout << "Sorry, " << userGuess
                         << " is not the hidden number.\n";
                    if (userGuess > hiddenNumber) {
                        cout << "Hint: The hidden number is "
                                "smaller than your guess."
                             << endl;
                    }
                    else {
                        cout << "Hint: The hidden number is "
                                "larger than your guess."
                             << endl;
                    }
                    attemptsLeft--;
                    cout << "You have " << attemptsLeft << " attempts left."
                         << endl;
                    if (attemptsLeft == 0) {
                        cout << "You've run out of attempts. The hidden number was "
                             << hiddenNumber
                             << ". Better luck next time!\n\n";
                        cout << "Try again to see if you can guess it!\n\n";
                    }
                }
            }
        }
        else if (levelChoice == 3) {
            cout << "\nYou have 5 attempts to guess the "
                    "hidden number between 1 and 100.";
            int attemptsLeft = 5;
            for (int i = 1; i <= 5; i++) {

                cout << "\n\nMake your guess: ";
                cin >> userGuess;

                if (userGuess == hiddenNumber) {
                    cout << "Congratulations! You guessed correctly, "
                         << userGuess
                         << " is the hidden number!" << endl;
                    cout << "\t\t\t Thanks for playing!"
                         << endl;
                    cout << "Feel free to play again!\n\n"
                         << endl;
                    break;
                }
                else {
                    cout << "Sorry, " << userGuess
                         << " is not the hidden number.\n";
                    if (userGuess > hiddenNumber) {
                        cout << "Hint: The hidden number is "
                                "smaller than your guess."
                             << endl;
                    }
                    else {
                        cout << "Hint: The hidden number is "
                                "larger than your guess."
                             << endl;
                    }
                    attemptsLeft--;
                    cout << "You have " << attemptsLeft << " attempts left."
                         << endl;
                    if (attemptsLeft == 0) {
                        cout << "You've run out of attempts. The hidden number was "
                             << hiddenNumber
                             << ". Better luck next time!\n\n";
                        cout << "Try again to see if you can guess it!\n\n";
                    }
                }
            }
        }
        else if (levelChoice == 0) {
            exit(0);
        }
        else {
            cout << "Invalid choice, please enter a valid option (0,1,2,3)"
                 << endl;
        }
    }
    return 0;
}
