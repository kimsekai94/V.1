
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;
//class used
int acno;
class account
{   
    int acno;
    char year;
    char name[50];
    int num;
    string ooc;
    int stay;
    string entry,ex;

    
    public:
        void create_account(); //function to get data from user
        void show_account() const; //function to show data on screen
        void report() const;
        int retacno() const;
        char retyear() const;
        int retnum() const;
        int retstay() const;
       
        void Showbillpayment();
        void Showbillpaymentscript();
        void billpayment();
        void mainofpricelist();
        void backtomainmenu();
        void priceList();
        void help();
        void exit();
        void memberDetails();
        void mainMenu();
        void welcome();



};

void account::create_account()
{system ("cls");
 cout<<"\t\t=============================================\n";
 cout<<"\t\t             Fill Up The Form\n";
 cout<<"\t\t=============================================\n";
 cout<<"\nRetype Room Number:";
 cin>>acno;
 cout<<"\n\nEnter  Name: ";
 cin.ignore();
 cin.getline(name,50);
 cout<<"\nEnter Age: ";
 cin.ignore();
 cin>>year;
 cout<<"\nEnter Phone Number: ";
 cin>>num;
 cout<<"\nEnter Occupation:";
 cin>>ooc;
 cout<<"\nEnter How Many Days Customer Want to stay:";
 cin>>stay;
 cout<<"\nEnter Entry Date(DD-MM-YY):";
 cin>>entry;
 cout<<"\nEnter EXit Date(DD-MM-YY):";
 cin>>ex;
 cout<<"\n\n\nThis Room Has Been Booked for "<<stay<<" days\n\t\t\t";
}
void account::report() const
{
 cout<<acno<<setw(10)<<" "<<name<<setw(2)<<" "<<year<<setw(2)<<num<<ooc<<stay<<entry<<ex;
}
int account::retacno() const
{
 return acno;
}

char account::retyear() const{
    return year;
}
int account::retnum() const{
    return num;
}
int account::retstay() const{
    return stay;
}

       
void account::show_account() const
{
 cout<<"\nAccount No. : "<<acno;
 cout<<"\nAccount Holder Name : ";
 cout<<name;
 cout<<"\nType of Account : "<<year;
 cout<<"\nBalance amount : "<<num;
}


//***************************************************************
//     function to write in file
//****************************************************************

void write_account()
{
 account ac;
 ofstream outFile;
 outFile.open("account.dat",ios::binary|ios::app);
 ac.create_account();
 outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
 outFile.close();
}
//***************************************************************
//     function to read specific record from file
//****************************************************************
void display_sp(int n)
{system ("cls");
 account ac;
 bool flag=false;
 ifstream inFile;
 inFile.open("account.dat",ios::binary);
 if(!inFile)
 {
  cout<<"File could not be open !! Press any Key...";
  return;
 }
 cout<<"\nBALANCE DETAILS\n";

     while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
 {
  if(ac.retacno()==n)
  {
   ac.show_account();
   flag=true;
  }
 }
 inFile.close();
 if(flag==false)
  cout<<"\n\nAccount number does not exist";
  system ("pause");
}

//***************************************************************
//     function to modify record of file
//****************************************************************

/*void modify_account(int n)
{
 bool found=false;
 account ac;
 fstream File;
 File.open("account.dat",ios::binary|ios::in|ios::out);
 if(!File)
 {
  cout<<"File could not be open !! Press any Key...";
  return;
 }
 while(!File.eof() && found==false)
 {
  File.read(reinterpret_cast<char *> (&ac), sizeof(account));
  if(ac.retacno()==n)
  {
   ac.show_account();
   cout<<"\n\nEnter The New Details of account"<<endl;
   ac.modify();
   int pos=(-1)*static_cast<int>(sizeof(account));
   File.seekp(pos,ios::cur);
   File.write(reinterpret_cast<char *> (&ac), sizeof(account));
   cout<<"\n\n\t Record Updated";
   found=true;
    }
 }
 File.close();
 if(found==false)
  cout<<"\n\n Record Not Found ";
}*/

//***************************************************************
//     function to delete record of file
//****************************************************************


void delete_account(int n)
{
 account ac;
 ifstream inFile;
 ofstream outFile;
 inFile.open("account.dat",ios::binary);
 if(!inFile)
 {
  cout<<"File could not be open !! Press any Key...";
  return;
 }
 outFile.open("Temp.dat",ios::binary);
 inFile.seekg(0,ios::beg);
 while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
 {
  if(ac.retacno()!=n)
  {
   outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
  }
 }
 inFile.close();
 outFile.close();
 remove("account.dat");
 rename("Temp.dat","account.dat");
 cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//     function to display all accounts deposit list
//****************************************************************

void display_all()
{system("cls");
 account ac;
 ifstream inFile;
 inFile.open("account.dat",ios::binary);
 if(!inFile)
 {
  cout<<"File could not be open !! Press any Key...";
  return;
 }
 cout<<"\n\n\t\t ROOM RECORD\n\n";
 cout<<"==================================================================================================================================\n";
 cout<<"Room no.      NAME           Age            Phone          Occupation                 Days          Entry Date      EXit Date\n";
 cout<<"==================================================================================================================================\n";
 while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
 {
  ac.report();
 }
 inFile.close();
 system("pause");
}
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext(){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext(){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext(){SetConsoleTextAttribute(hConsole, 14);  };
void darktext(){SetConsoleTextAttribute(hConsole, 8);  };
string Servicecharges1("*****");
string Servicecharges2("*****");
string Servicecharges3("*****");
string Servicecharges4("*****");
int checkinDate(00);
int checkinMonth(00);
int checkinYear(00);
int checkoutDate(00);
int checkoutMonth(00);
int checkoutYear(00);
double TotalPrice(0.00);
double TotalServicecharges(0.00);
 
bool MenuLoop = true;
string name("*****");    
string surname("*****");
int address1(00);
string address2("*****");
string address3("*****");
string address4("*****");
string postcode("*****");
string tel("00");
int creditcardSelection;
string creditcardType("*****");
string creditcard("****"); 

bool Menupricelist = true;
int number;
double StandardStudio = 600.00;
double DeluxeStudio = 900.00;
double StandardFamily = 1200.00;
double ParkingSpot = 20.00;
double HighSpeedInternet = 50.00;
double FitnessRoom = 20.00;
double Breakfast = 50.00;
int numroom[9]={101,102,103,201,202,203,301,302,303};
string availble = "Yes";
string bookedfor = "N/A Days";
string entrydate = "N/A";
string exitdate = "N/A";
string selectroom;

void resetMemberDetails(){
    name = "*****";
    surname = "*****";
    address1 = 00;
    address2 = "*****";
    address3 = "*****";
    address4 = "*****";
    postcode = "*****";
    tel = "00";
    creditcard = "****";
    creditcardType = "*****";
}

void resetBookingDetails(){
    Servicecharges1 = "*****";
    Servicecharges2 = "*****";
    Servicecharges3 = "*****";
    Servicecharges4 = "*****";
    TotalServicecharges = 00;
    checkinDate= 00;
    checkinMonth = 00;
    checkinYear = 00;
    checkoutDate= 00;
    checkoutMonth = 00;
    checkoutYear = 00;
}

void Showbillpayment(){
    system ("cls");
   	cout<<"\n________________________________________________________________________________\n";
    cout<<"\t\t\t\t    La-lune-hotel  ";
    cout<<"\n \t\t\t____________________________________";
    cout<<"\n\t\t\t\tChiang Mai,Chiang Mai  ";
    cout<<"\n\t\t\t\t    Tel :-023658966 ";
    cout<<"\n--------------------------------------------------------------------------------\n";
 	
    system ("pause");
}  
void Showbillpaymentscript(){
    Showbillpayment();
}


void billpayment(){
    char confirm;
system ("cls");
    char filename [100];
    ifstream file_ptr;
    cout << "\n\t\t\t\tSaved Bookings:\n\n";
    system ("dir/b *.booking");
    cout << "\n\n\tPlease type the name of the booking you\n";
    cout << "\twish to open as it appears above OR\n";
    cout << "\ttype z (Lower case) to return to main menu: ";
    cin.ignore();
      
};   
void mainofpricelist(){
    
    system ("cls");
    cout << "\t\tView of pricelist\n\n";
    cout << "1 - Detail of Room\n\n";
    cout << "2 - Detail of Sevice changes\n\n";
    cout << "3 - Back to Main menu\n\n";
    cout << "Please select a number of page: ";
    cin >> number;

     
}

void backtomainmenu(){
    Menupricelist == false;
}

void priceList(){
    
    mainofpricelist();

    if (number == 1){
    system ("cls");
    cout <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t           page1\n"; 
    cout << "\tPrice List\n\n";
 
    cout << "\t\t\t\t\tDetail of Rooms\n\n\t";
    cout << "\t\t\t\tNone member  |    GSB(discount 10%)    |    KTB(discount 15%)    |    SCB(discount 20%)";
    cout << "\n\n\tStandard Studio.............     \x9c"<< StandardStudio <<" Bath"<< "\t        " << StandardStudio * 0.9 <<" Bath"<< "\t\t  " << StandardStudio * 0.85 <<" Bath"<<"\t\t    " << StandardStudio * 0.8<<"Bath";
    cout << "\n\n\tDeluxe Studio...............     \x9c"<< DeluxeStudio <<" Bath"<< "\t        " << DeluxeStudio * 0.9 <<" Bath"<< "\t\t  " << DeluxeStudio * 0.85 <<" Bath"<<"\t\t    " << DeluxeStudio * 0.8<<"Bath";
    cout << "\n\n\tStandard Family.............     \x9c"<< StandardFamily <<" Bath"<< "\t        " << StandardFamily * 0.9 <<" Bath"<< "\t\t  " << StandardFamily * 0.85 <<" Bath"<<"\t\t    " << StandardFamily * 0.8 <<"Bath"<<"\n\n";
    system ("pause");
    mainofpricelist();
        
    };

    if (number == 2){
    system ("cls");
    cout <<"\t\t\t\t\t\t\t\t\t\t\tpage2\n"; 
    cout << "\tPrice List\n\n";
    
    cout << "\t\t\t\t\tDetail of Service charges\n\n\t";
    cout << "\t\t\t\tPrice(Bath)";
    cout << "\n\n\tParking spot................        \x9c"<< ParkingSpot << " Bath";
    cout << "\n\n\tHigh speed internet.........        \x9c"<< HighSpeedInternet << " Bath";
    cout << "\n\n\tFitness Room................        \x9c"<< FitnessRoom << " Bath";
    cout << "\n\n\tBreakfast............. .....        \x9c"<< Breakfast << " Bath\n\n";
    system ("pause");
    mainofpricelist();

    if(number ==3){
        backtomainmenu();
    
    };

    

}
}
void help(){
    system ("cls");
cout << "\t\t\t\tHelp\n\n";
 
cout << "To enter a new member into the system, Choose option 1 from the Main Menu.\n";
cout << "Enter the new members details into the membership form and press Y to save once finished.\n\n\n";

cout << "To view a price list, select option 2 from the main menu.\n\n\n";
 
cout << "To create a new booking, select option 3 from the main menu.\n";
cout << "Enter the booking choices and then press Y to save the booking\n";
cout << "After create a new booking, can view detail of booking by typing the name of a file as it\n";
cout << "is displayed on the list to open and view it.\n\n\n";
 
cout << "To view a bill payment, choose option 4 from the main menu\n";
cout << "To open a member or booking file, choose option 3 at the main menu.\n";
cout << "Type the name of a file as it is displayed on the list to open and view it.\n\n\n";
 

 
system ("pause");
}
void exit(){
     MenuLoop = false;
}

void roombooking(){
    system ("cls");
    cout << "\t\t\t\t\t\t\t\t\tOur rooms\n\n";
    cout << "\t\tRoom No\t\t    Category\t\t Availble\t\t Booked for\t\t Entry Date\t\t Exit Date";
    cout << "\n\n\t\t  "<<numroom[0]<<"    \x9c\t  "<<"Standard Studio" <<"\t     " << availble <<"\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[1]<<"    \x9c\t  "<<"Standard Studio" <<"\t     " << availble <<"\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[2]<<"    \x9c\t  "<<"Standard Studio" <<"\t     " << availble <<"\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[3]<<"    \x9c\t  "<<"Deluxe Studio" <<"\t\t     " <<availble<< "\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[4]<<"    \x9c\t  "<<"Deluxe Studio" <<"\t\t     " <<availble<< "\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[5]<<"    \x9c\t  "<<"Deluxe Studio" <<"\t\t     " <<availble<< "\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[6]<<"    \x9c\t  "<<"Standard Family"<<"\t     " <<availble<< "\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[7]<<"    \x9c\t  "<<"Standard Family"<<"\t     " <<availble<< "\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate;
    cout << "\n\n\t\t  "<<numroom[8]<<"    \x9c\t  "<<"Standard Family"<<"\t     " <<availble<< "\t\t    " << bookedfor<<"\t\t      " << entrydate<<"\t\t     " << exitdate<<"\n\n";
      cout << "\t\t\t\t\t\t\t\tWhich Room You Want To Book:";cin >>numroom[9];
    write_account();
    system ("pause");
}
void memberDetails(){

}
void mainMenu(){
    int num;

    int menuchoice;
    system ("cls");
    resetMemberDetails();
    bluetext();
    cout << "\t\t\t\tMain Menu\n\n";
    whitetext();
    cout << "\t\t1 - Room bookig\n\n";
    cout << "\t\t2 - View Room Record \n\n";
    resetBookingDetails();
    cout << "\t\t3 - Create a new booking\n\n";
    whitetext();
    cout << "\t\t4 - bill payment\n\n";
    cout << "\t\t5 - Help\n\n";
    cout << "\t\t6 - Exit\n\n\n";
    cout << "\t\t\tPlease choose an option : ";
    cin >> menuchoice;
    while (cin.fail())
        {cin.clear();
        cin.ignore();
        cout << "\n\t\tPlease enter a valid number :"; cin >> menuchoice;
    };
    switch (menuchoice){
        case 1 :
            roombooking();
            break;
        case 2 :
            display_all();
            break;
        case 3 :
            memberDetails();
            break;
        case 4 :
        cout<<"\n\n\tEnter The account No. : "; cin>>num;
             delete_account(num);
            break;
        case 5 :
            help();
            break;
        case 6 :
            exit();
            break;
        default:
            cout << "\n\tPlease enter a correct menu choice\n\n\t";
            system ("pause");
    };
};

void welcome(){
    bluetext();
    cout << "\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  *           WELCOME to            *  @\n";
    cout <<       "\t\t\t@  *         La-lune-hotel           *  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    whitetext();
    cout <<       "\n\n\t\t\t\t>";
    cout << "   Main menu \n";
    greentext();
    cout << "\t\t      press enter in order to approach Main menu... ";
    cin.get(); 
}
int main(){
    welcome();
    while (MenuLoop == true){mainMenu();};     
    return 0;
}
