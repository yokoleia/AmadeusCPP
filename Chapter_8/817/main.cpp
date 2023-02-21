#include "LinkedListLibrary.h"
#include "VectorLibrary.h"
#include "BookNode.h"
#include "Book.h"
#include <fstream>
#include <iostream>
using namespace std;

void FillLibraries(LinkedListLibrary &linkedListLibrary, VectorLibrary &vectorLibrary)
{
    ifstream inputFS; // File input stream
    int linkedListOperations = 0;
    int vectorOperations = 0;

    BookNode *currNode;
    Book tempBook;

    string bookTitle;
    string bookAuthor;
    long long bookISBN;

    // Try to open file
    inputFS.open("books.txt");

    while (getline(inputFS, bookTitle))
    {
        inputFS >> bookISBN;
        inputFS.ignore(1, '\n');
        getline(inputFS, bookAuthor);

        // Insert into linked list
        currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
        linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);

        // Insert into vector
        tempBook = Book(bookTitle, bookAuthor, bookISBN);
        vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);
    }

    inputFS.close(); // close() may throw ios_base::failure if fails
}

int main()
{
    int linkedListOperations = 0;
    int vectorOperations = 0;

    // Create libraries
    LinkedListLibrary linkedListLibrary = LinkedListLibrary();
    VectorLibrary vectorLibrary;

    // Fill libraries with 100 books
    FillLibraries(linkedListLibrary, vectorLibrary);

    // Create new book to insert into libraries
    BookNode *currNode;
    Book tempBook;

    string bookTitle;
    string bookAuthor;
    long bookISBN;

    getline(cin, bookTitle);
    cin >> bookISBN;
    cin.ignore();
    getline(cin, bookAuthor);

    // cout << "Title: " << bookTitle << "\nISBN: " << bookISBN << "\nAuthor: " << bookAuthor << endl;
    // Insert into linked list
    // No need to delete currNode, deleted by LinkedListLibrary destructor
    currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
    // TODO: Call LL_Library's InsertSorted() method to insert currNode and return
    //       the number of operations performed
    linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);

    // Insert into VectorList
    tempBook = Book(bookTitle, bookAuthor, bookISBN);
    // TODO: Call VectorLibrary's InsertSorted() method to insert tempBook and return
    //       the number of operations performed
    vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);

    // TODO: Print number of operations for linked list
    cout << "Number of linked list book copy operations: " << linkedListOperations << endl;
    // TODO: Print number of operations for vector
    cout << "Number of vector book copy operations: " << vectorOperations << endl;
}