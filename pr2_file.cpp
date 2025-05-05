// Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular employee. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to main the data.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student {
    public:
        int roll;
        string name;
        string division;
        string address;

        void addStudent() {
            ofstream file("students.txt", ios::app);
            cout << "\nEnter Roll Number: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Division: ";
            getline(cin, division);
            cout << "Enter Address: ";
            getline(cin, address);
        
            file << roll << "," << name << "," << division << "," << address << "\n";
            file.close();
            cout << "Student added successfully!\n";
        }
        
        void displayStudent(int r) {
            ifstream file("students.txt");
            string line;
            bool found = false;
        
            while (getline(file, line)) {
                int pos1 = line.find(',');
                int pos2 = line.find(',', pos1 + 1);
                int pos3 = line.find(',', pos2 + 1);
        
                roll = stoi(line.substr(0, pos1));
                name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                division = line.substr(pos2 + 1, pos3 - pos2 - 1);
                address = line.substr(pos3 + 1);
        
                if (r == roll) {
                    cout << "\nStudent Found:\n";
                    cout << "Roll No: " << roll << "\n";
                    cout << "Name: " << name << "\n";
                    cout << "Division: " << division << "\n";
                    cout << "Address: " << address << "\n";
                    found = true;
                    break;
                }
            }
        
            if (!found)
                cout << "Student with roll number " << roll << " not found.\n";
        
            file.close();
        }
        
        void deleteStudent(int r) {
            ifstream file("students.txt");
            ofstream temp("temp.txt");
            string line;
            bool deleted = false;
        
            while (getline(file, line)) {
                int pos1 = line.find(',');
                int pos2 = line.find(',', pos1 + 1);
                int pos3 = line.find(',', pos2 + 1);
        
                roll = stoi(line.substr(0, pos1));
                name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                division = line.substr(pos2 + 1, pos3 - pos2 - 1);
                address = line.substr(pos3 + 1);
        
                if (r == roll) {
                    deleted = true;
                } else {
                    temp << line << "\n";
                }
            }
        
            file.close();
            temp.close();
        
            remove("students.txt");
            rename("temp.txt", "students.txt");
        
            if (deleted)
                cout << "Student deleted successfully.\n";
            else
                cout << "Student with roll number " << r << " not found.\n";
        }


};

int main() {
    int choice, roll;
    Student s;

    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.addStudent();
                break;
            case 2:
                cout << "Enter Roll No to Delete: ";
                cin >> roll;
                s.deleteStudent(roll);
                break;
            case 3:
                cout << "Enter Roll No to Search: ";
                cin >> roll;
                s.displayStudent(roll);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
