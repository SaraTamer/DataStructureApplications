#include <iostream>
#include "InfixToPostfix.h"
#include "LongestValidParentheses.h"
#include "Queue.h"
#include "SingleLinkedList.h"


using namespace std;

int main()
{
    Queue<string> queue;
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");
    queue.enqueue("farah");

    
    queue.print();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.print();

    cout << queue.first()<<endl;

    cout << queue.queueSize() <<endl;

    cout << queue.isEmpty() <<endl;

    queue.clear();

    cout << queue.isEmpty()<<endl;







// Stack Applications

    // Infix to postfix testing
//
//    string expression = "(3+2)+7/2*((7+3)*2)";
//    string expression2 = "X^Y / (5*Z) + 2";
//    string expression3 = "A + B * C + D";
//    string expression4 = " (A + B) * (C + D)";
//    cout << infixToPostfix(expression4);

    // longest valid parentheses testing
//
//    string expression = "(()";
//    string expression2 = ")()())((()))";
//    cout << longestValidParentheses(expression2);

    return 0;
}
