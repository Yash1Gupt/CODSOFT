#include <bits/stdc++.h>
using namespace std;

int main() {
    char op;
    double num1, num2;

    cout << "--- C++ Calculator ---" << endl;
    cout << "Enter an operator (+, -, *, /) or 'x' to exit." << endl << endl;

    while (true) {
        cout << "Enter operator: ";
        cin >> op;
        if (op == 'x' || op == 'X') {
            break; 
        }

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Error! Invalid operator. Please use +, -, *, or /." << endl;
            continue; 
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (op) {
            case '+':
                cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;

            case '-':
                cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;

            case '*':
                cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;

            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                } else {
                    cout << "Error! Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Error! Invalid operator." << endl;
                break;
        }
        cout << "----------------------" << endl;
    }
    return 0;
}