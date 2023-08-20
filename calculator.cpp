#include <iostream>
using namespace std;

int main() {
    double n1, n2;
    char op;

    cout << "Enter the first number: ";
    cin >> n1;

    cout << "Enter the second number: ";
    cin >> n2;

    cout << "Select an operation: \n(1) for Addition \n(2) for Subtraction \n(3) for Multiplication \n(4) for Division "<<endl;
    cout << "Enter your choice: ";
    cin >> op;

    switch (op) {
        case '1':
            cout << "Result: " << n1 + n2 << endl;
            break;
        case '2':
            cout << "Result: " << n1 - n2 << endl;
            break;
        case '3':
            cout << "Result: " << n1 * n2 << endl;
            break;
        case '4':
            if (n2 != 0) {
                cout << "Result: " << n1 / n2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
            break;
    }

    return 0;
}
