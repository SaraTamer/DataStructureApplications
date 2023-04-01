
#ifndef DATASTRUCTUREAPPLICATIONS_INFIXTOPOSTFIX_H
#define DATASTRUCTUREAPPLICATIONS_INFIXTOPOSTFIX_H

#include <iostream>
#include "Stack.h"

using namespace std;

short priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;
    return 0;
}
string infixToPostfix(string infix)
{
    Stack<char> operations;
    string postfix = "";

    for(int i = 0; i < infix.size(); i++)
    {
        if(infix[i] == ' '){postfix += infix[i];}
        else if(isdigit(infix[i]) || isalpha(infix[i])){postfix += infix[i];}    // for numbers and alphabets
        else if(infix[i] == '('){operations.push(infix[i]);}
        else if(infix[i] == ')')
        {
            while(operations.Top() != '(')
            {
                postfix += operations.pop();
            }
            operations.pop();
        }
        else
        {
            while(!operations.isEmpty() && priority(infix[i]) <= priority(operations.Top()))
            {
                postfix += operations.pop();
            }
            operations.push(infix[i]);
        }
    }
    while(!operations.isEmpty())
    {
        postfix += operations.pop();
    }

    return postfix;
}

#endif //DATASTRUCTUREAPPLICATIONS_INFIXTOPOSTFIX_H
