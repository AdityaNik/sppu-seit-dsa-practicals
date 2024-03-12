#include <iostream>
using namespace std;

class Queue
{
public:
    int front, rear, size;
    int ar[];
    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        ar[size] = 0;
    }

    bool isFull()
    {
        return front == (rear + 1) % size;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    void enqueue(){
        if (isFull()){
            cout << "Queue is Full";
        }
        else{
            if (front == -1){
                front = 0;
            }
            rear = (rear + 1) % size;
            cout << "Enter element: ";
            int temp;
            cin >> temp;
            ar[rear] = temp;
        }
        display();
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Array is empty";
        }
        else{
            if (front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1) % size;
            }
        }
        display();
    }

    void display(){
        if (isEmpty()){
            cout << "Nothing to display";
        }
        else{
            int i = front;
            cout << "\nFront: " << front << endl;
            cout << "Rear: " << rear << endl;
            do{
                cout << ar[i]<< " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout<<"\n";
        }
    }
};

int main()
{
    Queue q(10);
    while (1){
        int choice;
        cin >> choice;
        switch (choice){
        case 1:
            q.enqueue();
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << "\ndislplaying: " << endl;
            q.display();
            break;

        default:
            break;
        }
    }
    return 0;
}