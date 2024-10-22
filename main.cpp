#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    
    Node(int value) {
        data = value;
    }
};

void InsertAtTail(Node*& head, int value){
Node * n = new Node (value);
if (head == NULL)
{
    head = n;
    n->next = head;

}
Node * temp = head;
while (temp->next != head)
{
    temp = temp->next;
}
temp->next = n;
n->next = head;
}
void InsertAtHead(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == NULL) {
        head = n;
        n->next = head;  // Point to itself since it's the only node
    } else {
        Node* temp = head;
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        // Adjust pointers for circular linking
        temp->next = n;
        n->next = head;
        head = n;  // Update head to the new node
    }
}

void Display(Node*& head)
{
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}
void Position(Node* & head,int value,int pos){
Node * n = new Node (value);
if (head == NULL)
{
    InsertAtHead(head,value);
}
 Node * temp = head;
 while (temp->data != pos)
 {
    temp = temp->next;
 }
  n->next = temp->next;
 temp->next = n;


}
void Delete (Node*& head,int pos){
    if (pos == head->data)
    {
        
        Node * todel = head;
        Node * temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete todel;
        return;
    }
    
    
}

int main() {
    Node* head = NULL;
     
     cout<<"Inserting At Tail"<<endl;
     InsertAtTail(head,10);
     Display(head);

     cout<<"Inserting At Tail"<<endl;
     InsertAtTail(head,20);
     Display(head);

     cout<<"Inserting At Tail"<<endl;
     InsertAtTail(head,30);
     Display(head);

      cout<<"Inserting At Head"<<endl;
     InsertAtHead(head,5);
     Display(head);

     cout<<"Specific postion"<<endl;
     Position(head,5,20);
     Display(head);

     cout<<"Delete At head"<<endl;
     Delete(head,5);
     Display(head);

    return 0;
}
