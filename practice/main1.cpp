#include<iostream>
using namespace std;
class Node
{
public:
    Node * next;
    Node * prev;
    int data;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
void InsertAtTail(Node *& head, int value)
{
    Node *n = new Node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void InsertAtHead(Node *&head, int value)
{   Node *n = new Node(value);
    if (head = NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
}
void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void Delete(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Head is empty" << endl;
        return;
    }
    if (head->data == pos)
    {
        Node * todel = head;
        head = head->next;
        head->prev = NULL;
        delete todel;
        return;
    }
    Node *temp = head;
    while (temp->data != pos)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev;
    }
    else
    {
        temp->prev->next = NULL;
        temp->prev = NULL;
    }
    
    
     delete temp;
}
void position(Node *&head, int pos, int value)
{
    if (head == NULL)

    {
        InsertAtHead(head, value);
        return;
    }
    Node *n = new Node(value);
    if (head->data == pos)

    {
        InsertAtHead(head, value);
        return;
    }
    Node *temp = head;
    while (temp->data != pos)
    {
        temp = temp->next;
    }
    temp ->next = n;
}
int main(){
    
}