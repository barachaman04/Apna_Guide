#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

class Student {
private:
    string RollNo, Name, Grade;
public:
    Student() : RollNo(""), Name(""), Grade("") {}

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }
    void setName(string name) {
        Name = name;
    }
    void setGrade(string grade) {
        Grade = grade;
    }

    string getRollNo() {
        return RollNo;
    }
    string getName() {
        return Name;
    }
    string getGrade() {
        return Grade;
    }
};

int main() {
    Student s;
    bool exit = false;
    while (!exit) {
        system("cls");

        int val;
        cout << "\tWelcome To Student Report Card System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Report Card" << endl;
        cout << "\t2. Exit" << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            string rollNo, name;
            cout << "\tEnter Roll of Student: ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cout << "\tEnter Name Of Student: ";
            cin.ignore();
            getline(cin, name);
            s.setName(name);

            int physics, computer, math, total;
            double avg;
            cout << "\tEnter Physics Marks: ";
            cin >> physics;
            cout << "\tEnter Computer Marks: ";
            cin >> computer;
            cout << "\tEnter Math Marks: ";
            cin >> math;

            system("cls");

            cout << "\tStudent Report Card" << endl;
            cout << "\t********************" << endl;
            total = physics + computer + math;
            cout << "\tTotal Marks Of Student: " << total << endl;
            avg = static_cast<double>(total) / 3.0;
            cout << "\tAverage Marks Of Student: " << avg << endl;

            if (avg >= 90 && avg <= 100) {
                s.setGrade("A+");
            } else if (avg >= 80 && avg < 90) {
                s.setGrade("B");
            } else if (avg >= 70 && avg < 80) {
                s.setGrade("C");
            } else if (avg >= 60 && avg < 70) {
                s.setGrade("D");
            } else if (avg >= 0 && avg < 60) {
                s.setGrade("F");
            }
            cout << "\tGrade Of Student: " << s.getGrade() << endl;

            ofstream out("Student.txt", ios::app);
            out << "\t" << s.getRollNo() << " : " << s.getName() << " : " << s.getGrade() << endl << endl;
            out.close();
            cout << "\tStudent Report Card Saved Successfully" << endl;

            this_thread::sleep_for(chrono::milliseconds(10000));
        }
        else if (val == 2) {
            system("cls");
            exit = true;
            cout << "\tThank You For Using This Program!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
        }
    }
    return 0;
}