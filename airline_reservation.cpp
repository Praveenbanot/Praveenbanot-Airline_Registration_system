#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

void mainmenu();

class Management {
public:
    Management() {
        mainmenu();
    }
};

class Details {
public:
    static string name, gender;
    int contact_number;
    int Age;
    string add;
    static int customer_ID;

    void Information() {
        cout << "\n Enter The Customer ID: ";
        cin >> customer_ID;
        cout << "\n Enter The Name: ";
        cin >> name;
        cout << "\n Enter The Gender: ";
        cin >> gender;
        cout << "\n Enter The Age: ";
        cin >> Age;
        cout << "\n Enter The Address: ";
        cin >> add;
        cout << "Your Details Are Saved With Us \n" << '\n';
    }
};

int Details::customer_ID;
string Details::name;
string Details::gender;

class Registration {
public:
    static int choice;
    int c1;
    int back;
    static float charges;

    void flights() {
        cout << "\n WELCOME TO THE AIRLINES!\n";
        cout << "1. Flight to Dubai\n";
        cout << "2. Flight to Canada\n";
        cout << "3. Flight to UK\n";
        cout << "4. Flight to Australia\n";
        cout << "5. Flight to Europe\n";
        cout << "Press The Number Of The Country Of Which You Want To Book The Flight: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookFlight("Dubai", 14000, 10000, 12000);
                break;
            case 2:
                bookFlight("Canada", 20000, 15000, 18000);
                break;
            case 3:
                bookFlight("UK", 25000, 22000, 20000);
                break;
            case 4:
                bookFlight("Australia", 30000, 28000, 26000);
                break;
            case 5:
                bookFlight("Europe", 35000, 32000, 30000);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                flights();
                break;
        }
    }

    void bookFlight(string destination, float price1, float price2, float price3) {
        cout << "________________Welcome To " << destination << " Airlines______________\n" << endl;
        cout << "Your Comfort is our Priority. Enjoy The Journey!" << endl;
        cout << "Following Are The Flights \n" << endl;
        cout << "1. " << destination << " - 101 Rs." << price1 << endl;
        cout << "2. " << destination << " - 202 Rs." << price2 << endl;
        cout << "3. " << destination << " - 303 Rs." << price3 << endl;
        cout << "\n Select The Flight You Want To Book: ";
        cin >> c1;

        if (c1 == 1) {
            charges = price1;
        } else if (c1 == 2) {
            charges = price2;
        } else if (c1 == 3) {
            charges = price3;
        } else {
            cout << "Invalid Input, Shifting To The Previous Menu" << endl;
            flights();
            return;
        }
        cout << "\n You Have Successfully Booked The Flight " << destination << " - " << c1 << endl;
        Payment();
    }

    void Payment() {
        int payment_choice;
        string confirmation;
        cout << "\n Select Payment Method:\n";
        cout << "1. Credit/Debit Card\n";
        cout << "2. UPI Payment\n";
        cout << "Choose Payment Option: ";
        cin >> payment_choice;
        
        switch (payment_choice) {
            case 1:
                cout << "\n Enter Card Details...";
                break;
            case 2:
                cout << "\n Enter UPI ID...";
                break;
            default:
                cout << "Invalid payment method. Try again." << endl;
                Payment();
                return;
        }

        cout << "\n Confirm Payment (yes/no): ";
        cin >> confirmation;
        if (confirmation == "yes" || confirmation == "YES") {
            cout << "\n Payment Successful!" << endl;
        } else {
            cout << "\n Payment Cancelled. Please try again." << endl;
            Payment();
            return;
        }
        cout << "Press Any Key To Go Back To The Main Menu: ";
        cin >> back;
        mainmenu();
    }
};

float Registration::charges;
int Registration::choice;

void mainmenu() {
    int choice1;
    int back;

    cout << "\t      XYZ Airlines \n" << '\n';
    cout << "\t__________Main Menu___________" << '\n';
    cout << "\t_________________________" << '\n';
    cout << "\t|\t Press 1 to add the Customer Details  \t|" << '\n';
    cout << "\t|\t Press 2 for Flight Registration    \t|" << '\n';
    cout << "\t|\t Press 3 for Exit                     \t" << "\n";
    cout << "\t______________________________________________" << "\n";

    cout << "Enter The Choice: ";
    cin >> choice1;

    Details d;
    Registration r;

    switch (choice1) {
        case 1:
            cout << "____________Customers____________\n" << '\n';
            d.Information();
            cout << "Press Any Key to go back to the main menu ";
            cin >> back;
            mainmenu();
            break;

        case 2:
            cout << "__________Book A Flight Using This System_____________\n";
            r.flights();
            break;

        case 3:
            cout << "\n\n\t____________Thank YOU_______________" << endl;
            break;

        default:
            cout << "Invalid Input, Please Try Again!\n" << endl;
            mainmenu();
            break;
    }
}

int main() {
    Management mg;
    return 0;
}



