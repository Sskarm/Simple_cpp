#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int target = rand() % 100 + 1;
    int guess, tries = 0;
    cout << "Guess the number between 1 and 100: ";
    do {
        cin >> guess;
        ++tries;
        if (guess > target) {
            cout << "Too high. Try again: ";
        } else if (guess < target) {
            cout << "Too low. Try again: ";
        }
    } while (guess != target);
    cout << "Congratulations! You found the number in " << tries << " tries." << endl;
    return 0;
}
