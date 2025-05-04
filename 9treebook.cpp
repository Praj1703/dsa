#include <iostream>     // Required for input and output (cin, cout)
#include <string>       // Required for using the string data type

using namespace std;    // To avoid writing std:: before every standard function

// Define a structure for each Node in the tree (Book, Chapter, Section)
struct Node {
    string label;       // Name of the node (Book title / Chapter name / Section name)
    int ch_count;       // Number of child nodes (Chapters or Sections)
    Node* child[10];    // Fixed-size array to store pointers to child nodes (up to 10)

    Node() : ch_count(0) { // Constructor to initialize the node
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr;  // Initialize all child pointers to null
        }
    }
};

// Define the Generic Tree (GT) class
class GT {
public:
    Node* root;         // Pointer to the root node (book)

    GT() {              // Constructor to initialize root as null
        root = nullptr;
    }

    void create_tree();             // Method to build the tree
    void display(Node* r1);         // Method to display the tree
};

// Function to build the book tree by taking user input
void GT::create_tree() {
    int tchapters;

    root = new Node;     // Create the root node (the Book)
    cout << "Enter name of book: ";
    cin.ignore();        // Clear any newline left in buffer
    getline(cin, root->label);    // Read full book name with spaces
    
    cout << "Enter number of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;   // Set number of chapters

    for (int i = 0; i < tchapters; i++) {
        root->child[i] = new Node;   // Create node for chapter
        cout << "Enter the name of Chapter " << (i + 1) << ": ";
        cin.ignore();                // Clear buffer
        getline(cin, root->child[i]->label); // Input chapter name

        cout << "Enter number of sections in Chapter " << (i + 1) << ": ";
        cin >> root->child[i]->ch_count;

        // Add sections under each chapter
        for (int j = 0; j < root->child[i]->ch_count; j++) {
            root->child[i]->child[j] = new Node;  // Create section node
            cout << "Enter name of Section " << (j + 1) << ": ";
            cin.ignore();                         // Clear buffer
            getline(cin, root->child[i]->child[j]->label); // Input section name
        }
    }
}

// Function to display the book tree
void GT::display(Node* r1) {
    if (r1 == nullptr) return; // If tree is empty, exit function

    // Display root node (book title)
    cout << "Book: " << r1->label << endl;

    // Loop through all chapters
    for (int i = 0; i < r1->ch_count; i++) {
        cout << "  Chapter " << (i + 1) << ": " << r1->child[i]->label << endl;

        // Loop through sections of each chapter
        for (int j = 0; j < r1->child[i]->ch_count; j++) {
            cout << "    Section " << (j + 1) << ": " << r1->child[i]->child[j]->label << endl;
        }
    }
}

// Main function - menu driven interface
int main() {
    GT gt;       // Create an object of GT class
    int choice;

    while (true) {
        // Display menu
        cout << "x----------------------x" << endl;
        cout << "|  BOOK TREE CREATION  |" << endl;
        cout << "x----------------------x\n" << endl;
        cout << "   1. Insert" << endl;
        cout << "   2. Display" << endl;
        cout << "   3. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        cout << "*************************" << endl;

        // Handle user choices
        switch (choice) {
            case 1:
                gt.create_tree();             // Build the tree
                cout << "*************************" << endl;
                break;
            case 2:
                gt.display(gt.root);          // Display the tree
                cout << "*************************" << endl;
                break;
            case 3:
                cout << "Thanks for using this program!" << endl;
                cout << "*************************" << endl;
                return 0;                     // Exit the program
            default:
                cout << "Wrong choice!!!" << endl;
                cout << "*************************" << endl;
        }
    }

    return 0;
}
