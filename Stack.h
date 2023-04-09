
#ifndef DATASTRUCTUREALGORITHMS_STACK_H
#define DATASTRUCTUREALGORITHMS_STACK_H

#include <iostream>

#define ll long long

using namespace std;

class StackEmptyException : public exception
{
public:
    StackEmptyException() = default;
    virtual const char* what() const throw()
    {
        return "Stack Empty Exception!\n";
    }
};
class StackOverFlowException : public exception
{
public:
    StackOverFlowException() = default;
    virtual const char* what() const throw()
    {
        return "Stack Overflow Exception!\n";
    }
};

template <class T>
class Stack {
private:
    ll top;
    T* container;
    ll capacity;
public:
    // initializing stack with default capacity 100
    Stack():top(-1) , capacity(100)
    {
        container = new T[100];
    }
    // initializing stack with given capacity
    Stack(ll capacity):capacity(capacity) , top(-1)
    {
        container = new T[capacity];
    }
    void push(T item);
    T pop();
    T Top();
    void print();

    ll size(){return (top+1);}
    bool isFull(){return (top >= capacity - 1);}
    bool isEmpty() {return (top == -1);}
    void clear(){top = -1;}

    ~Stack()
    {
        delete[] container;
    }
};

template <class T>
void Stack<T>::push(T item)
{
    StackOverFlowException over;
    try{
        if(this->isFull())
        {
            throw over;
        }
        else
        {
            top++;
            container[top] = item;
        }
    }
    catch (...)
    {
        cout << over.what();
    }
}

template <class T>
T Stack<T>::pop()
{
    StackEmptyException empty;
    try {
        if(this->isEmpty())
        {
            throw empty;
        }
        else
        {
            return container[top--];
        }
    }
    catch (...)
    {
        cout << empty.what();
        exit(0);
    }
}

template <class T>
T Stack<T>::Top()
{
    StackEmptyException empty;
    try {
        if(this->isEmpty())
        {
            throw empty;
        }
        else
        {
            return container[top];
        }
    }
    catch (...)
    {
        cout << empty.what();
        exit(0);
    }
}

template <class T>
void Stack<T>::print()
{
    for(ll i = top ; i >= 0 ; i--)
    {
        cout << container[i] << ' ';
    }
    cout << '\n';
}


#endif //DATASTRUCTUREALGORITHMS_STACK_H
