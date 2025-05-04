#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int emp_Id;
    char name[50];
    char department[30];
    bool isActive;
};

//data should noyt exceed more than ten entries therfore defining the table size as 10
const int TABLE_SIZE = 10;

//here making variable to store the name of the file to reuse it
const char* FILENAME = "records.dat";



// These are the finctions need to define 

/*void insertData();
void deleteData();
void displayTable();
void searchData();
*/

void insertData() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    int emp_Id;
    cout << "Enter emp_Id: ";
    cin >> emp_Id;
    if (emp_Id < 1 || emp_Id > TABLE_SIZE) {
        cout << "Invalid emp_Id.\n";
        return;
    }

    Student record;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(record.name, 50);
    cout << "Enter Department: ";
    cin.getline(record.department, 30);
    record.emp_Id = emp_Id;
    record.isActive = true;

    long position = (emp_Id - 1) * sizeof(Student);
    file.seekp(position);
    file.write(reinterpret_cast<const char*>(&record), sizeof(Student));
    cout << "Record inserted successfully.\n";

    file.close();
}

void deleteData() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    int emp_Id;
    cout << "Enter emp_Id to delete: ";
    cin >> emp_Id;
    if (emp_Id < 1 || emp_Id > TABLE_SIZE) {
        cout << "Invalid emp_Id.\n";
        return;
    }

    Student record = {0, "", "", false};
    long position = (emp_Id - 1) * sizeof(Student);
    file.seekp(position);
    file.write(reinterpret_cast<const char*>(&record), sizeof(Student));
    cout << "Record deleted successfully.\n";

    file.close();
}

void displayTable() {
    fstream file(FILENAME, ios::in | ios::binary);
    Student record;
    bool dataExists = false;
    cout << "\n--- Inserted Student Records ---\n";
    cout << "emp_Id\tName\t\tDepartment\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        file.seekg(i * sizeof(Student));
        file.read(reinterpret_cast<char*>(&record), sizeof(Student));
        if (record.isActive) {
            cout << record.emp_Id << "\t" << record.name << "\t" << record.department << "\n";
            dataExists = true;
        }
    }

    if (!dataExists) cout << "No records available.\n";
    file.close();
}

void searchData() {
    fstream file(FILENAME, ios::in | ios::binary);
    int emp_Id;
    cout << "Enter emp_Id to search: ";
    cin >> emp_Id;
    if (emp_Id < 1 || emp_Id > TABLE_SIZE) {
        cout << "Invalid emp_Id.\n";
        return;
    }

    Student record;
    long position = (emp_Id - 1) * sizeof(Student);
    file.seekg(position);
    file.read(reinterpret_cast<char*>(&record), sizeof(Student));

    if (record.isActive)
        cout << "\n--- Record Found ---\nemp_Id: " << record.emp_Id << "\nName: " << record.name << "\nDepartment: " << record.department << "\n";
    else
        cout << "Record not found.\n";

    file.close();
} 	



int main() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    if (!file) {
        file.open(FILENAME, ios::out | ios::binary);
        Student emptyRecord = {0, "", "", false};
        for (int i = 0; i < TABLE_SIZE; i++)
            file.write(reinterpret_cast<const char*>(&emptyRecord), sizeof(Student));
        file.close();
        file.open(FILENAME, ios::in | ios::out | ios::binary);
    }

    int choice;
    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "Select an operation:\n";
        cout << "1. Insert Data\n";
        cout << "2. Delete Data\n";
        cout << "3. Display Inserted Data\n";
        cout << "4. Search Data by emp_Id\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertData();
            	break;
            case 2: deleteData(); 
            	break;         
            case 3: displayTable(); break;
            case 4: searchData(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    file.close();
    return 0;
}