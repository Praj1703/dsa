#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* GetNewNode(int in_data) {
    Node* ptr = new Node();
    ptr->data = in_data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

Node* insert(Node* temp, int in_data) {
    if(temp == NULL) {
        return GetNewNode(in_data);
    }
    else if (in_data < temp->data) {
        temp->left = insert(temp->left, in_data);
    }
    else {
        temp->right = insert(temp->right, in_data);
    }
    return temp;
}

Node* min(Node* temp) {
    if(temp == NULL) {
        cout << "No element found." << endl;
        return NULL;
    }
    while(temp->left != NULL) {
        temp = temp->left;
    }
    cout << "Min value: " << temp->data << endl;
    return temp;
}
Node* max(Node* temp) {
    if(temp == NULL) {
        cout << "Element not found." << endl;
        return NULL;
    }
    while(temp->right != NULL) {
        temp = temp->right;
    }
    cout << "Max value: " << temp->data << endl;
    return temp;
}

Node* search(Node* temp, int data) {
    if(temp == NULL) {
        return NULL;  // Not found
    }
    if(temp->data == data) {
        return temp;  // Found
    }
   
    if(data < temp->data) {
        return search(temp->left, data);
    } else {
        return search(temp->right, data);  // Search in the right subtree
    }
}

int len(Node* temp) {
    if (temp == NULL) {
        return 0;
    }
    int leftLength = len(temp->left);
    int rightLength = len(temp->right);
    return max(leftLength, rightLength) + 1;
}

void swap(Node* temp) {
    if (temp == NULL) {
        return;
    }

    Node* tempNode = temp->left;
    temp->left = temp->right;
    temp->right = tempNode;

    // Recursively swap the left and right subtrees
    swap(temp->left);
    swap(temp->right);
}

void display(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root !=NULL){
    display(root->left);   // Traverse left subtree
    cout << root->data << " ";  // Visit the node
    display(root->right);  // Traverse right subtree
}

}

int main() {
    Node* root = NULL;
    int choice, data;
   
    cout << "Enter the number of nodes to insert: ";
    int n;
    cin >> n;

    cout << "Enter the values to insert into the tree:\n";
    for(int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    do {
        cout << "\nMenu: ";
        cout << "\n1. Insert data into the tree";
        cout << "\n2. Search for a value";
        cout << "\n3. Find minimum value";
        cout << "\n4. Find maximum value";
        cout << "\n5. Find the length of the tree";
        cout << "\n6. Display the tree";
        cout << "\n7. Swap left and right subtrees of the tree";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
       
        switch(choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                root = insert(root, data);
                cout << "New node with value " << data << " inserted." << endl;
                break;
            case 2:
                cout << "Enter a value to search in the tree: ";
                cin >> data;
                if(search(root, data) != NULL) {
                    cout << "Value " << data << " found in the tree." << endl;
                } else {
                    cout << "Value " << data << " not found in the tree." << endl;
                }
                break;
            case 3:
                min(root);
                break;
            case 4:
                max(root);
                break;
            case 5:
                cout << "Number of nodes in the longest path (height) from the root: " << len(root) << endl;
                break;
            case 6:
                cout << "Displaying tree in in-order: ";
                display(root);
                cout << endl;
                break;
            case 7:
                cout << "Tree before swapping: ";
                display(root);
                cout << endl;

                swap(root); 

                cout << "Tree after swapping: ";
                display(root);
                cout << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 8);
   
    return 0;
}