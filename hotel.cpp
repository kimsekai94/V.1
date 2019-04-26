#include<iostream>
#include <ctime>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<iomanip>

#define max 100
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext(){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext(){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext(){SetConsoleTextAttribute(hConsole, 14);  };
void darktext(){SetConsoleTextAttribute(hConsole, 8);  };
using namespace std;

bool Menupricelist = true;
int number;
//Class Customer
class Customer
{
    public:
    char name[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    double ServiceCharge;
    int booking_id;
};


class Room
{
    public:
    string type;
    string stype;
    string ac;
    int roomNumber;
    int rent;
    int status;

    class Customer cust;
    class Room addRoom(int);
    void searchRoom(int);
    void deleteRoom(int);
    void displayRoom(Room);
};

//Global Declarations
class Room rooms[max];
int count=0;

Room Room::addRoom(int rno)
{
    class Room room;
    room.roomNumber=rno;
    cout<<"\n\t\tType AC/Non-AC (Yes=Y/No=N) : ";
    cin>>room.ac;
    cout<<"\n\t\tType Room (Single=S/Double=D) : ";
    cin>>room.type;
    cout<<"\n\t\tType Size (Big=B/Small=S) : ";
    cin>>room.stype;
    cout<<"\n\t\tDaily Rent : ";
    cin>>room.rent;
    room.status=0;
    greentext();
    cout<<"\n\t\tRoom Added Successfully!";
    getch();
    return room;
}


void Room::searchRoom(int rno)
{
    int i,found=0;
    for(i=0;i<count;i++){
        if(rooms[i].roomNumber==rno){
        found=1;
        break;
        }
    }
    if(found==1)
    {   
        cout<<"\n\t\t---Room Details---\n";
        if(rooms[i].status==1){
        redtext();
        cout<<"\n\t\tRoom is Reserved";
        }else{
            greentext();
            cout<<"\n\t\tRoom is available";
            }
    whitetext();
    displayRoom(rooms[i]);
    getch();
    }else{
    cout<<"\nRoom not found";
    getch();
    }
}

void Room::displayRoom(Room tempRoom)
{
    cout<<"\n\t\tRoom Number : \t"<<tempRoom.roomNumber;
    cout<<"\n\t\tType AC/Non-AC (Yes=Y/No=N) : "<<tempRoom.ac;
    cout<<"\n\t\tType Room (Single=S/Double=D) : "<<tempRoom.type;
    cout<<"\n\t\tType Size (Big=B/Small=S) : "<<tempRoom.stype;
    cout<<"\n\t\tRent : "<<tempRoom.rent;
}

//hotel management class
class HotelMgnt:protected Room
{
    public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char *);
    void checkOut(int);
    void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

    if(count==0){
        redtext();
        cout<<"\n\t\t No Guest in Hotel !!";
    } 
    for(int i=0;i<count;i++){
        if(rooms[i].status==1){
            cout<<"\n\t\t Customer Name : "<<rooms[i].cust.name;
            cout<<"\n\t\t Room Number : "<<rooms[i].roomNumber;
            cout<<"\n\t\t Address (only city) : "<<rooms[i].cust.address;
            cout<<"\n\t\t Phone : "<<rooms[i].cust.phone;
            cout<<"\n\t\t Enter Check In Date (DD-MM-YY): "<<rooms[i].cust.from_date;
            cout<<"\n\t\t Enter Check Out Date (DD-MM-YY): "<<rooms[i].cust.to_date;
            greentext();
            cout<<"\n\t\t==================================================================="; 
            whitetext();
        }
    
    }
    getch();
}

//hotel management reservation of room
void HotelMgnt::checkIn(){
    system("cls");

    int i,found=0,rno,k;
    string j;
    char Parking ; 
    char gym;
    double parkingCost;
    double gymCost;


    class Room room;
    cout<<"\n\t\tEnter Room number : ";
    cin>>rno;
    for(i=0;i<count;i++){
        if(rooms[i].roomNumber==rno){
            found=1;
            break;}
    }if(found==1){
        if(rooms[i].status==1){
            redtext();
            cout<<"\n\t\tRoom is already Booked";
            getch();
            return;
        }

        cout<<"\n\t\tEnter booking id(Number 4 digit): ";
        rooms[i].cust.booking_id =rand()%8999+1000;
        cout <<  rooms[i].cust.booking_id <<"\n";

        cout<<"\n\t\tEnter Customer Name (First Name): ";
        cin>>rooms[i].cust.name;

        cout<<"\n\t\tEnter Address (only city): ";
        cin>>rooms[i].cust.address;

        cout<<"\n\t\tEnter Phone: ";
        cin>>rooms[i].cust.phone;

        cout<<"\n\t\tEnter Check In Date (DD-MM-YY): ";
        cin>>rooms[i].cust.from_date;

        cout<<"\n\t\tEnter Check Out Date (DD-MM-YY): ";
        cin>>rooms[i].cust.to_date;
        
        cout <<"\n\t\tEnter Service : ";
        do {
        cout << "\n\t\tDo you want a parking spot during your stay? ";
        cin >> Parking;
        if (Parking == 'Y' || Parking == 'y'){

            parkingCost = 20;
            break;
        }
        else if (Parking == 'N' || Parking == 'n'){
            parkingCost = 0;
            break;
        }
        else{
            cout << "\n\t\tYou entered an invalid answer. Please enter 'Y' for yes or 'N' for no.\n";
        }
        }while (Parking != 'Y' && Parking != 'y' && Parking != 'N' && Parking != 'n');
        
        
        do {
        cout << "\n\t\tDo you want a high speed internet during your stay? ";
        cin >> gym;
        if (gym == 'Y' || gym == 'y'){
            gymCost = 50;
            break;
        }
        else if (gym == 'N' || gym == 'n'){
            gymCost = 0;
            break;
        }
        else{
            cout << "\n\t\tYou entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        } 
        }while (   gym != 'Y' && gym != 'y' && gym != 'N' && gym != 'n');

        rooms[i].cust.ServiceCharge = parkingCost + gymCost;

        do{
            cout<<"\n\t\tEnter  your Type of Creditcard : ";
            cin>>j;
            if (j == "GSB"){
                rooms[i].cust.payment_advance = 0.9; };
            if (j == "KTB"){
                rooms[i].cust.payment_advance = 0.85; };
            if (j == "SCB"){
                rooms[i].cust.payment_advance = 0.6; };
            if (j == "No"){
                rooms[i].cust.payment_advance = 1.0; };
        }while (j!= "GSB" && j!= "KTB" && j!= "SCB" && j!= "No" );
      
        
        

        rooms[i].status=1;
        greentext();
        cout<<"\n\t\t Customer Checked-in Successfully..";
        
        getch();
        
    }
}


//hotel management shows available rooms
void HotelMgnt::getAvailRoom(){
    system("cls");
    int i,found=0;
        for(i=0;i<count;i++){
            if(rooms[i].status==0){
                displayRoom(rooms[i]);
                greentext();
                cout<<"\n\n\t\tPress enter for next room";
                whitetext();
                found=1;
                getch();
            }
        }if(found==0){
            redtext();
        cout<<"\n\t\tAll rooms are reserved";
        getch();
        
        }
}


//hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(char *pname){
    system("cls");
        int i,found=0;
        for(i=0;i<count;i++){
            if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0){
                cout<<"\n\t\tCustomer Name: "<<rooms[i].cust.name;
                cout<<"\n\t\tRoom Number: "<<rooms[i].roomNumber;
                greentext();
                cout<<"\n\n\t\tPress enter for next record";
                found=1;
                getch();
            }
        }if(found==0)
        {
            redtext();
        cout<<"\n\t\tPerson not found.";
        getch();
        
        }
}


//hotel managemt generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{       system("cls");
        int i,found=0,days,rno;
        float billAmount=0;
        for(i=0;i<count;i++){
            if(rooms[i].status==1 && rooms[i].roomNumber==roomNum){
            //rno = rooms[i].roomNumber;
            found=1;
            //getch();
            break;
            }
        }if(found==1)
        {   

            cout<<"\n\t\tEnter Number of Days (How many do you stay):\t";
            cin>>days;
            billAmount= (days * rooms[i].rent) + rooms[i].cust.ServiceCharge;
            cout<<"\t\t=============================================\n";
            bluetext();
            cout<<"\t\t                CheckOut Details \n";
            whitetext();
            cout<<"\t\t=============================================\n";
            cout<<"\n\t\tBooking ID : "<<rooms[i].cust.booking_id;
            cout<<"\n\t\tCustomer Name : "<<rooms[i].cust.name;
            cout<<"\n\t\tRoom Number : "<<rooms[i].roomNumber;
            cout<<"\n\t\tAddress : "<<rooms[i].cust.address;
            cout<<"\n\t\tPhone : "<<rooms[i].cust.phone;
            cout<<"\n\t\tEnter Check In Date (DD-MM-YY): "<<rooms[i].cust.from_date;
            cout<<"\n\t\tEnter Check Out Date (DD-MM-YY): "<<rooms[i].cust.to_date;
            cout<<"\n\t\tTotal ServiceCharge: " << rooms[i].cust.ServiceCharge <<" baht";
            cout<<"\n\t\tTotal Amount Due : "<<billAmount <<" baht";
            cout<<"\n\t\tAdvance Paid(discount): "<<rooms[i].cust.payment_advance<<" %";
            cout<<"\n\t\t*** Total Payable: "<< billAmount*rooms[i].cust.payment_advance<<" baht ";

            rooms[i].status=0;
        }
    getch();
    
}


//managing rooms (adding and searching available rooms)
void manageRooms()
{
        class Room room;
        int opt,rno,i,flag=0;
        char ch;
        do
        {
            system("cls");
            whitetext();
            cout<<"\t\t=============================================\n";
            bluetext();
            cout<<"\t\t                Manage Rooms\n";
            whitetext();
            cout<<"\t\t=============================================\n";
            cout<<"\n\t\t\t1 - Add Room";
            cout<<"\n\t\t\t2 - Search Room";
            cout<<"\n\t\t\t3 - Back to Main Menu";
            cout<<"\n\n\t\tPlease choose an option : ";
            cin>>opt;
        //switch statement
        switch(opt){
        case 1:
            cout<<"\n\t\tEnter Room Number: ";
            cin>>rno;
            i=0;
            for(i=0;i<count;i++){
                if(rooms[i].roomNumber==rno)
                {flag=1;}
            }if(flag==1){
                redtext();
                cout<<"\n\t\tRoom Number is Present.\n\t\tPlease enter unique Number";
                flag=0;
                getch();
            }else{
            rooms[count]=room.addRoom(rno);
            count++;
            }
            break;
        case 2:
            cout<<"\n\t\tEnter room number: ";
            cin>>rno;
            room.searchRoom(rno);
            break;
        case 3:
            //nothing to do
            break;
            default:
            cout<<"\n\t\tPlease Enter correct option";
            break;
            }
            }while(opt!=3);
}
void mainofpricelist(){
    
    system ("cls");
    cout << "\t\tView of pricelist\n\n";
    cout << "1 - Detail of Room\n\n";
    cout << "2 - Back to Main menu\n\n";
    cout << "Please select a number of page: ";
    cin >> number;

     
}

void backtomainmenu(){
    Menupricelist == false;
}
void priceList(){
    
    mainofpricelist();
    switch(number){
        case 1:

    system ("cls");
   
    cout << "\tPrice List\n\n";
 
    cout << "\t\t\t\t\tDetail of Rooms\n\n\t";

    cout << "\t\tRoom No\t\t    AC/Non-AC \t\t   Single/Double\t\t   Big/Small \t\t   Price";
    cout << "\n\n\t\t\t  101      \x9c\t\t  "<<"AC"<<setw(26)<<"Single" <<setw(29)<<"Big"<<setw(22)<<"4000 "<<"Baht";
    cout << "\n\n\t\t\t  102      \x9c\t\t  "<<"AC"<<setw(26)<<"Single" <<setw(29)<<"Big"<<setw(22)<<"4000 "<<"Baht";
    cout << "\n\n\t\t\t  103      \x9c\t\t  "<<"AC"<<setw(26)<<"Single" <<setw(29)<<"Small"<<setw(22)<<"3000 "<<"Baht";
    cout << "\n\n\t\t\t  104      \x9c\t\t  "<<"AC"<<setw(26)<<"Single" <<setw(29)<<"Small"<<setw(22)<<"3000 "<<"Baht";
    cout << "\n\n\t\t\t  201      \x9c\t\t  "<<"AC"<<setw(26)<<"Double" <<setw(29)<<"Big"<<setw(22)<<"6000 "<<"Baht";
    cout << "\n\n\t\t\t  202      \x9c\t\t  "<<"AC"<<setw(26)<<"Double" <<setw(29)<<"Big"<<setw(22)<<"6000 "<<"Baht";
    cout << "\n\n\t\t\t  203      \x9c\t\t  "<<"AC"<<setw(26)<<"Double" <<setw(29)<<"Small"<<setw(22)<<"5000 "<<"Baht";
    cout << "\n\n\t\t\t  204      \x9c\t\t  "<<"AC"<<setw(26)<<"Double" <<setw(29)<<"Small"<<setw(22)<<"5000 "<<"Baht";
    cout << "\n\n\t\t\t  301      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Single" <<setw(29)<<"Big"<<setw(22)<<"3500 "<<"Baht";
    cout << "\n\n\t\t\t  302      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Single" <<setw(29)<<"Big"<<setw(22)<<"3500 "<<"Baht";
    cout << "\n\n\t\t\t  303      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Single" <<setw(29)<<"Small"<<setw(22)<<"2500 "<<"Baht";
    cout << "\n\n\t\t\t  304      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Single" <<setw(29)<<"Small"<<setw(22)<<"2500 "<<"Baht";
    cout << "\n\n\t\t\t  401      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Double" <<setw(29)<<"Big"<<setw(22)<<"5500 "<<"Baht";
    cout << "\n\n\t\t\t  402      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Double" <<setw(29)<<"Big"<<setw(22)<<"5500 "<<"Baht";
    cout << "\n\n\t\t\t  403      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Double" <<setw(29)<<"Small"<<setw(22)<<"4500 "<<"Baht";
    cout << "\n\n\t\t\t  404      \x9c\t  "<<setw(12)<<"Non-AC"<<setw(24)<<"Double" <<setw(29)<<"Small"<<setw(22)<<"4500 "<<"Baht\n\n";
   
    system ("pause");
    mainofpricelist();
    getch();
    
        case 2:
    backtomainmenu();
    }


 

}

void welcome();

int main(){
     srand(time(0));
     class HotelMgnt hm;
     int i,j,opt,rno;
     char ch;
     char pname[100];
     welcome();
     system("cls");

     do{
            system("cls");
            bluetext();
            cout << "\t\t\t\tMain Menu\n\n";
            whitetext();
            cout<<"\n\t\t\t0 - View Price Room";
            cout<<endl;
            cout<<"\n\t\t\t1 - Manage Rooms";
            cout<<endl;
            cout<<"\n\t\t\t2 - Check-In Room";
            cout<<endl;
            cout<<"\n\t\t\t3 - Available Rooms";
            cout<<endl;
            cout<<"\n\t\t\t4 - Search Customer";
            cout<<endl;
            cout<<"\n\t\t\t5 - Check-Out Room";
            cout<<endl;
            /*cout<<"\n\t\t\t6 - Guest Summary Report";
            cout<<endl;*/
            cout<<"\n\t\t\t6 - Exit";
            cout<<endl;
            cout<<"\n\n\t\t\tPlease choose an option : ";
            cin>>opt;
            switch(opt){
                case 0:
                    priceList();
                    break;
                case 1:
                    manageRooms();
                    break;
                case 2:
                    if(count==0){
                        redtext();
                        cout<<"\n\t\tRooms data is not available.";
                        greentext();
                        cout<<"\n\t\tPlease add the rooms first.";
                        getch();
                    }else hm.checkIn();
                    break;
                case 3:
                    if(count==0){
                        redtext();
                        cout<<"\n\t\tRooms data is not available.";
                        greentext();
                        cout<<"\n\t\tPlease add the rooms first.";
                        getch();
                    }else hm.getAvailRoom();
                    break;
                case 4:
                    if(count==0) {
                        redtext();
                        cout<<"\n\t\tRooms data is not available.";
                        greentext();
                        cout<<"\n\t\tPlease add the rooms first.";
                        getch();
                    }else{
                        cout<<"\t\tEnter Customer Name: ";
                        cin>>pname;
                        hm.searchCustomer(pname);
                    }
                    break;
                case 5:
                    if(count==0){
                        redtext();
                        cout<<"\n\t\tRooms data is not available.";
                        greentext();
                        cout<<"\n\t\tPlease add the rooms first.";
                        getch();
                    }else{
                        cout<<"\t\tEnter Room Number : ";
                        cin>>rno;
                        hm.checkOut(rno);
                    }
                    break;
               /* case 6:
                    hm.guestSummaryReport(); 
                    break;*/
                case 6:
                    greentext();
                    cout<<"\n\t\tTHANK YOU! FOR RESERVATION";
                    break;
                    default:
                    cout<<"\n\t\tPlease Enter correct option";
                    break;
            }
            }while(opt!=6);

             getch();
}
void welcome(){
    bluetext();
    cout << "\n\n\n\t\t\t\t\t\t\t\t---------------------------------------------------\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *********************************************  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                                           *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                                           *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                                           *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                WELCOME to                 *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *              La-lune-hotel                *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                                           *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                                           *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *                                           *  |\n";
    cout <<       "\t\t\t\t\t\t\t\t|  *********************************************  |\n";
    cout <<       "\t\t\t\t\t\t\t\t---------------------------------------------------\n";
    whitetext();
    cout <<       "\n\n\t\t\t\t\t\t\t\t>";
    cout << "   Main menu \n";
    greentext();
    cout << "\t\t\t\t\t\t\t\t      press enter in order to approach Main menu... ";
    cin.get(); 
}