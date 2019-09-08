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
int main()
{
    string str ,infix;
    stack<char> s;
    int count = 0;
    cout << "\nEnter the prefix expression : ";
    getline(cin, str);
    int n = str.length();
    cout << "\nEvaluated infix expression : ";
    for (int i = 0; i < n; i++)
    {
        if (isOperator(str[i]))
        {
            s.push(str[i]);            
        }
        else if (isOperand(str[i]))
        {
            count++;
            if (isOperand(str[i - 1]))
            {
                cout << str[i];
                do
                {
                    cout << ")";
                    count--;
                } while (count > 1);
                count = 0;
                cout << s.top();
                s.pop();
                if (s.empty())
                    cout << "(";
            }
            else
            {
                cout << "(" << str[i] << s.top();
                s.pop();
            }
            
        }   
        
    }
    cout << ")";
    
}