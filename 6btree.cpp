#include <iostream>
#include <string>
#include <algorithm>  // Include for std::max
#include <limits>     // Include for numeric_limits
using namespace std;

struct Node {
    string keyword, meaning;
    Node* left;
    Node* right;
    int height;

    Node(string key, string mean) {
        keyword = key;
        meaning = mean;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* N) {
    return N ? N->height : 0;
}

int getBalance(Node* N) {
    return N ? height(N->left) - height(N->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, string key, string meaning) {
    if (!node)
        return new Node(key, meaning);

    if (key < node->keyword)
        node->left = insert(node->left, key, meaning);
    else if (key > node->keyword)
        node->right = insert(node->right, key, meaning);
    else {
        cout << "Keyword already exists, updating meaning.\n";
        node->meaning = meaning;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->keyword)
        return rightRotate(node);
    if (balance < -1 && key > node->right->keyword)
        return leftRotate(node);
    if (balance > 1 && key > node->left->keyword) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->keyword) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, string key) {
    if (!root) return root;

    if (key < root->keyword)
        root->left = deleteNode(root->left, key);
    else if (key > root->keyword)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->keyword << ": " << root->meaning << endl;
        inorder(root->right);
    }
}

void reverseInorder(Node* root) {
    if (root) {
        reverseInorder(root->right);
        cout << root->keyword << ": " << root->meaning << endl;
        reverseInorder(root->left);
    }
}

bool search(Node* root, string key, int& comparisons) {
    comparisons++;
    if (!root) return false;
    if (key == root->keyword) return true;
    if (key < root->keyword)
        return search(root->left, key, comparisons);
    else
        return search(root->right, key, comparisons);
}

int main() {
    Node* root = nullptr;
    int choice;
    string keyword, meaning;

    do {
        cout << "\n1. Add/Update Keyword\n2. Delete Keyword\n3. Display Ascending\n4. Display Descending\n5. Search Keyword\n6. Exit\nEnter choice: ";
        
        // Handling non-integer input for the menu
        while (!(cin >> choice)) {
            cin.clear();  // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore last input
            cout << "Invalid input! Please enter a valid choice (1-6): ";
        }

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cin.ignore();  // Ignore the newline character left in the buffer
                cout << "Enter meaning: ";
                getline(cin, meaning);
                root = insert(root, keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = deleteNode(root, keyword);
                break;
            case 3:
                cout << "\nDictionary (Ascending Order):\n";
                inorder(root);
                break;
            case 4:
                cout << "\nDictionary (Descending Order):\n";
                reverseInorder(root);
                break;
            case 5: {
                int comparisons = 0;
                cout << "Enter keyword to search: ";
                cin >> keyword;
                if (search(root, keyword, comparisons))
                    cout << "Keyword found with " << comparisons << " comparisons.\n";
                else
                    cout << "Keyword not found. Comparisons made: " << comparisons << endl;
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
