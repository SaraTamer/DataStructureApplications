

#ifndef DATASTRUCTUREAPPLICATIONS_GENERATEBINARYNUMBERS_H
#define DATASTRUCTUREAPPLICATIONS_GENERATEBINARYNUMBERS_H

#include <iostream>
#include "Queue.h"

using namespace std;

int converToBinary(int n)
{
    int decimal, binary = 0, remainder, product = 1 ;
    decimal = n;
    while (decimal != 0)
    {
        remainder = decimal % 2;
        binary = binary + (remainder * product);
        decimal = decimal / 2;
        product *= 10;
    }
    return binary;
}

template <class T>
Queue<T> generateBinaryNumbers(int n)
{
    Queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.enqueue(converToBinary(i));
    }
    return q;
}

#endif //DATASTRUCTUREAPPLICATIONS_GENERATEBINARYNUMBERS_H
