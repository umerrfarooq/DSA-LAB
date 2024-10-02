#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        next = NULL;
        this->data = data;
    }
};

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

void insertAtHead(Node*& head, int value) {
    Node* n = new Node(value);
    n->next = head;
    head = n;
}

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
    int value = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    cout << "List: ";
    Display(head);

    int search = 0;
    cout << "Enter the value you want to search: ";
    cin >> search;
    if (SearchNode(head, search)) {
        cout << "Value " << search << " found in the list." << endl;
    }
    else {
        cout << "Value " << search << " not found in the list." << endl;
    }

    int del = 0;
    cout << "Enter the value you want to delete: ";
    cin >> del;
    DeleteNode(head, del);

    cout << "List after deletion: ";
    Display(head);

    return 0;
}
