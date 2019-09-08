#include <iostream>
#include <algorithm>
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
string infixTopost(string str)
{
    int n = str.length();
    string output;
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (isOperand(str[i]))
            output += str[i];
        else if (isOperator(str[i]))
        {
            while (!s.empty() && prec(str[i]) <= prec(s.top()))
            {
                output += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            while (s.top() != '(')
            {
                output += s.top();
                s.pop();
            }
            if (s.top() == '(')
                s.pop();
        }
    }
    while (!s.empty())
    {
        output += s.top();
        s.pop();
    }
    return output;
}
string infixToPrefix(string s)
{
    reverse(s.begin(),s.end());
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    s = infixTopost(s);
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string str;

    cout << "\nEnter the expression : ";
    getline(cin, str);

    cout << "\nEvaluated prefix expression : " << infixToPrefix(str);
}