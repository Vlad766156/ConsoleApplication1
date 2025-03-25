#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void game();

int main()
{
    string pay;
    string password;
    string pay_or_not;
    string oportunity;
    string play_again;

    cout << "============================" << endl;
    cout << "   Welcome to the VIP Club!  " << endl;
    cout << "============================" << endl;
    cout << "\nDid you pay to enter this VIP video game club?" << endl;
    cin >> pay;

    if (pay == "yes") {
        cout << "\nEnter the password: ";
        cin >> password;
    }
    else {
        cout << "\nYou didn't pay. Access is only for those who pay $10.\n";
        return 0;
    }

    if (password == "166365") {
        cout << "\nAccess granted! Let's play!\n" << endl;
        do {
            game();
            cout << "\nDo you want to play again? (yes/no): ";
            cin >> play_again;
        } while (play_again == "yes");
    }
    else {
        cout << "\nAre you trying to deceive me? If you want to play, pay $10!\n";
        cout << "Yes or no?" << endl;
        cin >> pay_or_not;

        if (pay_or_not == "yes") {
            cout << "\nYou have only $9." << endl;
            cout << "Try your luck? (yes/no)" << endl;
            cin >> oportunity;
        }
        else {
            cout << "\nYou are too poor! \n";
            return 0;
        }

        if (oportunity == "yes") {
            cout << "\nPress ENTER to receive an answer... ";
            cin.ignore();
            cin.get();

            unsigned long t = reinterpret_cast<unsigned long>(&t) + static_cast<unsigned long>(std::time(0));

            if (t % 2 == 0) {
                cout << "\nNo\n";
                return 0;
            }
            else {
                cout << "\nYes\n";
            }

            do {
                game();
                cout << "\nDo you want to play again? (yes/no): ";
                cin >> play_again;
            } while (play_again == "yes");
        }
    }

    return 0;
}

void game() {
    cout << "\n============================" << endl;
    cout << "     Let's play a game!     " << endl;
    cout << "============================" << endl;
    cout << "\nI am thinking of a number. Try to guess it!" << endl;
    int user_guess = 0;
    int attempts = 0;
    int secret_number = 0;
    string attempts_for_if;

    cout << "\nHow many attempts would you like? (5, 10, or 20): ";
    cin >> attempts_for_if;

    if (attempts_for_if == "5") {
        attempts = 5;
        cout << "\n=====================================" << endl;
        cout << "  You need to guess a number between 1 and 50 with 5 attempts!" << endl;
        cout << "=====================================" << endl;
        srand(static_cast<unsigned int>(time(0)));
        secret_number = rand() % 50 + 1;
    }
    else if (attempts_for_if == "10") {
        attempts = 10;
        cout << "\n=====================================" << endl;
        cout << "  You need to guess a number between 1 and 300 with 10 attempts!" << endl;
        cout << "=====================================" << endl;
        srand(static_cast<unsigned int>(time(0)));
        secret_number = rand() % 300 + 1;
    }
    else if (attempts_for_if == "20") {
        attempts = 20;
        cout << "\n=====================================" << endl;
        cout << "  You need to guess a number between 1 and 1000 with 20 attempts!" << endl;
        cout << "=====================================" << endl;
        srand(static_cast<unsigned int>(time(0)));
        secret_number = rand() % 1000 + 1;
    }
    else {
        cout << "\nInvalid number of attempts. Defaulting to 5.\n";
        attempts = 5;
        srand(static_cast<unsigned int>(time(0)));
        secret_number = rand() % 50 + 1;
    }

    
    while (attempts > 0) {
        cout << "\nEnter your guess: ";
        cin >> user_guess;

        attempts--;

        if (user_guess < secret_number) {
            cout << "Too low! Try again." << endl;
        }
        else if (user_guess > secret_number) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Congratulations! You've guessed the number!" << endl;
            break;
        }

        if (attempts == 0) {
            cout << "\n=====================================" << endl;
            cout << "  You lose! The secret number was " << secret_number << "." << endl;
            cout << "=====================================" << endl;
            cout << "\nDo you want to play again? (yes/no): ";
            string play_again;
            cin >> play_again;
            if (play_again == "yes") {
                game();
            }
        }
    }
}