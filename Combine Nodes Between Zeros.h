//
// Created by DELL on 4/28/2023.
//

#ifndef DATASTRUCTUREAPPLICATIONS_COMBINE_NODES_BETWEEN_ZEROS_H
#define DATASTRUCTUREAPPLICATIONS_COMBINE_NODES_BETWEEN_ZEROS_H

#include "SingleLinkedList.h"
#include "Stack.h"

void combine(SingleLinkedList<int> &list){
   Node<int>*temp = list.head;

    //temp->value = list.head->value;

    SingleLinkedList<int>list2;

    while(temp->value == 0 && temp->next != nullptr){
        temp = temp->next;
        int result = 0;

        while (temp->value != 0){

            result += temp->value;

            temp = temp->next;
        }

        list2.insertAtTail(result);

    }
    list.clear();
    list = list2;

}


//};


#endif //DATASTRUCTUREAPPLICATIONS_COMBINE_NODES_BETWEEN_ZEROS_H
