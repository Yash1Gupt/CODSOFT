#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    int guess;
    int tries=0;

    srand(time(NULL));
    num = (rand() % 100) + 1;

    cout << "*****NUMBER GUESSING GAME****"<< endl;


    do{
        cout << "Enter Guess between (1-100):" << endl;
        cin >> guess;
        tries++;

        if(guess>num) {
            cout << "TOO HIGH " << endl;
        }
        else if(guess<num) {
            cout <<"TOO LOW "<< endl;
        }
        else {
            cout << "CORRECT! # of  tries: " << tries<< endl;
        }

    }while(guess!=num);
    return 0;
}