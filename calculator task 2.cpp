#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Simple Calculator" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 == 0) {
        throw runtime_error("Error: Division by zero is not allowed!");
    }
    return num1 / num2;
}

int main() {
    int choice;
    double num1, num2;

    do {
        displayMenu();
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            try {
                switch (choice) {
                    case 1:
                        cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                        break;
                    case 2:
                        cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                        break;
                    case 3:
                        cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                        break;
                    case 4:
                        cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                        break;
                }
            } catch (const exception& e) {
                cerr << e.what() << endl;
            }
        } else if (choice != 5) {
            cout << "Invalid choice! Please choose a valid operation." << endl;
        }

        // Check for input failure
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (choice != 5);

    return 0;
}