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

// Function to find the middle of the linked list using two-pointer approach
void FindMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL) {
        cout << "The middle element is: " << slow->data << endl;
    }
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

    // Find the middle of the linked list
    FindMiddle(head);

    system("pause");

    return 0;
}