// Author : Imam Fauji Sugiarta

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;
int ID;
string Name = "Imam Fauji Sugiarta";
class Bank {

    //struct Person {
    //    int id;
    //    string Name;
    //    int age;
    //    string address;
    //};
private:
    string name;
    string pin;
    long long accnumber;
    char type[10];
    long long amount = 0;
    long long tot = 0;

public:

    void login() {
        system("cls");
        int attempt;
        bool bSuccess = false;
        for (attempt = 0; attempt <= 3; attempt++) {
            cout << "\n Attempt : " << attempt << endl;
            cout << "\n Enter Name : " << Name;
            //cin.ignore(); // Clear the input buffer
            //getline(cin, name); // For void too much overbuffered
            //cin >> name;
            cout << "\n Enter Pin : " << flush;
            cin >> pin;
                if (pin == "672021039") {
                    bSuccess = true;
                    break;
                }
                else {
                    cout << "\n Your name and Pin is Wrong! Please Try Again!\n";
                    system("pause>nul");
                    system("cls");
                }
            }
        if (bSuccess) {
            cout << "\n Login Success! [Press any key to continue]\n";
            system("pause>nul");
        }
        else if (attempt > 3) {
            cout << "\n Too many attempt, your account has been suspended";
            cout << "\n Please Try, Contact Admin for Restore your Account \n\n";
            system("pause>nul");
            exit(0);
        }
    }


    void setvalue() {

        system("cls");
        cout << "\n Enter Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "\n Enter Account Number : ";
        cin >> accnumber;
        cout << "\n Enter Account Type : ";
        cin >> type;
        cout << "\n Enter First Balance : ";
        cin >> tot;
        ID++;

        ofstream write;
        write.open("person.txt", ios::app);
        write << "ID : " << ID << "\n";
        write << "Name : " << name << "\n";
        write << "Account Number : " << accnumber << "\n";
        write << "Bank Platform : " << type << "\n";
        write << "Balance Amount : " << tot << "\n";
        write.close();
        cout << "\n Adding Data Success! \n";
        cout << "\n Press any key to enter menu... \n";
        system("pause>nul");
        system("cls");
        return;
    }


    void showdata() {

        cout << "Name : " << name << endl;
        cout << "Account No : " << accnumber << endl;
        cout << "Account Type : " << type << endl;
        cout << "Balance : " << tot << endl;
        system("pause");
        system("cls");
        return;
    }
    void deposit() {
        system("cls");
        char withdraw_decision;
        long long deposit_amount;
        cout << "\n Enter Amount to be Deposited : ";
        cin >> deposit_amount;
        cout << "\n Are you sure for Deposited to " << name << " With " << deposit_amount << " Cash? (y/n) : ";
        cin >> withdraw_decision;
        if (withdraw_decision == 'y') {
            tot += deposit_amount; // Update the total balance by adding the deposited amount
            cout << "\n Deposit Success! [Press any key to back menu]\n";
            system("pause>nul");
        }
        else if (withdraw_decision == 'n') {
            deposit();
        }
        else {
            cout << "\n Please pick (y/n)!\n";
        }
        cout << endl;
        return;
    }

    //void showbal() {
    //    system("cls");
    //    cout << "Total Balance is : " << tot << endl << endl;
    //    system("pause");
    //    system("cls");
    //    return;
    //}

    void withdraw() {

        int withdraw_amount;

        cout << "\n Enter Amount to Withdraw: ";
        cin >> withdraw_amount;

        if (withdraw_amount > tot) {
            cout << "Insufficient balance!" << endl;
        }
        else {
            tot -= withdraw_amount;
            cout << "Withdrawn: " << withdraw_amount << endl;
            cout << "Available Balance is : " << tot << endl;
        }

        cout << endl;
        system("pause");
        system("cls");
        return;
    }

};

void showmainmenu() {
    system("color 17");
    cout << "\t\t\t ----------------------------\n\n" << endl;
    cout << "\t\t\t -    WELCOME BRI TO ATM    -\n\n" << endl;
    cout << "\t\t\t ----------------------------\n\n" << endl;

    cout << "\n\t\t\t   Please INSERT your Card \n\t\t\t [Press ENTER to insert card]" << endl << endl;
    system("pause>nul");
    system("cls");
    return;
};


int main()
{
    showmainmenu();

    Bank b;
    struct Person;

    b.login();

    int choice;
    system("color 17");
    system("cls");

    do {
        cout << "\t\t\t ----------------------------\n\n" << endl;
        cout << "\t\t\t -    WELCOME BRI TO ATM    -\n\n" << endl;
        cout << "\t\t\t ----------------------------\n\n\n" << endl;
        cout << "\t\t\t Username : "<< Name << endl << endl;
        cout << "1. Checking Balance and Withdraw" << endl;
        cout << "2. Deposit Cash" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << "\n ----------------------------\n\n" << endl;
            cout << "\n -    WELCOME BRI TO ATM    -\n\n" << endl;
            cout << "\n ----------------------------\n\n\n" << endl;
            cout << "1. Checking Balance" << endl;
            cout << "2. Withdraw Cash" << endl;
            cout << "\n Enter Choice : ";
            cin >> choice;
            if (choice == 1) {
                cout << "\n Check Balance Info" << endl;
                b.showdata();
            }
            else if (choice == 2) {
                cout << "\n Withdraw Amount" << endl;
                b.withdraw();
            }
            else {
                cout << "\n Your Choice is not available! Please choose right!" << endl;
            }
            break;

        case 2:
            cout << "\n Deposit Money" << endl;
            b.deposit();
            break;

        case 3:
            exit(0);
            break;
        default:
            cout << "\nInvalid Input!\n";
            system("pause");
            system("cls");
            main();
        }

    } while (choice != 6);
    return 0;


}
