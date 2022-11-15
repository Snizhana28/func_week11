// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


/*Task 3. Write the game "Bulls and cows". Program
"says" a four-digit number and the player must guess it.
After the user enters a number, the program reports,
how many digits of the number are guessed (bulls) and how many digits are guessed
and stands in the right place (cow). After guessing
numbers on the screen, it is necessary to display the number made
user attempts. The program must use recursion*/

#include <iostream>
#include <stdlib.h>
using namespace std;
void game(const int& secret_num) {
    int bulls = 0, cows = 0, variant = 0, go = 0;
    do {
        cout << "Enter number : ";
        cin >> variant;

        for (int i = 1000; i != 0; i /= 10) {
            if ((variant / i % 10) == (secret_num / i % 10))
                cows++;
        }
        for (int i = 1000; i != 0; i /= 10) {
            for (int j = 1000; j != 0; j /= 10)
            {
                if (i != j && (variant / i % 10) == (secret_num / j % 10))
                    bulls++;
            }
        }
        cout << " bulls: " << bulls << " cows: " << cows << endl;
        go++;
    } while (cows < 4);
    cout << "You have spent " << go << " try.\n";

}
int main()
{
    srand(time(NULL));
    cout << "Game : bulls and cows\n"
        "\nHow many digits is the number of guessed -- bulls."
        "\nHow many numbers are guessed and in the right place -- a cows.\n" << endl;
    bool arr[10];
    for (int i = 0; i != 10; i++)
        arr[i] = true;
    int n, secret_num = 0;
    for (int i = 1; i != 10000; i *= 10)
    {
        do {
            n = 1 + rand() % 9;
        } while (arr[n] == false);
        arr[n] = false;
        secret_num += i * n;
    }
    cout << secret_num << endl;
    game(secret_num);
    return 0;
}