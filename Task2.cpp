//SIMPLE CALCULATOR

#include <iostream>
using namespace std;

int main() {
    double firstNumber, secondNumber;
    char op;
    bool continueCalculations = true;

    while (continueCalculations) {
        cout << "Please enter the first number: ";
        cin >> firstNumber;

        cout << "Please enter the second number: ";
        cin >> secondNumber;

        cout << "Select an operator (+, -, *, /): ";
        cin >> op;

        switch (op) {
            case '+':
                cout << "The sum is: " << firstNumber + secondNumber << endl;
                break;
            case '-':
                cout << "The difference is: " << firstNumber - secondNumber << endl;
                break;
            case '*':
                cout << "The product is: " << firstNumber * secondNumber << endl;
                break;
            case '/':
                if (secondNumber != 0) {
                    cout << "The quotient is: " << firstNumber / secondNumber << endl;
                } else {
                    cout << "Error: Division by zero is not possible." << endl;
                }
                break;
            default:
                cout << "Error: Invalid operator selected." << endl;
                break;
        }

        char userChoice;
        cout << "Would you like to perform another calculation? (y/n): ";
        cin >> userChoice;
        if (userChoice == 'n' || userChoice == 'N') {
            continueCalculations = false;
        }
    }

    cout << "Thank you for using our calculator. Goodbye!" << endl;
    return 0;
}
