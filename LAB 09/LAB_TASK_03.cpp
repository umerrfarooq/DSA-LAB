#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
class Queue {
private:
    Node* front;
    Node* rear;
    int maxSize;
    int currentSize;

public:
    // Constructor
    Queue(int size) : front(nullptr), rear(nullptr), maxSize(size), currentSize(0) {}

    // Add to queue
    void addQueue(int value) {
        if (currentSize == maxSize) {
            cout << "Queue Overflow! Cannot add more elements.\n";
            return;
        }
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
    }

    // Remove from queue
    int removeQueue() {
        if (front == nullptr) {
            cout << "Queue Underflow! No element to remove.\n";
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        currentSize--;
        return value;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return currentSize == 0;
    }
};

int main() {
    Queue queue1(5), queue2(5);
    int choice, value;

    do {
        cout << "\n1. Insert in first queue\n2. Remove from first queue and insert in second queue\n";
        cout << "3. Remove from second queue\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            queue1.addQueue(value);
            break;
        case 2:
            value = queue1.removeQueue();
            if (value != -1) {
                queue2.addQueue(value);
            }
            break;
        case 3:
            queue2.removeQueue();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
