#include <iostream>
#include <string>
using namespace std;

class Information{
    string name;
    string Tel;
    string Creditcard;
    string service1;
    string service2;
    string service3;
    string service4;
    int dayin;
    int monthin;
    int yearin;
    int dayout;
    int monthout;
    int yearout;
    char room[9] = {'101','102','103','201','202','203','301','302','303'};
    

public:

    Information(string,string,string);
    string roomtype;
    void roomnumber(char);
    char bookingroom();
    int totalservice(string,string,string,string);
    void showInformation();
};

Information::Information(string a,string b,string c){
    name = a;
    Tel = b;
    Creditcard = c;
}

int Information::totalservice(string a,string b,string c,string d){
    int p1,p2,p3,p4;

        if(a == "Yes") p1 = 20;
        if(b == "Yes") p1 = 50;
        if(c == "Yes") p1 = 20;
        if(d == "Yes") p1 = 50;

        return p1+p2+p3+p4;

}

void Information::roomnumber(char roomtype){
    switch (roomtype){
    case '1' :
       for (int i = 0; i < 3; i++){
           cout << room[i] <<"\n";
       }    
        break;
    case '2' :
       for (int i = 3; i < 6; i++){
           cout << room[i] <<"\n";
       }    
        break;
    case '3' :
       for (int i = 6; i < 9; i++){
           cout << room[i] <<"\n";
       }    
        break;
    
    default:
        
        roomtype == '0';
    }    
}



void Information::showInformation(){
    cout << "__________________________________________________________\n";
    cout << "\t\t\tName : " << name << "\n";
    cout << "\t\t\tTelephone : " << Tel << "\n";
    cout << "\t\t\tCreditcard : " << Creditcard << "\n";
    cout << "__________________________________________________________\n";
}

int main(){
    string a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    Information i(a,b,c);
    i.showInformation();
    return 0;

}
