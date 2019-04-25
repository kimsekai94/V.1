#include <iostream>

using namespace std;
class ServiceCharge{ 
    char Parking ; 
    char internet;
    char gym;
    char breakfast;
    double parkingCost;
    double internetCost;
    double gymCost;
    double breakfastCost;
    double breakfastCost;

    public:
    ServiceCharge(char,char,char,char);
    double ServiceParking(); 
    double Serviceinternet();  
    double Servicegym();  
    double Servicebreakfast();
    double totalService(double,double,double,double);     
    void ShowService();
       
    };

ServiceCharge::ServiceCharge(char a ,char b ,char c ,char d){
    Parking = a;
    internet = b;
    gym = c;
    breakfast = d;
}

double ServiceCharge::ServiceParking(){
    do {
        cout << "Do you want a parking spot during your stay? ";
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
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.\n";
        }
        }while (Parking != 'Y' && Parking != 'y' && Parking != 'N' && Parking != 'n');
    return parkingCost;
}

double ServiceCharge::Serviceinternet(){
        do {
        cout << "Do you want a high speed internet during your stay? ";
        cin >> internet;
        if (internet == 'Y' || internet == 'y'){
            internetCost = 50;
            break;
        }
        else if (internet == 'N' || internet == 'n'){
            internetCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        } 
        }while (   internet != 'Y' && internet != 'y' && internet != 'N' && internet != 'n');
    return internetCost;
}


double ServiceCharge::Servicegym(){
    do {
        cout << "Do you want to use of the fitness room during your stay? ";
        cin >> gym;
        if (gym == 'Y' || gym == 'y'){
            gymCost = 20;
            break;
        }
        else if (gym == 'N' || gym == 'n'){
            gymCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        }
        } while (   gym != 'Y' && gym != 'y' && gym != 'N' && gym != 'n');
    return gymCost;
}  

double ServiceCharge::Servicebreakfast(){
    char breakfast;
    double breakfastCost ;
    do {
        cout << "Do you want a breakfast during your stay? ";
        cin >> breakfast;
        if (breakfast == 'Y' || breakfast == 'y'){
            breakfastCost = 50;
            break;
        }
        else if (breakfast == 'N' || breakfast == 'n'){
            breakfastCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        }
        } while (   breakfast != 'Y' && breakfast != 'y' && breakfast != 'N' && breakfast != 'n');
    return breakfastCost;
}

double ServiceCharge::totalService(double a ,double b ,double c ,double d){
   return a + b + c + d; 
}

void ServiceCharge::ShowService(){
    cout << "Do you want a parking spot during your stay? (Y/N) : ";
    cin >> Parking;
    cout << "\nDo you want a high speed internet during your stay? (Y/N) : ";
    cin >> internet;
    cout << "\nDo you want to use of the gym room during your stay? (Y/N) : ";
    cin >> gym;
    cout << "\nDo you want a breakfast during your stay? (Y/N) : ";
    cin >> breakfast;
    ServiceCharge(Parking,internet,gym,breakfast);
    double ServiceParking(); 
    double Serviceinternet();  
    double Servicegym();  
    double Servicebreakfast();
    cout << " The Total service charges are : " << totalService(parkingCost,internetCost,gymCost,breakfastCost);

}