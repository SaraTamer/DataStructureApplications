#include <iostream>
#include "SingleLinkedList.h"
#include "InfixToPostfix.h"
#include "LongestValidParentheses.h"
#include "MergeSortedLinkedLists.h"
#include "GenerateBinaryNumbers.h"
#include "Stack_with-Queue.h"
#include "sorting Queue.h"
#include "Combine Nodes Between Zeros.h"


using namespace std;

int main()
{


//// Stack Applications

    // Infix to postfix testing

//    string expression = "(3+2)+7/2*((7+3)*2)";
//    string expression2 = "X^Y / (5*Z) + 2";
//    string expression3 = "A + B * C + D";
//    string expression4 = " (A + B) * (C + D)";
//    cout << infixToPostfix(expression4);

    // longest valid parentheses testing

//    string expression = "(()";
//    string expression2 = ")()())((()))";
//    cout << longestValidParentheses(expression2);


//// Linked List Applications

    // Merge K sorted Linked Lists
//    SingleLinkedList<int> lst1;
//    lst1.insertAtTail(1);
//    lst1.insertAtTail(4);
//    lst1.insertAtTail(5);
//    SingleLinkedList<int> lst2;
//    lst2.insertAtTail(1);
//    lst2.insertAtTail(3);
//    lst2.insertAtTail(4);
//    SingleLinkedList<int> lst3;
//    lst3.insertAtTail(2);
//    lst3.insertAtTail(6);
//    SingleLinkedList<int>::Node* arr[] = {lst1.head , lst2.head, lst3.head};
//    mergeKLists(arr, 3).print();

//    SingleLinkedList<int> lst1;
//    lst1.insertAtTail(1);
//    lst1.insertAtTail(3);
//    lst1.insertAtTail(5);
//    lst1.insertAtTail(7);
//    SingleLinkedList<int> lst2;
//    lst2.insertAtTail(2);
//    lst2.insertAtTail(4);
//    lst2.insertAtTail(6);
//    lst2.insertAtTail(8);
//    SingleLinkedList<int> lst3;
//    lst3.insertAtTail(0);
//    lst3.insertAtTail(9);
//    lst3.insertAtTail(10);
//    SingleLinkedList<int>::Node* arr[] = {lst1.head, lst2.head, lst3.head};
//    mergeKLists(arr, 3).print();



//     combine nodes between zeros

//    SingleLinkedList<int> list;
//    SingleLinkedList<int> list1;
//    list.insertAtTail(0);
//    list.insertAtTail(1);
//    list.insertAtTail(0);
//    list.insertAtTail(3);
//    list.insertAtTail(0);
//    list.insertAtTail(2);
//    list.insertAtTail(2);
//    list.insertAtTail(0);
//
//    list1 = list;
//    list.print();
//    combine(list);
//    list.print();
//    list1.print();
//







//// Queue Applications

    //Generate Binary numbers from 1 to n

//    generateBinaryNumbers<int>(100).print();










///    stack using q
//
//        Stack_Q<int> sq;
//        sq.push(1);
//        sq.push(2);
//        sq.push(3);
//        sq.print();
//
//        cout << sq.pop() << endl; // output: 3
//        cout << sq.pop() << endl; // output: 2
//        cout << sq.pop() << endl; // output: 1
//        cout << "is the stack empty ?"<<sq.isEmpty()<<endl;
//
//
//        sq.push(4);
//        sq.push(5);
//        sq.print();
//        cout << sq.stackSize()<<endl;
//        sq.clear();


///sorting Queue

//    Queue<int >Q;
//    Q.enqueue(2);
//    Q.enqueue(4);
//    Q.enqueue(7);
//    Q.enqueue(30);
//    Q.enqueue(1);
//    Q.enqueue(6);
//    Q.enqueue(3);
//    Q.enqueue(8);
//    Q.enqueue(0);
//    Q.dequeue();
//    Q.print();
//    Q.print();


    return 0;
}
