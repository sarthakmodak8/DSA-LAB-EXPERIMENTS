#include<iostream>
using namespace std;

class Kunal {
private:
    int queue[5];
    int front;
    int rear;
    int size;

public:
    Kunal()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    void insert(int value)
    {
        if (rear == size - 1)
        {
            cout << "\nQueue is Full.\n";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        cout << "\nElement Inserted Successfully.\n";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue is Empty.\n";
            front = rear = -1;
            return;
        }
        cout << "\nDeleted Element : " << queue[front] << endl;
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty.\n";
            return;
        }
        cout << "\nQueue Elements:\n";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    void peek()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty.\n";
            return;
        }
        cout << "\nFront Element : " << queue[front] << endl;
    }
};

int main()
{
    Kunal k;
    int choice, value;

    do
    {
        cout << "\n========== QUEUE MENU ==========";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> value;
            k.insert(value);
            break;
        case 2:
            k.dequeue();
            break;
        case 3:
            k.display();
            break;
        case 4:
            k.peek();
            break;
        case 5:
            cout << "\nExiting Program...\n";
            break;
        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }
    } while (choice != 5);

    return 0;
}
