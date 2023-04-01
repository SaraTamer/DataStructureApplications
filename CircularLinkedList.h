
#ifndef DATASTRUCTUREALGORITHMS_CIRCULARLINKEDLIST_H
#define DATASTRUCTUREALGORITHMS_CIRCULARLINKEDLIST_H


#include <iostream>

#define ll long long

using namespace std;



template <class T>
class CircularLinkedList{
private:
    struct Node{
        Node* next;
        T value;
        Node()
        {
            value = 0;
            next = nullptr;
        }
    };
    Node *head = new Node();
    Node *tail = new Node();
    ll sz;

public:
    CircularLinkedList():sz(0)
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtHead(T item)
    {
        Node* tmp = new Node;
        tmp->value = item;
        if(isEmpty())
        {
            tail = head = tmp;
            tmp->next = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
        sz++;

    }
    void insertAtTail(T item)
    {
        Node* tmp = new Node;
        tmp->value = item;
        if(isEmpty()) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }

        tmp->next = tmp;
        sz++;
    }
    void insertAt(T item , ll index)
    {
        if(index > sz || index < 0)
        {
            cout << "Position out of scope!\n";
            return;
        }
        if(index == 0)
        {
            insertAtHead(item);
        }
        else if(index == sz)
        {
            insertAtTail(item);
        }
        else
        {
            Node* tmp = head;
            Node* newNode = new Node;
            newNode->value = item;
            for(ll i = 0; i < index - 1; i++)
            {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            sz++;
        }
    }
    void removeAtHead()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        head = head->next;
        tail->next = head;
        sz--;
    }
    void removeAtTail()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        Node* tmp = head;
        for(ll i = 0; i < sz - 1; i++)
        {
            tmp = tmp->next;
        }
        tail = tmp;
        tail->next = head;
        sz--;
    }
    void removeAt(ll index)
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            return;
        }
        if(index == 0)
        {
            removeAtHead();
            return;
        }
        if (index == sz-1)
        {
            removeAtTail();
            return;
        }
        Node* tmp = head;
        for(int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        sz--;
    }
    T retrieveAt(ll index)
    {
        if(index >= sz || index < 0)
        {
            cout << "Position out of scope!\n";
            exit(1);
        }
        Node* tmp = head;
        for(ll i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return tmp->value;
    }
    void replaceAt(T item , ll index)
    {
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            return;
        }
        Node* tmp = head;
        for(ll i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        tmp->value = item;
    }
    bool isExist(T item)
    {
        Node* tmp = head;
        for(ll i = 0; i < sz; i++)
        {
            if(tmp->value == item)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    bool isItemAtEqual(T item , ll index)
    {
        if(index < 0 || index >= sz)
        {
            cout << "Position out of scope!\n";
            exit(1);
        }
        Node* tmp = head;
        for(ll i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return (tmp->value == item);
    }
    void clear(){sz = 0;}
    bool isEmpty()
    {
        return (sz == 0);
    }
    ll size(){return sz;}
    void print()
    {
        Node* tmp = head;
        for(ll i = 0; i < sz; i++)
        {
            cout << tmp->value << ' ';
            tmp = tmp->next;
        }
        cout << '\n';
    }

    ~CircularLinkedList()
    {
        Node *tmp = new Node;
        for(ll i = 0; i < sz; i++)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        sz = 0;
    }
//// TODO:swap

};


#endif //DATASTRUCTUREALGORITHMS_CIRCULARLINKEDLIST_H
