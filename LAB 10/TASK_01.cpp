#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right; 
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
Node* Insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = Insert(root->left, value);
    } else if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    return root;
}

// Function to find the minimum value node in a tree
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node from the BST
Node* Delete(Node* root, int value) {
    if (root == NULL) {
        return root;  // If the tree is empty
    }
    
    if (value < root->data) {
        root->left = Delete(root->left, value);  // Go left if the value is smaller
    } else if (value > root->data) {
        root->right = Delete(root->right, value);  // Go right if the value is larger
    } else {
        // Node found. Now handle the 3 cases.
        
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Node has two children
        else {
            Node* temp = findMin(root->right);  // Find the minimum node in the right subtree
            root->data = temp->data;  // Replace the data with the minimum value from right subtree
            root->right = Delete(root->right, temp->data);  // Delete the duplicate node
        }
    }
    return root;
}

// In-order traversal (left, root, right)
void InOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

// Pre-order traversal (root, left, right)
void PreOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

// Post-order traversal (left, right, root)
void PostOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    PostOrderTraversal(root->left); 
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

// Function to search a value in the BST
bool Search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return Search(root->left, value);
    } else {
        return Search(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    int size = 0;
    int value = 0;
    
    // Insert elements into the BST
    cout << "How many values do you want to insert: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        root = Insert(root, value);
    }
    
    // Display traversals
    cout << "In-order traversal of the BST: ";
    InOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal of the BST: ";
    PreOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal of the BST: ";
    PostOrderTraversal(root);
    cout << endl;
    
    // Search for a value
    int key = 0;
    cout << "Enter the value you want to search: ";
    cin >> key;
    if (Search(root, key)) {
        cout << "The value " << key << " is found." << endl;
    } else {
        cout << "The value " << key << " is not found." << endl;
    }

    // Delete a value from the BST
    int delValue;
    cout << "Enter the value you want to delete: ";
    cin >> delValue;
    root = Delete(root, delValue);
    
    // Display in-order traversal after deletion
    cout << "In-order traversal after deletion: ";
    InOrderTraversal(root);
    cout << endl;

    return 0;
}
