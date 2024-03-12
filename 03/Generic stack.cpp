
#include <iostream>

using namespace std;

template <class T>
class node
{
    public:
    T data;
    node<T> *next;
};

template <class T>
class stack1
{
    node<T> *top;
    public:
    stack1(){ top=NULL;}
    void push(T val)
    {
        node<T> *temp;
        if (top==NULL)
        {
            top = new node<T>;
            top->data = val;
            top->next =NULL;
            cout <<"1st element"<<endl;
        }
        else
        {
            temp = new node<T>;
            temp->data = val;
            temp->next = top;
            top = temp;
            cout<<"next element"<<endl;
        }
        cout<<"element is pushed"<<endl<<endl;
    }
    
    T pop()
    {
        T n;
        if(top == NULL)
           cout<<"Stack Underflow";
        else
        {
            n = top->data;
            top = top->next;
            return(n);
        }
            
           
    }
};




int main()
{
    stack1<int> s;
    int a;
    char b;
    s.push(10);
    s.push(20);
    
    stack1<char> s1;
    s1.push('A');
    s1.push('B');
    
    a=s.pop();
    cout<<"poped  "<<a<<endl;
    a=s.pop();
    cout<<"poped   "<<a<<endl<<endl;
    
    b=s1.pop();
    cout<<"poped   "<<b<<endl;
    b=s1.pop();
    cout<<"poped   "<<b<<endl<<endl;
    
    //s.push
    cout<<"Hello World";

    return 0;
}


