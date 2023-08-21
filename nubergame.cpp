#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    int op = 0;
    
    while (op == 0)
    {
        int level;
        cout << "Enter 1 For EASY LEVEL" << endl;
        cout << "Enter 2 For HARD LEVEL" << endl;
        cin >> level;


        if (level == 1)
        {
            cout << "Welcome to the Number Guessing Game!" << endl;
            srand(time(0));  
            int randomNumber = rand() % 100 + 1;  
        
            int guess;
            int at = 0;

            do
            {
                cout << "Guess a number between 1 and 100: ";
                cin >> guess;

                if (guess > 0)
                {
                    at++;

                    if (guess > randomNumber) {
                        cout << "Too high! Try again." << endl;
                    } 
                    else if (guess < randomNumber) {
                        cout << "Too low! Try again." << endl;
                    } 
                    else {
                        cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << at << " attempts." << endl;
                    }
                }
            } while (guess != randomNumber);
        }
        else if (level == 2)
        {
            cout << "Welcome to the Number Guessing Game!" << endl;
            srand(time(0));  
            int randomNumber = rand() % 200 + 1;  
        
            int guess;
            int at = 0;

            do
            {
                cout << "Guess a number between 1 and 200: ";
                cin >> guess;

                if (guess > 0)
                {
                    at++;

                    if (guess > randomNumber) {
                        cout << "Too high! Try again." << endl;
                    } 
                    else if (guess < randomNumber) {
                        cout << "Too low! Try again." << endl;
                    } 
                    else {
                        cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << at << " attempts." << endl;
                    }
                }
            } while (guess != randomNumber);
        }

        cout << "If you want to Play Again Press 0" << endl;
        cin >> op;
    }
    
    return 0;
}
