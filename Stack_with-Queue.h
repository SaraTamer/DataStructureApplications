//
// Created by farah on 4/27/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_STACK_WITH_QUEUE_H
#define DATASTRUCTUREAPPLICATIONS_STACK_WITH_QUEUE_H


#include "Queue.h"

template <class T>
class Stack_Q {
private:
    Queue<T> q1, q2;

public:

    void push(T x);
    T pop();
    bool isEmpty();
    T top();
    int stackSize ();
    void clear ();
    void print ();
};

template<class T>
void Stack_Q<T>::push(T x) {

    q1.enqueue(x);                    //puts element in the back

}

template<class T>
T Stack_Q<T>::pop() {
    if (isEmpty()) {
        cout << "stack empty nothing to pop ";
        return -1;
    }

    while (q1.queueSize() > 1) {
        q2.enqueue(q1.first());      //puts all element in the second queue in reverse except the last ont
        q1.dequeue();                // and removes  them from the first queue
    }

    int result = q1.first();        //stores the element to be popped
    q1.dequeue();

    q1 = q2;                        //puts all the elements back into the original queue

    while (!q2.isEmpty()) {
        q2.dequeue();               //removes them from the second queue (empty out the second queue)
    }

    return result;
}

template<class T>
bool Stack_Q<T>::isEmpty() {
    return q1.isEmpty();
}

template<class T>
T Stack_Q<T>::top() {
    while (q1.queueSize() > 1) {
        q2.enqueue(q1.first());      //puts all element in the second queue in reverse except the last ont
        q1.dequeue();                // and removes  them from the first queue
    }

    int result = q1.first();        //stores the element to be popped

    q1 = q2;                        //puts all the elements back into the original queue

    while (!q2.isEmpty()) {
        q2.dequeue();               //removes them from the second queue (empty out the second queue)
    }

    return result;

}

template<class T>
int Stack_Q<T>::stackSize() {
    return q1.queueSize();
}

template<class T>
void Stack_Q<T>::clear() {
    q1.clear();

}

template<class T>
void Stack_Q<T>::print() {
    q1.print();

}

#endif //DATASTRUCTUREAPPLICATIONS_STACK_WITH_QUEUE_H
