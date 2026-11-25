#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void createList()
    {
        int n, value;

        if (head != NULL)
        {
            cout << "\nList already created.\n";
            return;
        }

        cout << "\nEnter number of nodes: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Invalid number of nodes.\n";
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;
            insertEnd(value);
        }
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        if (head->data == value)
        {
            head = head->next;
            delete temp;
            cout << "\nNode deleted successfully.\n";
            return;
        }

        while (temp != NULL && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\nValue not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "\nNode deleted successfully.\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "\nLinked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do
    {
        cout << "\n========== MENU ==========";
        cout << "\n1. Create Linked List";
        cout << "\n2. Display Linked List";
        cout << "\n3. Delete Node";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.createList();
            break;
        case 2:
            list.display();
            break;
        case 3:
            cout << "\nEnter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 4:
            cout << "\nProgram Ended.\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
