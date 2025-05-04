#include<iostream>
using namespace std;
 
class BTT {
private:
    struct node {
        int data;
        node* lc;  // left child pointer
        node* rc;  // right child pointer
        int lflag; // 0: not a thread, 1: is a thread
        int rflag; // 0: not a thread, 1: is a thread
    } *root, *header;
 
public:
    BTT() {
        root = NULL;
        header = new node;
        header->lc = header;
        header->rc = header;
        header->lflag = 0;
        header->rflag = 0;
    }
 
    void create();
    void preorder();
    void inorder();
    void postorder();
    void display();
};
 
// Function to create the threaded binary tree
void BTT::create() {
    node* curr;
    node* temp;
    int ans;
    do {
        temp = new node;
        temp->lflag = 0;
        temp->rflag = 0;
        cout << "Enter Data: ";
        cin >> temp->data;
 
        if (root == NULL) {
            root = temp;
            root->lc = header;
            root->rc = header;
        } else {
            curr = root;
            while (true) {
                if (temp->data < curr->data) {
                    if (curr->lflag == 0) {
                        temp->lc = curr->lc;
                        temp->rc = curr;
                        curr->lc = temp;
                        curr->lflag = 1;
                        break;
                    }
                    curr = curr->lc;
                } else if (temp->data > curr->data) {
                    if (curr->rflag == 0) {
                        temp->rc = curr->rc;
                        temp->lc = curr;
                        curr->rc = temp;
                        curr->rflag = 1;
                        break;
                    } else {
                        curr = curr->rc;
                    }
                }
            }
        }
        cout << "Do you want to add more nodes? (1 for YES, 2 for NO): ";
        cin >> ans;
    } while (ans == 1);
}
 
// Preorder traversal
void BTT::preorder() {
    if (root == NULL) {
        cout << "BTT is empty\n";
        return;
    } else {
        node* t = root;
        while (t != header) {
            cout << "\t" << t->data;
            if (t->lflag == 1) {
                t = t->lc;
            } else {
                while (t->rflag == 0) {
                    t = t->rc;
                    if (t == header)
                        break;
                }
                t = t->rc;
            }
        }
    }
}
 
// Inorder traversal
void BTT::inorder() {
    if (root == NULL) {
        cout << "BTT is empty\n";
        return;
    } else {
        node* t = root;
        while (t != header) {
            if (t->lflag == 1) {
                t = t->lc;
            } else {
                cout << "\t" << t->data;
                while (t->rflag == 0) {
                    t = t->rc;
                    if (t == header)
                        break;
                }
                t = t->rc;
            }
        }
    }
}
 
// Postorder traversal
void BTT::postorder() {
    if (root == NULL) {
        cout << "BTT is empty\n";
        return;
    } else {
        node* t = root;
        while (t != header) {
            if (t->lflag == 1) {
                t = t->lc;
            } else {
                while (t->rflag == 0) {
                    t = t->rc;
                    cout << "\t" << t->data;
                    if (t == header)
                        break;
                }
                t = t->rc;
            }
        }
    }
}
 
// Function to display the binary tree
void BTT::display() {
    if (root == NULL) {
        cout << "BTT is empty\n";
        return;
    } else {
        node* t = root;
        cout << "Displaying tree elements in Inorder: ";
        while (t != header) {
            if (t->lflag == 1) {
                t = t->lc;
            } else {
                cout << t->data << " ";
                while (t->rflag == 0) {
                    t = t->rc;
                    if (t == header)
                        break;
                }
                t = t->rc;
            }
        }
        cout << endl;
    }
}
 
int main() {
    BTT a;
    a.create();     // Create the tree
    cout << "Preorder traversal: ";
    a.preorder();   // Preorder traversal
    cout << "\nInorder traversal: ";
    a.inorder();    // Inorder traversal
    cout << "\nPostorder traversal: ";
    a.postorder();  // Postorder traversal
    cout << "\nDisplay tree: ";
    a.display();    // Display the tree
    return 0;
}