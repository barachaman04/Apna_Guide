#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Account {
private:
    string accountNo, password;
    int balance;
public:
    Account() : accountNo(""), password(""), balance(0) {}

    void setAccountNo(string id) {
        accountNo = id;
    }

    void setPassword(string pw) {
        password = pw;
    }

    void setBalance(int balance) {
        this->balance = balance;
    }

    string getAccountNo() {
        return accountNo;
    }

    string getPassword() {
        return password;
    }

    int getBalance() {
        return balance;
    }

    void openAccount();
    void addCash();
    void withdraw();
};

void Account::openAccount() {
    system("cls");
    string id, pw;

    cout << "\tEnter Account No: ";
    cin >> id;
    setAccountNo(id);

    cout << "\tEnter A Strong Password: ";
    cin >> pw;
    setPassword(pw);

    setBalance(0);

    ofstream outfile("Account.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        outfile << "\t" << getAccountNo() << " : " << getPassword() << " : " << getBalance() << endl << endl;
        cout << "\tAccount Created Successfully!" << endl;
    }
    outfile.close();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

void Account::addCash() {
    system("cls");
    string id;
    cout << "\tEnter Account No: ";
    cin >> id;
    ifstream infile("Account.txt");
    ofstream outfile("Account_Temp.txt");

    if (!infile || !outfile) {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;
        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;
        if (id == userID) {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;
            if (cin.fail()) {
                cout << "\tInvalid input. Please enter a valid number." << endl;
                return;
            }
            int newBalance = userBalance + cash;
            userBalance = newBalance;
            outfile << "\t" << userID << " : " << userPW << " : " << userBalance << endl;
            cout << "\tNew Balance Is: " << userBalance << endl;
        } else {
            outfile << line << endl;
        }
    }
    if (!found) {
        cout << "\tEnter Valid Account No!" << endl;
    }

    outfile.close();
    infile.close();
    remove("Account.txt");
    rename("Account_Temp.txt", "Account.txt");

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

void Account::withdraw() {
    system("cls");
    string id, pw;
    cout << "\tEnter Account No: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;
    ifstream infile("Account.txt");
ofstream outfile("Account_Temp.txt");
    if (!infile ||!outfile) {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }
    string line;
    bool found = false;
    while (getline(infile, line)) {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;
        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;
        if (id == userID && pw == userPW) {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;
            if (cin.fail()) {
                cout << "\tInvalid input. Please enter a valid number." << endl;
                return;
            }
            if (cash <= userBalance) {
                int newBalance = userBalance - cash;
                userBalance = newBalance;
                outfile << "\t" << userID << " : " << userPW << " : " << userBalance << endl;
                cout << "\tTransaction Was Successful!" << endl;
                cout << "\tRemaining Balance: " << userBalance << endl;
            } else {
                cout << "\tLow Balance!" << endl;
                outfile << line << endl;  // Write the original line if withdrawal fails
            }
        } else {
            outfile << line << endl;  // Write the original line for non-matching accounts
        }
    }
    if (!found) {
        cout << "\tInvalid Account No or Password!" << endl;
    }
    infile.close();
    outfile.close();
    remove("Account.txt");
    rename("Account_Temp.txt", "Account.txt");

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

int main() {
    Account user;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome to Bank Account Management System" << endl;
        cout << "\t*********************************************" << endl;
        cout << "\t1. Open New Account." << endl;
        cout << "\t2. Add Cash." << endl;
        cout << "\t3. Withdraw Cash." << endl;
        cout << "\t4. Exit." << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        if (val == 1) {
            user.openAccount();
        } else if (val == 2) {
            user.addCash();
        } else if (val == 3) {
            user.withdraw();
        } else if (val == 4) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        } else {
            cout << "\tInvalid choice. Please choose a valid option." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }

    return 0;
}