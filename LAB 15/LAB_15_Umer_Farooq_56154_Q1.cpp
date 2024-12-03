#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a node at the tail
void insertAtTail(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to delete a node by value
void DeleteNode(Node*& head, int key) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == key) {
        Node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Key not found!" << endl;
        return;
    }

    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

// Function to search for a node by value
bool SearchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to display the linked list
void Display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int value;

    // Create a linked list with 5 nodes
    for (int i = 0; i < 5; i++) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    cout << "Linked List: ";
    Display(head);

    // Search operation
    int searchKey;
    cout << "Enter the value to search: ";
    cin >> searchKey;
    if (SearchNode(head, searchKey)) {
        cout << "Value " << searchKey << " found in the list." << endl;
    } else {
        cout << "Value " << searchKey << " not found in the list." << endl;
    }

    // Deletion operation
    int deleteKey;
    cout << "Enter the value to delete: ";
    cin >> deleteKey;
    DeleteNode(head, deleteKey);
    cout << "Linked List after deletion: ";
    Display(head);

    system("pause");

    return 0;
}
