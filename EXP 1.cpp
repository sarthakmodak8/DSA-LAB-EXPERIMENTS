#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class Stack
{
private:
    string books[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(string book)
    {
        if (top == MAX - 1)
        {
            cout << "Stack is full.\n";
            return;
        }
        books[++top] = book;
        cout << book << " BOOK ADDED.\n";
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No books available.\n";
            return;
        }
        cout << books[top] << " removed from the stack.\n";
        top--;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack has no books.\n";
            return;
        }
        cout << "Latest Book: " << books[top] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "No books to display.\n";
            return;
        }
        cout << "\nAvailable Books:\n";
        for (int i = 0; i <= top; i++)
        {
            cout << books[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice;
    string book;

    do
    {
        cout << "\n===== Library Stack Menu =====\n";
        cout << "1. Return Book (Push)\n";
        cout << "2. Arrange Book (Pop)\n";
        cout << "3. Top Book (Peek)\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book Name: ";
            cin >> book;
            s.push(book);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Program Closed.\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}
