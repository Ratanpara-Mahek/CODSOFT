#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <algorithm> 
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
    time_t dueDate;
    Book(string t, string a, string i)
        : title(t), author(a), ISBN(i), available(true), dueDate(0) {}
};

struct Borrower {
    string name;
    vector<Book*> borrowedBooks;

    Borrower(string n) : name(n) {}
};

void searchBooks(const vector<Book>& books, const string& keyword) {
    cout << "Matching Books:" << endl;
    bool found = false;
    for (const Book& book : books) {
        if (book.title.find(keyword) != string::npos ||
            book.author.find(keyword) != string::npos ||
            book.ISBN.find(keyword) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author 
                 << ", ISBN: " << book.ISBN << ", Available: " 
                 << (book.available ? "Yes" : "No") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No matching books found." << endl;
    }
}

void checkoutBook(Book& book, Borrower& borrower) {
    if (book.available) {
        book.available = false;
        borrower.borrowedBooks.push_back(&book);
        time_t now = time(0);
        book.dueDate = now + 7 * 24 * 60 * 60; // 7 days in seconds
        cout << "Book checked out successfully." << endl;
    } else {
        cout << "Sorry, the book is not available for checkout." << endl;
    }
}

// Function to record book returns
void returnBook(Book& book, Borrower& borrower) {
    auto it = find(borrower.borrowedBooks.begin(), borrower.borrowedBooks.end(), &book);
    if (it != borrower.borrowedBooks.end()) {
        book.available = true;
        borrower.borrowedBooks.erase(it);
        cout << "Book returned successfully." << endl;
    } else {
        cout << "You have not borrowed this book." << endl;
    }
}

// Function to calculate fine for overdue books
float calculateFine(const Book& book) {
    time_t now = time(0);
    if (now > book.dueDate) {
        // Calculate difference in seconds
        double diff = difftime(now, book.dueDate);
        // Convert seconds to days
        int daysOverdue = static_cast<int>(diff) / (24 * 60 * 60);
        // Fine $1 per day overdue
        return daysOverdue;
    }
    return 0; // No fine if not overdue
}

int main() {
    vector<Book> library = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565"},
        {"To Kill a Mockingbird", "Harper Lee", "9780061120084"},
        {"1984", "George Orwell", "9780451524935"}
        // Add more books if needed
    };

    Borrower borrower("John Doe");

    int choice;
    string keyword;
    while (true) {
        cout << "\nMenu:\n1. Search Books\n2. Check Out Book\n3. Return Book\n4. Calculate Fine\n5. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter keyword to search: ";
                getline(cin, keyword);
                searchBooks(library, keyword);
                break;
            case 2:
                cout << "Enter book title to check out: ";
                getline(cin, keyword);
                {
                    bool found = false;
                    for (Book& book : library) {
                        if (book.title == keyword) {
                            checkoutBook(book, borrower);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book not found." << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter book title to return: ";
                getline(cin, keyword);
                {
                    bool found = false;
                    for (Book& book : library) {
                        if (book.title == keyword) {
                            returnBook(book, borrower);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book not found." << endl;
                    }
                }
                break;
            case 4:
                cout << "Enter book title to calculate fine: ";
                getline(cin, keyword);
                {
                    bool found = false;
                    for (Book& book : library) {
                        if (book.title == keyword) {
                            float fine = calculateFine(book);
                            cout << "Fine for \"" << book.title << "\": $" << fine << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book not found." << endl;
                    }
                }
                break;
            case 5:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice. Please try again.";
        }
    }

    return 0;
}
