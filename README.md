# Library-Online-Management
This is a simple Library Management System built in C++ using Object-Oriented Programming (OOP) concepts.
It allows you to:

i.	Add books and users to the library

ii.	Borrow and return books

iii.	Search for books by title

iv.	Display available books and registered users

The project demonstrates the use of:
i.	Classes and objects

ii.	Encapsulation (private data, public methods)

iii.	Relationships between classes (Library, Book, User)

iv.	Use of vectors (std::vector) for dynamic storage

Classes

1. Book

Represents a book in the library.
Data: title, author, ISBN (International Standard Book Number), available
Methods:

i.	borrowBook() → marks book as borrowed

ii.	returnBook() → marks book as available

iii.	Getters: getTitle(), getAuthor(), getISBN(), isAvailable()

3. User
   
Represents a library user.
Data: name, id, borrowedBooks (vector of Book pointers)
Methods:

i.	borrowBook(Book*) → adds a book to user’s borrowed list

ii.	returnBook(Book*) → removes a book from user’s borrowed list

iii.	showBorrowedBooks() → displays user’s borrowed books

5. Library

Manages books and users.
Data: books, users
Methods:

i.	addBook(Book) → adds a new book

ii.	addUser(User) → registers a user

iii.	searchBookByTitle(string) → finds a book

iv.	findUserById(int) → finds a user

v.	borrowBook(userId, title) → lets a user borrow a book

vi.	returnBook(userId, title) → lets a user return a book

vii.	showAllBooks() → displays all books

viii.	showAllUsers() → displays all users

How It Works
1.	The program starts by creating a Library object.
2.	Books and users are added with addBook() and addUser().
3.	A user can borrow a book if it’s available.
4.	The same book cannot be borrowed by another user until it’s returned.
5.	Users can return books, making them available again.
6.	The library can display all books and all registered users.

N/B: All test cases are included in the main() function. They demonstrate adding books/users, borrowing, returning, and edge cases like borrowing an already borrowed book.

