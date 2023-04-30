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
    void insertAtHead(T item);
    void insertAtTail(T item);
    void insertAt(T item , ll index);
    void insertAfter(Node * prv, T item);

    void swap(ll fIndex, ll sIndex);

    void removeAtHead();
    void removeAtTail();
    void removeAt(ll index);

    T retrieveAt(ll index);

    void replaceAt(T item , ll index);

    bool isExist(T item);
    bool isItemAtEqual(T item , ll index);

    void reverse();
    void clear();

    void forwardTraversal();
    void backwardTraversal();

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
//// TODO: swap , testing of insertAfter
};

template <class T>
void DoublyLinkedList<T>::insertAtHead(T item)
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

template <class T>
void DoublyLinkedList<T>::insertAtTail(T item)
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

template <class T>
void DoublyLinkedList<T>::insertAt(T item , ll index)
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
template<class T>
void DoublyLinkedList<T>::swap(ll fIndex, ll sIndex)
{
    if(fIndex > sz || fIndex < 0 || sIndex > sz || sIndex < 0)
    {
        cout << "Position out of scope!\n";
        return;
    }
    if(fIndex == sIndex)
        return;
    Node* tmp1 = head;
    Node* tmp2 = head;
    for(ll i = 0; i < sz; i++)
    {
        if(i == fIndex)
            break;
        tmp1 = tmp1->next;
    }
    for(ll i = 0; i < sz; i++)
    {
        if(i == sIndex)
            break;
        tmp2 = tmp2->next;
    }
    if(tmp1 != head)
    {
        tmp1->prev->next = tmp2;
    }
    if(tmp1 != tail && tmp1->next != tmp2)
        tmp1->next->prev = tmp2;

    if(tmp2 != head && tmp1->next != tmp2)
    {
        tmp2->prev->next = tmp1;
    }
    if(tmp2 != tail)
        tmp2->next->prev = tmp1;

    Node* prevTmp = tmp1->prev;
    Node* nextTmp = tmp1->next;

    if(tmp1->next == tmp2)
    {
        tmp1->next = tmp2->next;
        tmp2->prev = prevTmp;
        tmp1->prev = tmp2;
        tmp2->next = tmp1;
    }
    else
    {
        tmp1->next = tmp2->next;
        tmp1->prev = tmp2->prev;
        tmp2->next = nextTmp;
        tmp2->prev = prevTmp;
    }
    if(tmp1 == head)
    {
        head = tmp2;
    }
    else if(tmp2 == head)
        head = tmp1;

    if(tmp1 == tail)
        tail = tmp2;
    else if(tmp2 == tail)
        tail = tmp1;

}
template <class T>
void DoublyLinkedList<T>::insertAfter(Node * prv, T item)
{
    Node* tmp = new Node;
    tmp->value = item;
    tmp->prev = prv;
    tmp->next = prv->next;
    prv->next->prev = tmp;
    prv->next = tmp;
}

template <class T>
void DoublyLinkedList<T>::removeAtHead()
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

template <class T>
void DoublyLinkedList<T>::removeAtTail()
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
template <class T>
void DoublyLinkedList<T>::removeAt(ll index)
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
template <class T>
T DoublyLinkedList<T>::retrieveAt(ll index)
{
    if(isEmpty())
    {
        cout << "The list is EMPTY!\n";
        return T();
    }

    Node* tmp = head;
    for(ll i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp->value;
}
template <class T>
void DoublyLinkedList<T>::replaceAt(T item , ll index)
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
template <class T>
bool DoublyLinkedList<T>::isExist(T item)
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
template <class T>
bool DoublyLinkedList<T>::isItemAtEqual(T item , ll index)
{
    if(isEmpty())
    {
        cout << "The list is EMPTY!\n";
        return T();
    }

    Node* tmp = head;
    for(ll i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return (tmp->value == item);
}
template <class T>
void DoublyLinkedList<T>::reverse()
{
    Node *tmp = head;
    Node *prv = nullptr;
    while (tmp != nullptr)
    {
        tmp->prev = tmp->next;
        tmp->next = prv;
        prv = tmp;
        tmp = tmp->prev;
    }
    tail = head;
    head = prv;
}
template <class T>
void DoublyLinkedList<T>::clear()
{
    while(!isEmpty())
        removeAtHead();
}

template <class T>
void DoublyLinkedList<T>::forwardTraversal()
{
    Node* tmp = head;
    for(ll i = 0; i < sz; i++)
    {
        cout << tmp->value << ' ';
        tmp = tmp->next;
    }
    cout << '\n';
}
template <class T>
void DoublyLinkedList<T>::backwardTraversal()
{
    Node* tmp = tail;
    for(ll i = sz - 1; i >= 0; i--)
    {
        cout << tmp->value << ' ';
        tmp = tmp->prev;
    }
    cout << '\n';
}


#endif //DATASTRUCTUREALGORITHMS_DOUBLYLINKEDLIST_H
