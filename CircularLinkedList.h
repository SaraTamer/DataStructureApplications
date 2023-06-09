//
// Created by DELL on 4/9/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_CIRCULARLINKEDLIST_H
#define DATASTRUCTUREAPPLICATIONS_CIRCULARLINKEDLIST_H

//
// Created by DELL on 4/9/2023.
//


#include <iostream>

#define ll long long

using namespace std;


template <class T>
class CircularLinkedList {
private:
    struct Node {
        Node *next;
        T value;

        Node() {
            value = 0;

        }
    };

    Node *head = new Node();
    Node *tail = new Node();
    ll sz;

public:
    CircularLinkedList()
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

    ~CircularLinkedList();


};


template<class T>
void CircularLinkedList<T>::insertAtHead(T item) {
    Node *tmp = new Node;
    tmp->value = item;
    if (isEmpty()) {
        head = tail = tmp;
        tmp->next = head;
    }
    else {
        tmp->next = head;
        head = tmp;
    }
    sz++;
}

template<class T>
void CircularLinkedList<T>::insertAtTail(T item) {
    Node *tmp = new Node;
    tmp->value = item;
    if(isEmpty())
    {
        head = tail = tmp;
        tmp->next = head;
    }
    else
    {
        tail->next = tmp;
        tmp->next = head;
        tail = tmp;
    }
    sz++;

}

template<class T>
void CircularLinkedList<T>::insertAt(T item, long long int index) {
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
void CircularLinkedList<T>::removeAtHead() {
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
        tail->next = head;
        delete (temp);
        sz--;
    }


}

template<class T>
void CircularLinkedList<T>::removeAtTail() {
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
        temp->next = head;
        tail = temp;
        sz--;
    }


}

template<class T>
void CircularLinkedList<T>::removeAt(long long int index) {
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
T CircularLinkedList<T>::retrieveAt(long long int index) {
    if(index >= sz || index < 0)
    {
        cout << "Position out of scope!\n";
        return T();
    }
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

template<class T>
void CircularLinkedList<T>::replaceAt(T item, long long int index) {
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
bool CircularLinkedList<T>::isExist(T item) {

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
bool CircularLinkedList<T>::isItemAtEqual(T item, long long int index) {
    if(isEmpty())
    {
        cout << "The list is EMPTY!\n";
        return false;
    }
    else if(index < 0 || index >= sz)
    {
        cout << "Position out of scope!\n";
        return false;
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
void CircularLinkedList<T>::swap(int index1, int index2) {
    if (isEmpty()) {                            // check if the list is empty
        cout << "The list is EMPTY!\n";
        return;
    } else if (index1 < 0 || index1 >= sz || index2 < 0 || index2 >= sz ) { // check if indices are out of range
        cout << "Position out of scope!\n";
        return;
    } else if (index1 == index2) {              // check if indices are the same
        return;
    }

    Node* temp1 = head;
    Node* prev1 = nullptr;


    for (ll i = 0; i < index1; i++) {       //prev1 is to point to the nodes to be swapped
        prev1 = temp1;
        temp1 = temp1->next;
    }

    Node* temp2 = head;
    Node* prev2 = nullptr;


    for (ll i = 0; i < index2 ; i++) {    //prev2 is to point to the nodes to be swapped
        prev2 = temp2;
        temp2 = temp2->next;
    }

    // update the previous node's next pointer to point to the swapped node
    if (prev1) {                        //if there is a previous node
        prev1->next = temp2;             //connect it to the other node to be swapped
    }
    else {
        head = temp2;                    //make the other node as the head
    }

    // update the previous node's next pointer to point to the swapped node
    if (prev2) {
        prev2->next = temp1;
    } else {
        head = temp1;
    }

    // swap the next pointers of the nodes
    Node* temp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp;

    if (index2 == sz-1){
        tail=temp1;
        tail->next = head;
    }




}

template<class T>
void CircularLinkedList<T>::print() {
    Node *temp = head;
    for (int i = 0; i < sz; ++i) {
        cout << temp->value << " ";
        temp = temp->next;
    }


}


template<class T>
void CircularLinkedList<T>::clear() {
    while (!isEmpty()){
        removeAtTail();
    }

}




template<class T>
CircularLinkedList<T>::~CircularLinkedList() {
    Node *tmp;
    for(ll i = 0; i < sz; i++)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    sz = 0;

}




#endif //DATASTRUCTUREAPPLICATIONS_CIRCULARLINKEDLIST_H
