
#include <iostream>     // Used for input/output operations
#include <fstream>      // Used for file handling (reading/writing to files)
using namespace std;

// FUNCTION 1: Add a student record to the file
void addStudent() {
    ofstream out("students.txt", ios::app); // Open file in append mode (existing data won't be erased)
    
    int roll;                       // Variable to store roll number
    string name, division, address; // Variables to store student details

    // Take input from user
    cout << "Roll No: "; cin >> roll;              // Input roll number
    cout << "Name: "; cin >> name;                 // Input name
    cout << "Division: "; cin >> division;         // Input division
    cout << "Address: "; cin >> address;           // Input address

    // Write one line of student data to the file
    out << roll << " " << name << " " << division << " " << address << "\n";

    out.close(); // Close the file
}

// FUNCTION 2: Display student details for a given roll number
void displayStudent() {
    ifstream in("students.txt"); // Open the student file in read mode

    int roll, r; // 'roll' is for reading, 'r' is the roll number to search
    string name, division, address;
    bool found = false; // Flag to check if student exists

    cout << "Enter roll to search: "; cin >> r; // Input roll number to search

    // Read each record from file
    while (in >> roll >> name >> division >> address) {
        if (roll == r) { // If roll number matches
            cout << "Found: " << roll << " " << name << " " << division << " " << address << "\n";
            found = true;
        }
    }

    if (!found) cout << "Student not found.\n"; // Display message if not found

    in.close(); // Close file
}

// FUNCTION 3: Delete a student record by roll number
void deleteStudent() {
    ifstream in("students.txt");       // Open original student file
    ofstream temp("temp.txt");         // Open temporary file for writing

    int roll, r;
    string name, division, address;
    bool found = false;

    cout << "Enter roll to delete: "; cin >> r; // Input roll number to delete

    // Read each record
    while (in >> roll >> name >> division >> address) {
        if (roll == r) {
            found = true; // If found, skip writing it (i.e., delete it)
            continue;
        }
        temp << roll << " " << name << " " << division << " " << address << "\n"; // Write non-deleted records
    }

    in.close();       // Close original file
    temp.close();     // Close temp file

    remove("students.txt");             // Delete original file
    rename("temp.txt", "students.txt"); // Rename temp to original name

    if (found) cout << "Deleted.\n";    // Show success message
    else cout << "Student not found.\n"; // If no match, show not found
}

// FUNCTION 4: Show all students' records
void showAllStudents() {
    ifstream in("students.txt"); // Open file to read

    int roll;
    string name, division, address;
    bool empty = true; // To check if file has any data

    cout << "\nAll Student Records:\n";
    cout << "---------------------\n";

    while (in >> roll >> name >> division >> address) {
        // Print each student record
        cout << "Roll No: " << roll << "\n";
        cout << "Name: " << name << "\n";
        cout << "Division: " << division << "\n";
        cout << "Address: " << address << "\n";
        cout << "---------------------\n";
        empty = false; // Found at least one record
    }

    if (empty)
        cout << "No records found.\n"; // Show message if file is empty

    in.close(); // Close the file
}

// MAIN FUNCTION: Menu-driven interface
int main() {
    int ch; // Choice for menu

    do {
        // Show menu options to the user
        cout << "\n1.Add 2.Display 3.Delete 4.Show All 5.Exit\nEnter choice:  ";
        cin >> ch; // Take choice input

        // Call function based on choice
        if (ch == 1) addStudent();         // Add student
        else if (ch == 2) displayStudent(); // Search and display student
        else if (ch == 3) deleteStudent();  // Delete a student
        else if (ch == 4) showAllStudents(); // Show all records
        else if (ch != 5) cout << "Invalid choice. Try again.\n"; // Invalid choice message
    } while (ch != 5); // Keep looping until exit (choice 5)

    return 0; // Exit the program
}