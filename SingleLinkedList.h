//
// Created by DELL on 4/9/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_SINGLELINKEDLIST_H
#define DATASTRUCTUREAPPLICATIONS_SINGLELINKEDLIST_H
#include <iostream>
using namespace std;


#include <iostream>

#define ll long long

using namespace std;




template <class T>
class SingleLinkedList {
private:
public:

    struct Node;
    Node *head = new Node();
    Node *tail = new Node();
    ll sz;

    SingleLinkedList()
    {
        head = tail = nullptr;
        sz =0;
    }

    void insertAtHead(T item);
    void insertAtTail(T item);
    void insertAt(T item , ll index);

    void removeAtHead();
    void removeAtTail();
    void removeAt(ll index);

    T retrieveAt(ll index);
    void replaceAt(T item , ll index);

    bool isExist(T item);
    bool isItemAtEqual(T item , ll index);

    void swap (int index1,int index2);

    ll size(){return sz;}
    bool isEmpty(){return (sz == 0);}

    void print();

    void clear();

    SingleLinkedList& operator=(const SingleLinkedList& list);

    ~SingleLinkedList();
};

template <class T>
struct SingleLinkedList<T>::Node {
    Node *next;
    T value;
};
template<class T>
void SingleLinkedList<T>::insertAtHead(T item) {
    Node *tmp = new Node;
    tmp->value = item;
    if (isEmpty()) {
        head = tail = tmp;
        tmp->next = nullptr;
    } else {
        tmp->next = head;

        head = tmp;
    }
    sz++;
}

template<class T>
void SingleLinkedList<T>::insertAtTail(T item) {
    Node *tmp = new Node;
    tmp->value = item;
    if(isEmpty())
    {
        head = tail = tmp;
        tmp->next = nullptr;
    }
    else
    {
        tail->next = tmp;
        tmp->next = nullptr;
        tail = tmp;
    }
    sz++;

}

template<class T>
void SingleLinkedList<T>::insertAt(T item, long long int index) {
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
        Node *temp = head;
        Node *newNode = new Node;
        newNode->value = item;
        for (ll i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

        sz++;
    }

}

template<class T>
void SingleLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        cout << "list is empty nothing to be removed \n";
        return;
    }

    else if (sz == 1){
        delete head;
        head = nullptr;
        tail = head;
        sz--;
        return;
    }
    else{
        Node *temp = head;
        head = head->next;
        free(temp);
        sz--;
    }


}

template<class T>
void SingleLinkedList<T>::removeAtTail() {
    if(isEmpty())
    {
        cout << "The list is empty nothing to be removed \n";
        return;
    }
    else if(sz == 1)
    {
        delete head;
        head = tail = nullptr;
        sz--;
        return;
    }
    else{
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        temp->next = nullptr;
        tail = temp;
        sz--;
    }


}

template<class T>
void SingleLinkedList<T>::removeAt(long long int index) {
    if(index >= sz || index < 0)
    {
        cout << "Position out of scope!\n";
        return;
    }
    else if(index == 0)
    {
        removeAtHead();
        return;
    }
    else if(index == sz -1)
    {
        removeAtTail();
        return;
    }
    else{
        int counter = 0;
        Node *temp = head;

        while (counter < index - 1){
            temp = temp->next;
            counter++;
        }

        Node *target = temp->next;
        temp->next = target->next;
        delete target ;
        sz--;
    }


}

template<class T>
T SingleLinkedList<T>::retrieveAt(long long int index) {
    if(index >= sz || index < 0)
    {
        cout << "Position out of scope!\n";
        exit(1);
    }
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

template<class T>
void SingleLinkedList<T>::replaceAt(T item, long long int index) {
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

template<class T>
bool SingleLinkedList<T>::isExist(T item) {

    Node* tmp = head;
    for(ll i = 0; i < sz; i++)
    {
        if(tmp->value == item) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template<class T>
bool SingleLinkedList<T>::isItemAtEqual(T item, long long int index) {
    if(isEmpty())
    {
        cout << "The list is EMPTY!\n";
        exit(1);
    }
    else if(index < 0 || index >= sz)
    {
        cout << "Position out of scope!\n";
        exit(1);
    }
    else{
        Node* tmp = head;
        for(ll i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return (tmp->value == item);
    }
}


template<class T>
void SingleLinkedList<T>::swap(int index1, int index2) {


}

template<class T>
void SingleLinkedList<T>::print() {
    Node *temp = head;
    while (temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;


}


template<class T>
void SingleLinkedList<T>::clear() {
    while (!isEmpty()){
        removeAtTail();
    }

}


template <class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList& list)
{
    this->clear();
    SingleLinkedList<T> tmp;
    tmp.head = list.head;
    for(ll i = 0; i < list.sz; i++)
    {
        this->insertAtTail(tmp.head->value);
        tmp.head = tmp.head->next;
    }
    return *this;
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList() {
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



#endif //DATASTRUCTUREAPPLICATIONS_SINGLELINKEDLIST_H
