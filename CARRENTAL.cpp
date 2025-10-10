#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
class CarRental
{
    public:
    int carid;
    string model;
    string brand;
    double rentperday;
    bool isAvailable;


    CarRental(){}

    CarRental(int i,string m,string b,double r,bool a)
        :carid(i),model(m),brand(b),rentperday(r),isAvailable(a){}

    
    void savedata()
    {
        ofstream file("cars.txt",ios::app);
        if(file)
        {
            file<<carid<<" "<<model<<" "<<brand<<" "<<rentperday<<" "<<isAvailable<<"\n";
            file.close();
            cout<<"Car added successfully!\n";
        }
        else
        {
            cout<<"Error opening file.\n";
        }

    }
    void display()
    {
        cout<< " Cars ID :"<<carid
            <<" | MOdel :"<<model
            <<" | brand:"<<brand
            <<" | Rent PerDay :"<<rentperday
            <<" | ISAVailable :"<<(isAvailable ? "yes":"NO")<<endl;
    }
    static void viewCars()
    {
        ifstream file("cars.txt");
        if(!file)
        {
            cout<<"NO Cars Found.\n";
            return;
        }
         CarRental c;
        cout<<"\n-----------Available Cars------------\n";
        while(file>>c.carid>>c.model>>c.brand>>c.rentperday>>c.isAvailable)
        {
            c.display(); 
        }
        file.close();
    }
    static void rentCar()
    {
        int rentid;
        long phoneno;
        string name,address;

        cout<<"Enter Car ID to rent :";
        cin>>rentid;
        cout<<"Enter your name :";
        cin>>name;
        cout<<"Enter your address :";
        getline(cin, address);
        cout<<"Enter your phone no :";
        cin>>phoneno;

        ifstream in("cars.txt");
        if(!in)
        {
            cout<<"No cars available.\n";
            return;
        }
        ofstream out("temp.txt",ios::trunc);
        if(!out)
        {
               cout<<"Error processing request.\n";
               return;
        }
        CarRental c;
        bool found=false;

        while(in>>c.carid>>c.model>>c.brand>>c.rentperday>>c.isAvailable)
        {
            if(c.carid==rentid && c.isAvailable)
            {
                c.isAvailable=false;
                found=true;
                cout<<"Car rented successfully to "<<name<<"!\n";
            }
            out << c.carid << " " << c.model << " " << c.brand << " " << c.rentperday << " " << c.isAvailable << endl;
            //out<<c.carid<<" "<<c.model<<" "<<c.brand<<" "<<c.rentperday<<" "<<c.isAvailable<<" "<<endl;
        }
        if(!found)
        {
            cout<<"Car not found or already rented.\n";
        }
        in.close();
        out.close();
        remove("cars.txt");
        rename("temp.txt","cars.txt");
    }
    static void returnCar()
    {
        int returnid;
        cout<<"Enter Car ID to return :";
        cin>>returnid;

        ifstream in("cars.txt");
        ofstream out("temp.txt");

        CarRental c;
        bool found = false;

        while(in>>c.carid>>c.model>>c.brand>>c.rentperday>>c.isAvailable)
        {
            if(c.carid == returnid && !c.isAvailable)
            {
                c.isAvailable=true;
                found=true;
                cout<<"Car returned successfully!\n";
            }
            out<<c.carid<<" "<<c.model<<" "<<c.brand<<" "<<c.rentperday<<" "<<c.isAvailable<<" "<<endl;
        }
        if(!found)
        {
            cout<<"Car not found or not rented.\n";
        }
        in.close();
        out.close();
        remove("cars.txt");
        rename("temp.txt","cars.txt");
    }
};
int main()
{ 
    CarRental d;
    int ch;
    while(true)
    {
        cout<<"1. Add Car \n";
        cout <<"2. View Cars\n";
        cout <<"3. Rent a Car\n";
        cout <<"4. Return Car\n";
        cout <<"5. Exit ";

        cout <<"Enter your choice ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {   int id;
                string model,brand;
                double rent;
                cout<<"Enter Car ID :";
                cin>>id;
                cout<<"Enter Car Model :";
                cin>>model;
                cout<<"Enter Car Brand :";
                cin>>brand;
                cout<<"Enter Rent Per Day :";
                cin>>rent;
                CarRental c(id,model,brand,rent,true);
                c.savedata();   
            }                 
            break;
            case 2: d.viewCars();
                break;
            case 3: d.rentCar();
                break;
            case 4: d.returnCar();
                break;
            case 5: return 0;
            default:cout<<"invaild choice ";
        }
    }
    return 0;
}