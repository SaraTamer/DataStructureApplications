//
// Created by DELL on 4/9/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_QUEUE_H
#define DATASTRUCTUREAPPLICATIONS_QUEUE_H


#include <iostream>
#include "SingleLinkedList.h"

template<class T>
class Queue{
private:
    SingleLinkedList<T> s;
public:

    void enqueue (T element);
    T dequeue ();
    T first () ;
    bool isEmpty ();
    int queueSize ();
    void clear ();
    void print ();

};

template<class T>
void Queue<T>::enqueue(T element) {
    s.insertAtTail(element);

}

template<class T>
T Queue<T>::dequeue() {
    T value = s.retrieveAt(0);
    s.removeAtHead();
    return value;
}

template<class T>
T Queue<T>::first() {

    return s.retrieveAt(0);
}

template<class T>
bool Queue<T>::isEmpty() {
    return s.isEmpty();
}

template<class T>
int Queue<T>::queueSize() {
    return s.size();
}

template<class T>
void Queue<T>::clear() {
    s.clear();

}

template<class T>
void Queue<T>::print() {
    s.print();

}


#endif //DATASTRUCTUREAPPLICATIONS_QUEUE_H
