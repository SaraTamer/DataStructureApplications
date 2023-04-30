
#ifndef DATASTRUCTUREAPPLICATIONS_MERGESORTEDLINKEDLISTS_H
#define DATASTRUCTUREAPPLICATIONS_MERGESORTEDLINKEDLISTS_H

#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

template<class T>
SingleLinkedList<int> merge(Node<T>* h1 ,Node<T>* h2)
{
    SingleLinkedList<int> subMerged;
    if(h2 != nullptr)
    {
        if(h1->value < h2->value)
        {
            subMerged.insertAtTail(h1->value);
            h1 = h1->next;
        }
        else
        {
            subMerged.insertAtTail(h2->value);
            h2 = h2->next;
        }
        while(h1 != nullptr && h2 != nullptr)
        {
            if(h1->value < h2->value)
            {
                subMerged.insertAtTail(h1->value);
                h1 = h1->next;
            }
            else
            {
                subMerged.insertAtTail(h2->value);
                h2 = h2->next;
            }
        }
        while(h1 != nullptr)
        {
            subMerged.insertAtTail(h1->value);
            h1 = h1->next;
        }
        while (h2 != nullptr)
        {
            subMerged.insertAtTail(h2->value);
            h2 = h2->next;
        }
    }
    else
    {
        while(h1 != nullptr)
        {
            subMerged.insertAtTail(h1->value);
            h1 = h1->next;
        }
    }

    return subMerged;
}

template<class T>
SingleLinkedList<int> mergeKLists(Node<T>* h[] , int k)
{
    SingleLinkedList<int> merged;
    while (k--)
    {
        merged = merge(*h, merged.head);
        h++;
    }
    return merged;
}

#endif //DATASTRUCTUREAPPLICATIONS_MERGESORTEDLINKEDLISTS_H
