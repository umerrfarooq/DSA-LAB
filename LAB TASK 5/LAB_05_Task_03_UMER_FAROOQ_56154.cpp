#include <iostream>
using namespace std;

class Node {
public:
   int data;
   Node* next;
   Node(int value) {
       data = value;
       next = NULL;
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

void displayNodes(Node* head) {
   if (head == NULL) {
       cout << "List is Empty" << endl;
           return;
   }

   Node* temp = head;
   while (temp != NULL) {
       cout << temp->data << " -> ";
       temp = temp->next;
   }
   cout << "NULL" << endl;
}

void findMiddle(Node* head) {
   if (head == NULL) {
       cout << "List is empty" << endl;
       return;
   }

   Node* slow = head;
   Node* fast = head;

    
   while (fast != NULL && fast->next != NULL) {
       slow =
           slow->next;
       fast = fast->next->next;
   }

   cout << "Middle of the Linked List: " << slow->data << endl;
}

int main() {
   Node* head = NULL;
   insertAtTail(head, 10);
   insertAtTail(head, 20);
   insertAtTail(head, 30);
   insertAtTail(head, 40);
   insertAtTail(head, 50);
   insertAtTail(head, 60);
   insertAtTail(head, 70);
   insertAtTail(head, 80);
   insertAtTail(head, 90);
   insertAtTail(head, 100);
   insertAtTail(head, 110);
   insertAtTail(head, 120);

   cout << "Linked List: ";
   displayNodes(head);

   findMiddle(head);

   return 0;
}