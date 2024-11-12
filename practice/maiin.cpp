#include <iostream>
#include <string>
using namespace std;

// Book class to store book information
class Book {
public:
    string title;
    string author;

    Book() {
        title = "";
        author = "";
    }

    void setDetails(string t, string a) {
        title = t;
        author = a;
    }

    void displayDetails() {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

// Library class to manage an array of books
class Library {
private:
    Book books[100]; // Array to store up to 100 books
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    // Add a new book to the library
    void addBook(string title, string author) {
        if (bookCount < 100) {
            books[bookCount].setDetails(title, author);
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full, can't add more books." << endl;
        }
    }

    // Remove a book by title
    void removeBook(string title) {
        int index = -1;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < bookCount - 1; i++) {
                books[i] = books[i + 1];
            }
            bookCount--;
            cout << "Book removed successfully!" << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    // Display all books in the library
    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
        } else {
            for (int i = 0; i < bookCount; i++) {
                books[i].displayDetails();
            }
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Display Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character after choice input

        switch (choice) {
        case 1:
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(title, author);
            break;

        case 2:
            cout << "Enter the title of the book to remove: ";
            getline(cin, title);
            library.removeBook(title);
            break;

        case 3:
            library.displayBooks();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
