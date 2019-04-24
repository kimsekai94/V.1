#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

bool MenuLoop = true;
bool Menupricelist = true;
int pricelistchoice;

double StandardStudio = 600.00;
double DeluxeStudio = 900.00;
double StandardFamily = 1200.00;
double ParkingSpot = 20.00;
double HighSpeedInternet = 50.00;
double FitnessRoom = 20.00;
double Breakfast = 50.00;

void backtomainmenu(){
    Menupricelist = false;
}

void mainofpricelist(){
    system ("cls");
    cout << "\n\t\t\t\tView of pricelist\n\n";
    cout << "\t\t1 - Detail of Room\n\n";
    cout << "\t\t2 - Detail of Sevice changes\n\n";
    cout << "\t\t3 - Back to Main menu\n\n";
    cout << "\n\t\t\tPlease choose an option : ";
    cin >> pricelistchoice;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "\n\t\t\tPlease enter a valid number : ";
        cin >> pricelistchoice;
    }
}

void viewpricelist(){
    mainofpricelist();
    if(pricelistchoice == 1){
        system ("cls");
        cout << "\n\t\t\t\t\tDetail of Rooms\n\n\n\t";
        cout << "\t\t\t\tNone member  |    GSB(discount 10%)    |    KTB(discount 15%)    |    SCB(discount 20%)";
        cout << "\n\n\tStandard Studio.............     \x9c"<< StandardStudio << "  Bath" << "\t      " << StandardStudio * 0.9 << "  Bath"<< "\t\t       " << StandardStudio * 0.85 <<"  Bath"<<"\t\t  " << StandardStudio * 0.8<<" Bath";
        cout << "\n\n\tDeluxe Studio...............     \x9c"<< DeluxeStudio   << "  Bath" << "\t      " << DeluxeStudio * 0.9   << "  Bath"<< "\t\t       " << DeluxeStudio * 0.85 <<"  Bath"<<"\t\t  " << DeluxeStudio * 0.8<<" Bath";
        cout << "\n\n\tStandard Family.............     \x9c"<< StandardFamily << " Bath"  << "\t      " << StandardFamily * 0.9 << " Bath"<< "\t\t       " << StandardFamily * 0.85 <<" Bath"<<"\t\t  " << StandardFamily * 0.8 <<" Bath"<<"\n\n";            system ("pause");
        mainofpricelist();
    }
    if(pricelistchoice == 2){
        system ("cls");
        cout << "\n\t\t\t\t\tDetail of Service charges\n\n\t";
        cout << "\t\t\t\tPrice(Bath)";
        cout << "\n\n\tParking spot................        \x9c"<< ParkingSpot << " Bath";
        cout << "\n\n\tHigh speed internet.........        \x9c"<< HighSpeedInternet << " Bath";
        cout << "\n\n\tFitness Room................        \x9c"<< FitnessRoom << " Bath";
        cout << "\n\n\tBreakfast............. .....        \x9c"<< Breakfast << " Bath\n\n";
        system ("pause");
        mainofpricelist();
    }
    if(pricelistchoice == 3){
        backtomainmenu();
    }
}

void createbooking(){

}

void billpayment(){

}

void help(){
    system ("cls");
    cout << "\n\t\t\t\t\t\t\tHelp\n\n";
    cout << "\t\tTo view a price list, select option 1 from the main menu.\n\n\n";
    cout << "\t\tTo create a new booking, select option 2 from the main menu.\n";
    cout << "\t\tis displayed on the list to open and view it.\n\n\n"; 
    cout << "\t\tTo view a bill payment, choose option 3 from the main menu\n";
    system ("pause");
}

void exit(){
    MenuLoop = false;
}

void mainMenu(){
    int menuchoice;
    system ("cls");
    cout << "\n\t\t\t\tMain Menu\n\n";
    cout << "\t\t1 - View price list\n\n";
    cout << "\t\t2 - Create a new booking\n\n";
    cout << "\t\t3 - bill payment\n\n";
    cout << "\t\t4 - Help\n\n";
    cout << "\t\t5 - Exit\n\n\n";
    cout << "\t\t\tPlease choose an option : ";
    cin >> menuchoice;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "\n\t\tPlease enter a valid number : ";
        cin >> menuchoice;
    };
    switch (menuchoice){
        case 1 :
            viewpricelist();
            break;
        case 2 :
            createbooking();
            break;
        case 3 :
            billpayment();
            break;
        case 4 :
            help();
            break;
        case 5 :
            exit();
            break;
        default:
            cout << "\n\tPlease enter a correct menu choice : \n\n\t";
            system ("pause");
    }
}

void welcome(){
    cout << "\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  *           WELCOME to            *  @\n";
    cout <<       "\t\t\t@  *         La-lune-hotel           *  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout <<   "\n\n\t\t\tPress enter in order to approach main menu";
    cin.get();
}

int main(){
    welcome();
    while(MenuLoop == true){
        mainMenu();
    }    
    return 0;
}