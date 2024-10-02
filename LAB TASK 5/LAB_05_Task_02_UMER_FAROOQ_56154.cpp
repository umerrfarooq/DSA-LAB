#include <iostream>
using namespace std;
class Node
{
public:
    Node* next;
    int data;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insertAtTail(Node*& head, int value)
{
    Node* n = new Node(value);
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
}
void displaynNodes(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void reverseNode(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }

    Node* previous = NULL;
    Node* current = head;
    Node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}
int main()
{
    Node* head = NULL;
    insertAtTail(head, 22);
    insertAtTail(head, 27);
    insertAtTail(head, 31);
    insertAtTail(head, 40);
    cout << "Before Reverse Node Data: ";
    displaynNodes(head);
    cout << "After Reverse Node Data: ";
    reverseNode(head);
    displaynNodes(head);
    system("pause");
    return 0;
}