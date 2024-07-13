#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the program." << endl;
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 2:
                result = subtract(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 3:
                result = multiply(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nSimple Calculator" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}