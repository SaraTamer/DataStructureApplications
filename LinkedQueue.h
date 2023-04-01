

#ifndef DATASTRUCTUREALGORITHMS_LINKEDQUEUE_H
#define DATASTRUCTUREALGORITHMS_LINKEDQUEUE_H


#include <iostream>

#define ll long long

using namespace std;



template <class T>
class LinkedQueue {
private:
    struct Node{
        Node *next;
        T value;
        Node():value(0), next(nullptr){};
    };
    Node *front = new Node();
    Node *rear = new Node();
    ll sz;
public:
    LinkedQueue():sz(0)
    {
        front = rear = nullptr;
    }
    void enqueue(T item)
    {
        Node* tmp = new Node;
        tmp->value = item;
        if(isEmpty()) {
            front = rear = tmp;
        }
        else {
            rear->next = tmp;
            rear = tmp;
        }
        tmp->next = nullptr;
        sz++;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        Node *toBeRemoved = front;
        front = front->next;
        sz--;
        delete toBeRemoved;
    }
    T first()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            exit(1);
        }

        return front->value;
    }
    void clear()
    {
        sz = 0;
        for(ll i = 0; i < sz; i++)
        {
            this->dequeue();
        }
        front = rear = nullptr;
    }
    void print()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        Node *tmp = front;
        for(ll i = 0; i < sz; i++)
        {
            cout << tmp->value << ' ';
            tmp = tmp->next;
        }
    }

    bool isEmpty(){return (sz == 0);}
    ll size(){return sz;}
};

#endif //DATASTRUCTUREALGORITHMS_LINKEDQUEUE_H
