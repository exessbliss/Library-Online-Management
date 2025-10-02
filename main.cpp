#include <iostream>
#include <string> //this is because the name of the users and books will be in strings
#include <vector> // instead of focusing on specific numbers of users or books, it helps keep in vague

using namespace std;

//...........book class.............

class Book{
  private:
    string title;
    string author;
    string isbn; //international standard book number
    bool available; //checks whether the book is available or not

  public:
    Book(string t,string a, string i)
    :title(t), author(a), isbn(i),available(true) {}
    string getTitle() const {return title;}
    string getAuthor() const {return author;}
    string getISBN() const {return isbn;}
    bool isAvailable() const {return available;}


void borrowBook (){
    if(available)available=false;
}
void returnBook(){
    available=true;
}
};


//...........user class.......
class User{
private:
    string name;
    int id;
    vector<Book*> borrowedBooks; //tracks the books the user has borrowed

public:
    User(string n,int i):name(n), id(i){}
    string getName() const {return name;}
    int getId() const{return id;}

//Called when user successfully borrows a book
void borrowBook(Book* b){
    borrowedBooks.push_back(b);
    cout<< name<< "borrowed \"" << b->getTitle() << "\"\n";
}


//Called when user returns a book
void returnbook(Book* b){
    for(size_t i=0; i< borrowedBooks.size(); ++i){
        if (borrowedBooks[i]== b){
            borrowedBooks.erase(borrowedBooks.begin()+i);
            cout<<name << "returned \"" << b->getTitle() << "\"\n";
            return;
        }
    }
    cout << name << "does not have \"" << b->getTitle() << "\"\n";
}
void showBorrowedBooks() const{
    cout <<name << "has borrowed";
    if (borrowedBooks.empty()){
        cout << "No books.\n";
        return;
    }
    for (auto b : borrowedBooks) cout << b->getTitle() << ";";
    cout << "\n";
}
};

//......Library Class....
class Library{
private:
    vector<Book> books;
    vector<User> users;

public:
    //add book by value
    void addBook(const Book& b){
        books.push_back(b);
        cout << "Added book:" << b.getTitle() << "\n";
    }

    //add user by value
    void addUser( const User& u){
        users.push_back(u);
        cout << "Add user:" << u.getName() << "\n";
    }

   Book* searchBookByTitle(const string& title){
       for(auto &b: books){
        if (b.getTitle() ==title) return &b;
       }
       return nullptr;
   }

   User* findUserById(int id){
       for (auto &u : users){
        if (u.getId()==id) return &u;
       }
       return nullptr;
   }

  bool borrowBook(int userId, const string& title) {
        User* u = findUserById(userId);
        if (!u) {
            cout << "User id " << userId << " not found.\n";
            return false;
        }

        Book* b = searchBookByTitle(title);
        if (!b) {
            cout << "Book \"" << title << "\" not found.\n";
            return false;
        }

        if (!b->isAvailable()) {
            cout << "Book \"" << title << "\" is already borrowed.\n";
            return false;
        }

        // mark as borrowed then add to user's list
        b->borrowBook();
        u->borrowBook(b);
        return true;
    }

    bool returnBook(int userId, const string& title) {
        User* u = findUserById(userId);
        if (!u) {
            cout << "User id " << userId << " not found.\n";
            return false;
        }

        Book* b = searchBookByTitle(title);
        if (!b) {
            cout << "Book \"" << title << "\" not found.\n";
            return false;
        }

        u->returnbook(b);
        b->returnBook();
        return true;
    }

    void showAllBooks() const {
        cout << "Library books:\n";
        for (const auto &b : books) {
            cout << "- " << b.getTitle() << " by " << b.getAuthor()
                 << " [ISBN: " << b.getISBN() << "] "
                 << (b.isAvailable() ? "[Available]" : "[Borrowed]") << "\n";
        }
    }

    void showAllUsers() const {
        cout << "Registered users:\n";
        for (const auto &u : users) {
            cout << "- " << u.getName() << " (id=" << u.getId() << ")\n";
        }
    }

};

int main()
{
 Library lib;
// Test 1: Adding Books---
 lib.addBook(Book("Twisted Games", "Anna Huang", "1111"));
 lib.addBook(Book("Hunting Adenaline", "Rina Kent", "2222"));


 //Test 2: Adding Users----
 lib.addUser(User("Rita", 1));
 lib.addUser(User("Eileen", 2));

 cout << "\n";
 lib.showAllBooks();
 cout << "\n";

 // Test 3: Borrowing Books----
lib.borrowBook(1, "Twisted Games");       // Rita borrows 1984
lib.borrowBook(2, "Twisted Games");       // Eileen tries to borrow same book (should fail)
lib.borrowBook(2, "Hunting Adenaline"); // Eileen borrows a different book

cout << "\n";
lib.showAllBooks();
cout << "\n";

//Test 4: Returning Books----
lib.returnBook(1, "Twisted Games");
lib.returnBook(2, "Hunting Adenaline");

cout << "\n";
lib.showAllBooks();
cout << "\n";

User* a=lib.findUserById(1);
if(a) a->showBorrowedBooks();
User* b=lib.findUserById(2);
if(b) b->showBorrowedBooks();

return 0;
}
