

#ifndef DATASTRUCTUREAPPLICATIONS_LONGESTVALIDPARENTHESES_H
#define DATASTRUCTUREAPPLICATIONS_LONGESTVALIDPARENTHESES_H


#include "Stack.h"
#include <iostream>

using  namespace std;

bool isPair(char left , char right)
{
    if(left == '(' && right == ')')
        return true;
    if(left == '[' && right == ']')
        return true;
    if(left == '{' && right == '}')
        return true;
    return false;
}
int longestValidParentheses(string str)
{
    int count = 0;
    int maxCount = 0;
    Stack<char> stack;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            stack.push(str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(!stack.isEmpty() && isPair(stack.Top(), str[i]))
            {
                stack.pop();
                count+=2;
                maxCount = max(maxCount, count);
            }
            else{
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
    }

    return maxCount;
}
#endif //DATASTRUCTUREAPPLICATIONS_LONGESTVALIDPARENTHESES_H
