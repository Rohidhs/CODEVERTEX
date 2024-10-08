#include <iostream>

using namespace std;

void calculator() {
    double num1, num2;
    char operation;
    double result;

    cout << "Simple Calculator" << endl;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;


    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please use one of +, -, *, /." << endl;
    }
}

int main() {

    calculator();
    return 0;
}
