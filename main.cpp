#include <iostream>
#include "InfixToPostfix.h"

using namespace std;

int main()
{
//// Stack Applications

    //// Infix to postfix testing

    string expression = "(3+2)+7/2*((7+3)*2)";
    string expression2 = "X^Y / (5*Z) + 2";
    string expression3 = "A + B * C + D";
    string expression4 = " (A + B) * (C + D)";
    cout << infixToPostfix(expression4);

    return 0;
}
