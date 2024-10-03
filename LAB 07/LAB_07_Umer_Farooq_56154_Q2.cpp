#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;
Node(int value){
    next = NULL;
    prev = NULL;
    data = value;
}
};
void InsertAtTail(Node*& head,int value){
    Node* n = new Node (value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
     temp->next = n;
     n->prev = temp; 
}
void InsertAtHead(Node*& head,int value){
    Node* n = new Node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
    
}
void InsertPosition(Node*&head,int value,int pos){
    if (head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;

    }
    if (pos == head->data)
    {
        InsertAtHead(head,value);
    }
    Node* temp = head;
    while (temp->data != pos)
    {
        temp = temp->next;
    }
        Node* n  = new Node(value);
       
    if (temp->next != NULL)
    {
        Node* pointer = temp->next;
        n->prev = temp;
        temp->next = n;
        n->next = pointer;
        pointer->prev = n;
    }
    else
    {
        temp->next = n;
        n->prev = temp;
    }
       

    }
void DeleteNode(Node*&head,int pos){
  if (head == NULL)
  {
    cout<<"List is empty"<<endl;
    return;
  }
if (head->data == pos)
{
   
    Node* temp = head;
    head= head->next;
    head->prev = NULL;
    delete temp;
    return;
}

  Node* temp = head;

  while (temp->data != pos)
  {
    temp = temp->next;
  }
  if (temp->next == NULL)
  {
    Node* todel = temp;
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete todel;
    return;
  }
  
   temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
        
}
void Middle(Node*& head){
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "Middle element: " << slow->data << "\n";
}

void Display(Node*& head){
Node* temp = head;
while (temp != NULL)
{
    cout<<temp->data<< " -> ";
    temp = temp->next;
    
}
cout<<"NULL";
cout<<endl;

}
void ReverseDisplay(Node* head) {
    if (head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
}
int main()
{
    Node *head = NULL;
    InsertAtTail(head, 10);
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    InsertAtTail(head, 40);
    Display(head);
    cout<<"Reverse Display"<<endl;
    ReverseDisplay(head);
  
    system("pause");
    return 0;
}