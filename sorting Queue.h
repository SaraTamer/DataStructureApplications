//
// Created by DELL on 4/28/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_SORTING_QUEUE_H
#define DATASTRUCTUREAPPLICATIONS_SORTING_QUEUE_H

#include "Queue.h"
#include "SingleLinkedList.h"



template<class T>
void insertion(SingleLinkedList<T>&list){

    for (int i = 1; i < list.size(); i++) {
        int temp = list.retrieveAt(i);

        for (int j = i; j > 0 && temp < list.retrieveAt(j - 1); j--) {

            list.replaceAt(list.retrieveAt(j-1),j);                               // if smaller place into the switch the places
            list.replaceAt(temp,j-1);
        }
    }
}


void sort_Q (Queue<int>&q){
    SingleLinkedList<int> list;
    while(!q.isEmpty()){
        list.insertAtTail(q.dequeue());      //remove all elements from queue and put them in a linked list
    }

    insertion(list);
    for (int i = 0; i <list.size() ; ++i) {
        q.enqueue(list.retrieveAt(i));   //put  all elements in the list back in queue
    }
    q.print();


}


#endif //DATASTRUCTUREAPPLICATIONS_SORTING_QUEUE_H
