#include<iostream>
#include<cmath>
using namespace std;
void  add();
void sub();
void mul();
void div();
void mod();

void add()
{
    int a,b,c;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    c=a+b;
    cout<<"Addition of two numbers is: "<<c;
}
void sub()
{
    int a,b,c;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    c=a-b;
    cout<<"subtraction of two numbers is: "<<c;
}
void mul()
{
    int a,b,c;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    c=a*b;
    cout<<"Multiplication of two numbers is: "<<c;
}
void div()
{
    int a,b,c;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    c=a/b;
    cout<<"Division of two numbers is: "<<c;
}
void mod()
{
    int a,b,c;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    c=a%b;
    cout<<"Modulous of two numbers is: "<<c;
}
int main()
{
    while(true)
    {
        cout<<"!. Addition "<<endl;
        cout<<"2. Subtraction "<<endl;
        cout<<"3. Multiplication "<<endl;
        cout<<"4. Division "<<endl;
        cout<<"5. modulous "<<endl;
        cout<<"6. exit "<<endl;
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1: add();
                    break;
            case 2: sub();
                    break;
            case 3: mul();
                    break;
            case 4: div();
                    break;
            case 5: mod();
                    break;
            case 6: exit(0);
            default : cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}