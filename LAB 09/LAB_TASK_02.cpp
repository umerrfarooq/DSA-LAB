#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    // Constructor
    Person() : per_id(0), per_name(""), per_age(0) {}

    // Input function
    void input() {
        cout << "Enter person ID: ";
        cin >> per_id;
        cout << "Enter person name: ";
        cin >> per_name;
        cout << "Enter person age: ";
        cin >> per_age;
    }

    // Output function
    void output() const {
        cout << "Person ID: " << per_id << "\n";
        cout << "Person Name: " << per_name << "\n";
        cout << "Person Age: " << per_age << "\n";
    }
};

// Node class for linked list
class Node {
public:
    Person data;
    Node* next;
    
    Node(Person p) : data(p), next(nullptr) {}
};

// Linked list queue for Person objects
class PersonQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    PersonQueue() : front(nullptr), rear(nullptr) {}

    // Add to queue
    void addQueue(const Person& p) {
        Node* newNode = new Node(p);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove from queue
    void removeQueue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot remove!\n";
        } else {
            Node* temp = front;
            cout << "Removing person:\n";
            front->data.output();
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
        }
    }

    // Check if queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    PersonQueue queue;
    Person person; 
    int choice;

    do {
        cout << "\n1. Add person to queue\n2. Remove person from queue\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            person.input();
            queue.addQueue(person);
            break;
        case 2:
            queue.removeQueue();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
