#include <iostream>
#include <string>
#include<bits/stdc++.h>
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

class Visa : public CreditCard {
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
int main() {
    string cardNumber;

    cout << "Enter your credit card number: ";
    cin >> cardNumber;

    CreditCard* creditCard;

    if (cardNumber[0] == '4') {
        creditCard = new Visa(cardNumber);
    } else if (cardNumber.substr(0, 2) == "51" || cardNumber.substr(0, 2) == "52" || cardNumber.substr(0, 2) == "53" || cardNumber.substr(0, 2) == "54" || cardNumber.substr(0, 2) == "55") {
        creditCard = new MasterCard(cardNumber);
    } else {
        cout << "Invalid credit card type" << endl;
        return 1;
    }

    if (creditCard->validate()) {
        cout << "Credit card number is valid" << endl;
    } else {
        cout << "Credit card number is invalid" << endl;
    }

    delete creditCard;

    return 0;
}
