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

// Function to reverse the linked list
void Reverse(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
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

    cout << "Original Linked List: ";
    Display(head);

    // Reverse the linked list
    cout << "Reversing the linked list..." << endl;
    Reverse(head);
    cout << "Reversed Linked List: ";
    Display(head);

    system("pause");

    return 0;
}
