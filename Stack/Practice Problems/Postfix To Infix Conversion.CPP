#include <iostream>
#include <string>
#include <stack>
/*
STL Stack: functions to perform stack operations.
push()  : push element to stack , does not return anything.
pop()   : removes the top element from the stack without returning anything.
top()   : returns the top element of the stack.

syntax to create stack :
stack < data-type > name_of_stack;
*/

using namespace std;
int prec(char t)
{
    if (t == '^')
        return 3;
    else if (t == '*' || t == '/')
        return 2;
    else if (t == '+' || t == '-')
        return 1;
    else
        return -1;
}
bool isOperand(char t)
{
    if (t >= 65 && t <= 90)
        return 1;
    else if (t >= 97 && t <= 122)
        return 1;
    return 0;
}
bool isOperator(char t)
{
    if (t == '^' || t == '/' || t == '*' || t == '+' || t == '-')
        return 1;
    return 0;
}
string postToInfix(string post_exp)
{
    stack<string> s;
    int n = post_exp.size();
    for (int i = 0; i < n; i++)
    {
        if (isOperator(post_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op2 + post_exp[i] + op1 + ")";
            s.push(temp);
        }
        else
            s.push(string(1, post_exp[i]));
    }
    return s.top();
}
int main()
{
    string str, infix;
    stack<char> s;
    int count = 0;
    cout << "\nEnter the postfix expression : ";
    getline(cin, str);
    cout << "\nEvaluated infix expression : " << postToInfix(str);
    
}