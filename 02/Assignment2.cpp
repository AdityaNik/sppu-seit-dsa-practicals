#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, size;
    int queue[];

public:
    Queue(int n)
    {
        size = n;
        queue[size] = 0;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    void Enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full. Enqueue operation failed." << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            queue[rear] = item;
            display();
        }
    }

    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Dequeue operation failed." << endl;
            return -1;
        }
        else
        {
            int removedItem = queue[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            display();
            return removedItem;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "\nFront: " << front << endl;
            cout << "Rear: " << rear << endl;
            cout << "Queue: ";
            int i = front;
            do
            {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << "\n\n";
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;
    Queue cq(size);
    int choice, item;

    while (true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> item;
            cq.Enqueue(item);
            break;
        case 2:
            cq.Dequeue();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}