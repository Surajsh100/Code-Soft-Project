#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    int number=rand()%100+1;
    int guess;

    cout<<"Guess the number (between 1 and 100): ";
    while(1)
    {
        cin>>guess;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<< " Invalid input. Please enter a number :";
            continue;
        }
        cout << "Your guess :"<<guess<<endl;
        if(guess== number)
        {
            cout<<"Congratulations! You guessed the number! "<<endl;
            break;
        }
        else if(guess > number)
        {
            cout<<"too high! try again: ";
        }
        else
        {
            cout<<" Too low! Try again :";
        }
    }
    return 0;
}