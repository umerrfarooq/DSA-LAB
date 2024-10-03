#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        next = NULL;
        prev = NULL;
        data = value;
    }
};

void InsertAtTail(Node*& head, int value) {
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
    n->prev = temp;
}

void InsertAtHead(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == NULL) {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}

void InsertPosition(Node*& head, int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = head;
    int count = 1;

    if (pos == 1) {
        InsertAtHead(head, value);
        return;
    }

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position is greater than the length of the list. Inserting at the end." << endl;
        InsertAtTail(head, value);
        return;
    }

    Node* n = new Node(value);
    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = n;
    }
    temp->next = n;
}

void DeleteNode(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range. Cannot delete." << endl;
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

void Display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DeleteAllNodes(Node*& head) {
    while (head != NULL) {
        DeleteNode(head, 1);
        Display(head);
    }
}

int main() {
    Node* head = NULL;

    // Test: Insert into an empty list
    cout << "Inserting at tail (list empty initially):" << endl;
    InsertAtTail(head, 10);
    Display(head);

    // Test: Deleting from an empty list
    cout << "Trying to delete from an empty list:" << endl;
    DeleteNode(head, 1);  // List now empty after deletion
    DeleteNode(head, 1);  // Should output "List is empty"

    // Test: Inserting at position greater than the length of the list
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    cout << "Inserting at position greater than the length of the list:" << endl;
    InsertPosition(head, 40, 10);  // Should insert at the end
    Display(head);

    // Test: Deleting all nodes one by one and trying further deletions
    cout << "Deleting all nodes:" << endl;
    DeleteAllNodes(head);
    
    cout << "Trying to delete from an empty list again:" << endl;
    DeleteNode(head, 1);  // Should output "List is empty"

    return 0;
}
