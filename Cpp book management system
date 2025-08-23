#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book class
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void display() {
        cout << "Book ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

// Library class
class Library {
    vector<Book> books;

public:
    // Add book
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }
        for (auto &book : books) {
            book.display();
        }
    }

    // Search book by title
    void searchBook(string title) {
        bool found = false;
        for (auto &book : books) {
            if (book.title == title) {
                book.display();
                found = true;
            }
        }
        if (!found) cout << "Book not found.\n";
    }

    // Issue book by ID
    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "Book issued successfully.\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    // Return book by ID
    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book ID not found.\n";
    }
};

// Main function
int main() {
    Library lib;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                cin.ignore();
                cout << "Enter Title to search: ";
                getline(cin, title);
                lib.searchBook(title);
                break;

            case 4:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 5:
                cout << "Enter Book ID to return: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 6:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
