#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void InsertAtTail(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
}

void Display(Node*& head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}
void InsertAtHead(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
    }
}
int main() {
    Node* head = NULL;

    InsertAtTail(head, 10);
    Display(head);

    InsertAtTail(head, 20);
    Display(head);

    InsertAtTail(head, 30);
    Display(head);

    InsertAtHead(head, 5);
    Display(head);

   

    return 0;
}
