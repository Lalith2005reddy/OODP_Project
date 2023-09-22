#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class CreditCard {
protected:
    string cardNumber;

public:
    CreditCard(string cardNumber) {
        this->cardNumber = cardNumber;
    }

    virtual bool validate() {
        return false;
    }
};

class Visa : public CreditCard {                                   //Inheritance is being implemented Here
public:
    Visa(string cardNumber) : CreditCard(cardNumber) {}

    bool validate() {
        if (cardNumber.length() != 16) {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < 16; i++) {
            int digit = cardNumber[i] - '0';
            if (i % 2 == 0) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
            }
            sum += digit;
        }

        return sum % 10 == 0;
    }
};

class MasterCard : public CreditCard {
public:
    MasterCard(string cardNumber) : CreditCard(cardNumber) {}

    bool validate() {
         if (cardNumber.length() != 16 || cardNumber[0] != '5') {
        return false;
    }

        int sum = 0;
    for (int i = 0; i < 16; i++) {
        int digit = cardNumber[i] - '0';
        if (i % 2 == 0) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
    }
    return (sum % 10 == 0);
}

};
class Image{
    public:
    void image(){
                cout<<"                                       = = = = = = = = = = = = = = = = = ="<<endl;
                cout<<"                                       =                                 ="<<endl;
                cout<<"                                       =                                 ="<<endl;
                cout<<"                                       =          Credit Card            ="<<endl;
                cout<<"                                       =           Validator             ="<<endl;
                cout<<"                                       =                                 ="<<endl;
                cout<<"                                       =                                 ="<<endl;
                cout<<"                                       =                                 ="<<endl;
                cout<<"                                       = = = = = = = = = = = = = = = = = ="<<endl;
    }
};
class CardDetails{
    public:
    int Cvc;
    string name;
    int Expdate_mon,Expdate_year;

    public:

    void getCvc(){
        cout<<"Enter 'Name' On Credit Card: ";
        cin.ignore();
        getline(cin, name);
        bool validcvc=false;
        while(!validcvc){
        cout<<"Enter 3 Digit 'Cvc' Number On Credit Card: ";
        cin>>Cvc;
        if(Cvc>=100 && Cvc<=999){
            validcvc=true;
        }
        else{
                cout << "\033[31m"; // set text color to red
                cout<<"Cvc is invalid"<<endl;
                cout << "\033[0m"; //Reset colour
        }
        }

        bool valid=false;
        while(!valid){
        cout<<"Enter 'Expiry Date' On Credit Card(Month, year): ";
        cin>>Expdate_mon;
        cin>>Expdate_year;
        if(Expdate_mon>=01 && Expdate_mon<=12 && Expdate_year>=2023){
            valid=true;
        }
       else{
                cout << "\033[31m"; // set text color to red
                cout<<"Invalid Expiry Date"<<endl;
                cout<<"Please Enter Valid Expiry Date"<<endl;
                cout << "\033[0m"; //Reset colour
                
        }
        }
    }
};

int main() {

    string cardNumber;
    Image card;//Image Class object creation
    card.image();
    main:
    cout << "Enter your Credit card number: ";
    cin >> cardNumber;

    CardDetails obj;//Credit Card Details input and saving
    obj.getCvc();

    CreditCard* creditCard;

    if (cardNumber[0] == '4') {

        creditCard = new Visa(cardNumber);

    } 
    else if (cardNumber.substr(0, 2) == "51" || cardNumber.substr(0, 2) == "52" || cardNumber.substr(0, 2) == "53" || cardNumber.substr(0, 2) == "54" || cardNumber.substr(0, 2) == "55") {
        
        creditCard = new MasterCard(cardNumber);

    } 
    else {

        cout << "Invalid credit card type" << endl;
        return 1;

    }

    if (creditCard->validate()) {
        cout<<"\n";
        cout<<"Hi! "<<obj.name<<endl;
        cout << "\033[32m"; // set text color to green
        cout << "                                              Your Credit Card Number is valid" << endl;
        cout << "\033[0m"; //Reset colour

    } 
    else {

        cout << "\033[31m"; // set text color to red
        cout << "                                              Your Credit Card Number is invalid" << endl;
        cout << "\033[0m"; // set text to default colour
        try{
            if(cardNumber[0]!=4 && cardNumber[0]!=5){
            }
            else{
                throw runtime_error("Error in Creditcard Number");
            }
        }
        catch(runtime_error &e){
            cerr<<e.what()<<endl;
        }

    }
    char k;
    cout<<"-------------------->>Do you Want to Exit(Y/N):____"<<endl;
    cin>>k;
    if(k=='Y'){
        cout<<"Project Done By";
        cout << "\033[32m"; // set text color to green
        cout<<" Saahil Pradhan";
        cout << "\033[0m"; //Reset colour
        cout<<" And ";
        cout << "\033[32m"; // set text color to green
        cout<<"Lalith Reddy";
        cout << "\033[0m"; //Reset colour
        
    }
    else{
        goto main;//Again runs 
    }

    delete creditCard;//Data is Secured and deleted after execution of program;

    return 0;
}

