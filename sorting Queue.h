//
// Created by DELL on 4/28/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_SORTING_QUEUE_H
#define DATASTRUCTUREAPPLICATIONS_SORTING_QUEUE_H

#include "Queue.h"
#include "SingleLinkedList.h"

//
//
//template<class T>
//void insertion(SingleLinkedList<T>&list){
//
//    for (int i = 1; i < list.size(); i++) {
//        int temp = list.retrieveAt(i);
//
//        for (int j = i; j > 0 && temp < list.retrieveAt(j - 1); j--) {
//
//            list.replaceAt(list.retrieveAt(j-1),j);                               // if smaller place into the switch the places
//            list.replaceAt(temp,j-1);
//        }
//    }
//}
//
//


void reverseQueue(Queue<int>& q) {
    if (q.isEmpty()) {
        return;
    }
    int front = q.first();
    q.dequeue();
    reverseQueue(q);
    q.enqueue(front);
}

template<class T>
void sort_Q (Queue<T>&q){
    Queue<T>q2;
    for (int i = 0; i <q.queueSize() ; ++i) {

        T min_element = q.dequeue();
        while(!q.isEmpty()) {
            T current = q.dequeue();
            if(min_element >= current){
                q2.enqueue(min_element);
                min_element = current;
            }
            else{
                q2.enqueue(current);
            }
        }


        q2.enqueue(min_element);
        while(!q2.isEmpty()){

            q.enqueue(q2.dequeue());
        }




    }
    reverseQueue(q);

}






#endif //DATASTRUCTUREAPPLICATIONS_SORTING_QUEUE_H
