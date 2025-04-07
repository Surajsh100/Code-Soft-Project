#include<iostream>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
char token= 'x';
bool isTie = false;
string n1=" ";
string n2=" ";

void functionOne()
{
 
    cout<<"       |       |   \n";
    cout<<" "<<space[0][0]<<"     | "<<space[0][1]<<"     | "<<space[0][2]<<"   \n";
    cout<<"       |       |   \n";
    cout<<"---------------------------\n";
    cout<<"       |       |   \n";
    cout<<" "<<space[1][0]<<"     | "<<space[1][1]<<"     | "<<space[1][2]<<"   \n";
    cout<<"       |       |   \n";
    cout<<"---------------------------\n";
    cout<<"       |       |   \n";
    cout<<" "<<space[2][0]<<"     | "<<space[2][1]<<"     | "<<space[2][2]<<"   \n";
    cout<<"       |       |   \n";
}
void functionTwo()
{
    int digit;
    while(true)
    {
        cout<< (token == 'x'? n1 : n2) << "Please enter: ";
        cin >> digit;
    
        if(digit < 1 || digit > 9)
        {
            cout<<" Invalid input! Try again.\n";
            continue;
        }
        row=(digit - 1)/ 3;
        column = (digit - 1) % 3;

        if(space[row][column] == 'x' || space[row][column] == '0')
        {
            cout<<"That spot is already taken! try again.\n";
            continue;
        }
        space[row][column] = token;
        token = (token == 'x' ) ? '0': 'x';
        break;
    }
    functionOne();
   /*if(digit ==1)
    {
        row=0;
        column=0;
    }
    if(digit ==2)
    {
        row=0;
        column=1;
    }
    if(digit ==3)
    {
        row=0;
        column=2;
    }
    if(digit ==4)
    {
        row=1;
        column=0;
    }
    if(digit ==5)
    {
        row=1;
        column=1;
    }
    if(digit ==6)
    {
        row=1;
        column=2;
    }
    if(digit ==7)
    {
        row=2;
        column=0;
    }
    if(digit ==8)
    {
        row=2;
        column=1;
    }
    if(digit ==9)
    {
        row=2;
        column=2;
    }
    else
    {
        cout<<" Invliad !!!"<<endl;
    }
    if(token=='x' &&space[row][column] != 'x' && space[row][column] !='0')
    {
        space[row][column]='x';
        token='0';
    }
    else  if(token=='0' &&space[row][column] != 'x' && space[row][column] !='0')
    {
        space[row][column]='0';
        token='x';
    }
    else
    {
        cout<<"There is no empty space!"<<endl;
        functionTwo();
    }
    functionOne();*/
}
bool functionThree()
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2]) return true;
        if(space[0][i] == space[1][i] && space[0][i] == space[2][i]) return true;
    }
    if(space[0][0] == space[1][1] && space[1][1] == space[2][2])
    return true;
    if(space[0][2] == space[1][1] && space[1][1] == space[2][0])
    return true; 

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    isTie = true;
    return false;
}
int main()
{
    cout<<"Enter the name of the first player : \n";
    cin.ignore();
    getline(cin,n1);
    cout<<"Enter the name of the second player : \n";
    getline(cin,n2);

    while(!functionThree())
    {
        functionOne();
        functionTwo();

    }
   if(!isTie)
   {
    cout<<((token == 'x' ) ? n2 : n1)<<"Wins !!!"<<endl;
   }
   else{
    cout<<" It is a Draw !\n";
   }
   return 0;
}