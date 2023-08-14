#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  
    int targetNo = rand() % 100 + 1;  
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!!!" << endl;

    while (true) {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        attempts++;

        if (guess < targetNo) {
            cout << "Too low!! Try again." << endl;
        } 
        else if (guess > targetNo) {
            cout << "Too high!! Try again." << endl;
        }
        else {
            cout << "Congratulations!! You've guessed the number " << targetNo
                      << " in " << attempts << " attempts." << endl;
            break;
        }
    }
    return 0;
}
