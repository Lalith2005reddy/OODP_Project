#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isMastercard(const std::string& cardNumber) {
    // Check if the card number starts with 5 and has 16 digits
    if (cardNumber.length() != 16 || cardNumber[0] != '5') {
        return false;
    }
    
    // Apply the Luhn algorithm to validate the card number
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

int main() {
    string cardNumber;
    cout << "Enter a Mastercard credit card number: ";
    cin >> cardNumber;
    string formattedCardNumber = cardNumber;
    formattedCardNumber.erase(remove(formattedCardNumber.begin(), formattedCardNumber.end(), ' '), formattedCardNumber.end()); // remove spaces
    if (isMastercard(formattedCardNumber)) {
        cout << "Valid Mastercard credit card number." << std::endl;
    } else {
        cout << "Invalid Mastercard credit card number." << std::endl;
    }
    return 0;
}
