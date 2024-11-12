#include<iostream>
#include<string>
using namespace std;

// Node structure representing an item in the shopping cart
class Node {
public:
    string itemName;      // Item name
    double pricePerUnit;   // Price per unit
    int quantity;          // Quantity
    double totalPrice;     // Total price for the item
    Node* next;            // Pointer to the next item

    // Constructor to initialize a node
    Node(string name, double price, int qty) {
        itemName = name;
        pricePerUnit = price;
        quantity = qty;
        totalPrice = price * qty;
        next = NULL;
    }
};

// Function to insert an item at the tail of the list
void insertAtTail(Node*& head, string name, double price, int qty) {
    Node* n = new Node(name, price, qty);
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

// Function to display the shopping list and total price
void displayList(Node* head) {
    if (head == NULL) {
        cout << "The shopping list is empty!" << endl;
        return;
    }

    Node* temp = head;
    double grandTotal = 0.0;

    // Display the header
    cout << "\nItem\tPrice per Unit\tQuantity\tTotal Price\n";
    while (temp != NULL) {
        cout << temp->itemName << "\t" << temp->pricePerUnit << "\t\t" 
             << temp->quantity << "\t\t" << temp->totalPrice << endl;
        grandTotal += temp->totalPrice;
        temp = temp->next;
    }
    cout << "Grand Total: $" << grandTotal << endl;
}

// Function to delete an item from the shopping list
void deleteItem(Node*& head, string itemName) {
    if (head == NULL) {
        cout << "The shopping list is empty!" << endl;
        return;
    }

    if (head->itemName == itemName) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->itemName != itemName) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Item not found in the list!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main() {
    Node* head = NULL;
    int choice;

    do {
        cout << "\n1. Add item to shopping list\n2. Display shopping list\n3. Delete item from shopping list\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double price;
                int qty;

                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter price per unit: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> qty;

                insertAtTail(head, name, price, qty);
                break;
            }

            case 2:
                displayList(head);
                break;

            case 3: {
                string name;
                cout << "Enter the name of the item to delete: ";
                cin >> name;
                deleteItem(head, name);
                break;
            }

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 4);

    return 0;
}
