
#ifndef DATASTRUCTUREALGORITHMS_ARRAY_BASEDLIST_H
#define DATASTRUCTUREALGORITHMS_ARRAY_BASEDLIST_H

#include <iostream>

#define ll long long

using namespace std;

template <class T>
class ArrayBasedList{
private:
    T *arr;
    ll maxSz;
    ll sz;
public:
    ArrayBasedList():maxSz(100) , sz(0){arr = new T[100];}  // default maxSize = 100
    ArrayBasedList(ll maxS):sz(0)
    {
        // default maxSize = 100
        if(maxS < 0)
            maxSz = 100;
        else
            maxSz = maxS;

        arr = new T[maxSz];
    }
    void insert(T item)
    {
        if(isFull())
        {
            cout << "The list is FULL!\n";
            return;
        }
        arr[sz] = item;
        sz++;

    }
    void insertAt(T item , ll index)
    {
        if(isFull())
        {
            cout << "The list is FULL!\n";
            return;
        }
        if(index < 0 || index > sz)
        {
            cout << "Position out of scope!\n";
            return;
        }
        for(ll i = sz ; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = item;
        sz++;
    }
    void replaceAt(T item , ll index)
    {
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            return;
        }
        arr[index] = item;
    }
    T retrieveAt(ll index)
    {
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            exit(1);
        }
        return arr[index];
    }
    bool isItemAtEqual(T item , ll index)
    {
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            exit(1);
        }
        return (arr[index] == item);
    }
    void removeAt(ll index)
    {
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            return;
        }
        for(ll i = index; i < sz; i++)
        {
            arr[i] = arr[i + 1];
        }
        sz--;
    }
    void print()
    {
        for(ll i = 0; i < sz; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    ll size(){return sz;}
    ll maxSize(){return maxSz;}
    bool isEmpty(){return (sz == 0);}
    bool isFull(){return (sz == maxSz);}
    void clear(){sz = 0;}
    ~ArrayBasedList(){delete[] arr;}
};
#endif //DATASTRUCTUREALGORITHMS_ARRAY_BASEDLIST_H
