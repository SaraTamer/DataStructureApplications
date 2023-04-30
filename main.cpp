#include <iostream>
#include "SingleLinkedList.h"
#include "InfixToPostfix.h"
#include "LongestValidParentheses.h"
#include "MergeSortedLinkedLists.h"
#include "GenerateBinaryNumbers.h"
#include "Stack_with-Queue.h"
#include "sorting Queue.h"
#include "Combine Nodes Between Zeros.h"
#include "DoublyLinkedList.h"

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
//    sort_Q(Q);
//    Q.print();


//// test linked list

    DoublyLinkedList<int> list;

    // Test inserting at head and tail
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    cout << "Expected output: 2 1 3 4" << endl;
    list.forwardTraversal();

    // Test inserting at a specific index
    list.insertAt(5, 0); // should become new head
    list.insertAt(6, list.size()); // should become new tail
    list.insertAt(7, 3);
    cout << "Expected output: 5 2 1 7 3 4 6" << endl;
    list.forwardTraversal();


    // Test removing from head and tail
    list.removeAtHead();
    list.removeAtTail();
    list.removeAtTail();
    cout << "Expected output: 2 1 7 3" << endl;
    list.forwardTraversal();


    // Test removing from a specific index
    list.removeAt(0); // should become new head
    cout << "Expected output: 1 7 3" << endl;
    list.forwardTraversal();

    // Test retrieving an item at a specific index
    cout << "Expected output: 1" << endl;
    cout << list.retrieveAt(0) << endl;
    cout << "Expected output: 3" << endl;
    cout << list.retrieveAt(list.size()-1) << endl;
    cout << "Expected output: 7" << endl;
    cout << list.retrieveAt(1) << endl;

    // Test replacing an item at a specific index
    list.replaceAt(8, 0); // should become new head
    list.replaceAt(9, list.size()-1); // should become new tail
    list.replaceAt(10, 1);
    list.insertAt(7,2);
    cout << "Expected output: 8 10 7 9" << endl;
    list.forwardTraversal();

    // Test swapping two items at specific indices
    list.swap(0, 1); // should swap head and second item        //10 8 7 9
    list.swap(list.size()-2, list.size()-1); // should swap tail and second-to-last item  // 10 8 9 7
    list.swap(1, 2); // should swap two items in the middle     // 10 9 8 7
    list.swap(1,3);
    cout << "Expected output: 10 7 8 9" << endl;
    list.forwardTraversal();

    // Test checking if an item exists in the list and if an item at a specific index is equal to a given item
    cout << "Expected output: true" << endl;
    cout << list.isExist(8) << endl;
    cout << "Expected output: false" << endl;
    cout << list.isExist(11) << endl;
    cout << "Expected output: true" << endl;
    cout << list.isItemAtEqual(7, 1) << endl;
    cout << "Expected output: true" << endl;
    cout << list.isItemAtEqual(8, 2) << endl;

    // Test the size and isEmpty functions
    cout << "Expected output: 4" << endl;
    cout << list.size() << endl;
    cout << "Expected output: false" << endl;
    cout << list.isEmpty() << endl;

    // Test copying and clearing the list
//    SingleLinkedList<int> list_copy;
//    list_copy = list;
//    list_copy.insertAtHead(11);
//    list_copy.insertAtTail(12);
//    cout << "Original list: ";
//    list.forwardTraversal();
//    cout << "Copy of list: ";
//    list_copy.print();
//
//    list_copy = list;
//    list.clear();
//    cout << "Expected output: true" << endl;
//    cout << list.isEmpty() << endl;
//    cout << "Expected output: 4" << endl;
//    cout << list_copy.size() << endl;
//    cout << "Expected output: 10 7 8 9" << endl;
//    list_copy.print();

//// Test removing all items and checking the size and isEmpty functions
//    list_copy.clear();
//    cout << "Expected output: true" << endl;
//    cout << list_copy.isEmpty() << endl;
//    cout << "Expected output: 0" << endl;
//    cout << list_copy.size() << endl;

    return 0;
}
