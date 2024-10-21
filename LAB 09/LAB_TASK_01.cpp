#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    // Constructor
    Student() : reg_no(0), st_name(""), cgpa(0.0f) {}

    // Function to input student data
    void input() {
        cout << "Enter registration number: ";
        cin >> reg_no;
        cout << "Enter student name: ";
        cin >> st_name;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    // Function to output student data
    void output() const {
        cout << "Registration Number: " << reg_no << "\n";
        cout << "Student Name: " << st_name << "\n";
        cout << "CGPA: " << cgpa << "\n";
    }
};

// Stack class using dynamic array of students
class StudentStack {
private:
    Student* stack;
    int top;
    int maxSize;

public:
    // Constructor
    StudentStack(int size) {
        maxSize = size;
        stack = new Student[maxSize];
        top = -1;
    }

    // Destructor to free memory
    ~StudentStack() {
        delete[] stack;
    }

    // Push function
    void push(const Student& s) {
        if (top == maxSize - 1) {
            cout << "Stack Overflow! Cannot push more students.\n";
        } else {
            stack[++top] = s;
        }
    }

    // Pop function
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! No student to pop.\n";
        } else {
            cout << "Popped student details:\n";
            stack[top--].output();
        }
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    StudentStack studentStack(stackSize);
    Student student;
    int choice;

    do {
        cout << "\n1. Push student\n2. Pop student\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student.input();
            studentStack.push(student);
            break;
        case 2:
            studentStack.pop();
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
