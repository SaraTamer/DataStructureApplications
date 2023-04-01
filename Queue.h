
#ifndef DATASTRUCTUREALGORITHMS_QUEUE_H
#define DATASTRUCTUREALGORITHMS_QUEUE_H

#include <iostream>

#define ll long long

using namespace std;



template <class T>
class CircularQueue{
private:
    ll sz;
    ll maxSz;
    ll front;
    ll rear;
    T* arr;
public:
    CircularQueue():sz(0), maxSz(100), front(0) , rear(99)
    {
        arr = new T[maxSz];
    }
    CircularQueue(ll maxS):sz(0), maxSz(maxS), front(0) , rear(maxS - 1)
    {
        if(maxS < 0)
        {
            maxSz = 100;
            rear = maxSz - 1;
        }
        arr = new T[maxSz];
    }
    void enqueue(T item)
    {
        if(isFull())
        {
            cout << "The queue is FULL!\n";
            return;
        }
        arr[sz] = item;
        rear = (rear + 1) % maxSz;
        sz++;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "The queue is EMPTY!\n";
            return;
        }
        front = (front + 1) % maxSz;
        sz--;
    }
    void print()
    {
        for(ll i = front , j = 0; j < sz ; i = (i+1) % maxSz , j++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    T first()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            exit(1);
        }
        return arr[front];
    }
    void clear(){sz = 0; arr = nullptr;}
    ll size(){return sz;}
    bool isEmpty(){return (sz == 0);}
    bool isFull(){return (sz == maxSz);}
    ~CircularQueue(){delete[] arr;}
};

#endif //DATASTRUCTUREALGORITHMS_QUEUE_H
