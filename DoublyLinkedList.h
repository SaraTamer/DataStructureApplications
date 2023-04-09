#ifndef DATASTRUCTUREALGORITHMS_DOUBLYLINKEDLIST_H
#define DATASTRUCTUREALGORITHMS_DOUBLYLINKEDLIST_H



#include <iostream>

#define ll long long

using namespace std;



template <class T>
class DoublyLinkedList {
private:
    struct Node {
        Node *next;
        Node *prev;
        T value;

        Node() {
            value = 0;
            next = prev = nullptr;
        }
    };

    Node *head = new Node();
    Node *tail = new Node();
    ll sz;

public:
    DoublyLinkedList():sz(0)
    {
        head = tail = nullptr;
    }
    void insertAtHead(T item)
    {
        Node *tmp = new Node;
        tmp->value = item;
        if(isEmpty())
        {
            head = tail = tmp;
            tmp->next = tmp->prev = nullptr;
        }
        else
        {
            head->prev = tmp;
            tmp->next = head;
            tmp->prev = nullptr;
            head = tmp;
        }
        sz++;
    }
    void insertAtTail(T item)
    {
        Node *tmp = new Node;
        tmp->value = item;
        if(isEmpty())
        {
            head = tail = tmp;
            tmp->next = tmp->prev = nullptr;
        }
        else
        {
            tail->next = tmp;
            tmp->prev = tail;
            tmp->next = nullptr;
            tail = tmp;
        }
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
        else {
            Node *tmp = head;
            Node *newNode = new Node;
            newNode->value = item;
            for (ll i = 0; i < index - 1; i++)
            {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next->prev = newNode;
            tmp->next = newNode;
            newNode->prev = tmp;
            sz++;
        }
    }
    void insertAfter(Node * prv, T item)
    {
        Node* tmp = new Node;
        tmp->value = item;
        tmp->prev = prv;
        tmp->next = prv->next;
        prv->next->prev = tmp;
        prv->next = tmp;
    }
    void removeAtHead()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        if(sz == 1)
        {
            delete head;
            head = tail = nullptr;
            sz--;
            return;
        }
        Node *toBeRemoved = head;
        head = head->next;
        head->prev = nullptr;
        sz--;
        delete toBeRemoved;
    }
    void removeAtTail()
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
            return;
        }
        if(sz == 1)
        {
            delete head;
            head = tail = nullptr;
            sz--;
            return;
        }
        Node *toBeRemoved = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete toBeRemoved;
        sz--;
    }
    void removeAt(ll index)
    {
        if(index >= sz || index < 0)
        {
            cout << "Position out of scope!\n";
            return;
        }
        if(index == 0)
        {
            removeAtHead();
            return;
        }
        if(index == sz -1)
        {
            removeAtTail();
            return;
        }
        Node *tmp = head;
        for(ll i = 0; i < index ; i++)
        {
            tmp = tmp->next;
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        sz--;
    }
    T retrieveAt(ll index)
    {
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
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
        if(isEmpty())
        {
            cout << "The list is EMPTY!\n";
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

    void forwardTraversal()
    {
        Node* tmp = head;
        for(ll i = 0; i < sz; i++)
        {
            cout << tmp->value << ' ';
            tmp = tmp->next;
        }
        cout << '\n';
    }
    void backwardTraversal()
    {
        Node* tmp = tail;
        for(ll i = sz - 1; i >= 0; i--)
        {
            cout << tmp->value << ' ';
            tmp = tmp->prev;
        }
        cout << '\n';
    }

    ll size(){return sz;}
    bool isEmpty(){return (sz == 0);}

    ~DoublyLinkedList()
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
//// TODO: swap , reverse , insertAfter
};


#endif //DATASTRUCTUREALGORITHMS_DOUBLYLINKEDLIST_H
