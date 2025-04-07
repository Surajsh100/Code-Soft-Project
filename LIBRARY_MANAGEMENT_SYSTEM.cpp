#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class library
{
    public:
    void addbook();
    void displaybook();
    void adduser();
    void borrowuser();
    void returnbook();
    void deletebook();
    void searchbook();
};
void library :: addbook()
{
    string bookname,author,category;
    int year;
    cout<<"Enter book name: ";
    cin.ignore();
    getline(cin,bookname);
    cout<<" Enter author name: ";
    getline(cin,author);
    cout<<"Enter book category: ";
    getline(cin,category);
    cout<<"Enter book year: "; 
    cin>>year;
    ofstream file("library.txt",ios::app);
    if(file.is_open())
    {
        file<<bookname<<" |"<<author<<" |"<<category<<" |"<<year<<" ||"<<endl;
        file.close();
        cout<<" Book added successfully\n";
    }
    else
    {
        cout<<"Unable to open file";
    }    
}
void library :: displaybook()
{
    string line;
    ifstream file("library.txt");
    if(!file.is_open())
    {
        cout<<"Unable to open file!\n";
        return ;
    }
    cout<<"\n list of books:\n";
    while(getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();
}
void library :: adduser()
{
    string name,address,phone;
    cout<<" Enter user name: ";
    cin.ignore();
    getline(cin,name);

    cout<<" Enter user address: ";
    getline(cin,address);

    cout<<" Enter user phone: ";
    getline(cin,phone);

    ofstream file("users.txt",ios::app);
    if(file.is_open())
    {
        file<<name<<" | "<<address<<"| "<<phone<<" |"<<endl;
        file.close();
        cout<<"user add successfully!\n";
    }
    else{
        cout<<"Unable to open file";
    }
}
void library :: borrowuser()
{
    string name,bookname,author,category,issue;
    int year;

    cout<<" Enter user name: ";
    cin.ignore();
    getline(cin,name);

    cout<<" Enter book name: "; 
    getline(cin,bookname);

    cout<<" Enter book author: ";
    getline(cin,author);

    cout<<" Enter book category: ";
    getline(cin,category);

    cout<<" Enter book year: ";
    cin>>year;

    cout<<" Enter issue date: ";
    cin.ignore();
    getline(cin,issue);

    ofstream file("borrowedbooks.txt",ios::app);
    if(file.is_open())
    {
        file<<name<<" |"<<bookname<<"| "<<author<<"| "<<category<<" |"<<year<<" |"<<issue<<" ||"<<endl;
        file.close();
        cout<<"book borrowed successfully!\n";
    }
    else{
        cout<<"Unable to open file";
    }
}
void library :: returnbook()
{
    string name,bookname,author,category,returndate;
    cout<<" Enter user name: ";
    cin.ignore();
    getline(cin,name);
    
    cout<<" Enter book name: ";
    getline(cin,bookname);

    cout<<" Enter return date: ";
    cin.ignore();
    getline(cin,returndate);

    ifstream file("borrowedbooks.txt");
    ofstream temp("temp.txt");
    string line;
    bool found=false;

    while(getline(file,line))
    {
        if(line.find(name) !=string::npos && line.find(bookname) != string ::npos)
        {
                found=true;
        }
        else{
            temp<<line<<endl;
        }
    }
    file.close();
    temp.close();
    remove("borrowbooks.txt");
    rename("temp.txt","borrowedbooks.txt");

    if(found)
    {
        cout<<" Book returned successfully!\n";
    }
    else{
        cout<<" Book not found in borrowed books list.\n";
    }
}
void library :: deletebook()
{
    string bookname;
    cout<<" Enter book name to delete: ";
    cin.ignore();
    getline(cin,bookname);

    ifstream file("library.txt");
    ofstream temp("temp.txt");
    string line;
    bool found=false;
    while(getline(file,line))
    {
        if(line.find(bookname) != string ::npos)
        {
            found=true;
        }
        else{
            temp<<line<<endl;
        }
    }
    file.close();
    temp.close();
    remove("library.txt");
    rename("temp.txt","library.txt");

    if(found)
    {
        cout<<" Book deleted successfully!\n";
    }
    else
    {
        cout<<" Book not found in library list.\n";
    }
}
void library :: searchbook()
{
    string search;
    cout<<" Enter book name to search: ";
    cin.ignore();
    getline(cin,search);
    ifstream file("library.txt");
    string line;
    bool found=false;
    while(getline(file,line))
    {
        if(line.find(search) != string ::npos)
        {
            cout<<"book found: "<<line<<endl;
            found=true;
        }
    }
    file.close();
    if(!found)
    {
        cout<<"book not found!\n";
    }
}
int main()
{
    library lib;
    int ch;
    do
    {
        cout<<"=========Library Management System=============\n";
        cout<<"1. Add Book\n";
        cout<<"2. Distplay Book\n";
        cout<<"3. Add user \n";
        cout<<"4. Borrow Book \n";
        cout<<"5. Return Book \n";
        cout<<"6. delete Book \n";
        cout<<"7. search Book \n";
        cout<<"8. exit \n";
        
        cin>>ch;
        switch(ch)
        {
            case 1: lib.addbook();
                    break;
            case 2: lib.displaybook();
                    break;
            case 3: lib.adduser();
                    break;
            case 4: lib.borrowuser();
                    break;
            case 5: lib.returnbook();
                    break;
            case 6: lib.deletebook();
                    break;
            case 7: lib.searchbook();
                    break;
            case 8: exit(0);
                default: cout<<" invalid choice \n";
        }
    }
    while(true);
    return 0;
}