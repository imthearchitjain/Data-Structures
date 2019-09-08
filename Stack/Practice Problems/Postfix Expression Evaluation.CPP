#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOperator(char t)
{
    if (t == '^' || t == '/' || t == '*' || t == '+' || t == '-')
        return 1;
    return 0;
}
int operation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
}
bool isOperand(char t)
{
    if (t >= '0' && t <= '9')
        return 1;
    return 0;
}
int evaluate(string exp)
{
    stack<int> value;
    int n = exp.size();
    for (int i = 0; i < n; i++)
    {    
        if(isOperator(exp[i]))
        {
            int val2 = value.top();
            value.pop();
            int val1 = value.top();
            value.pop();
            value.push(operation(val1, val2, exp[i]));
        }
        else if(isOperand(exp[i]))
        {
            value.push(int(exp[i] - '0'));
        }
        
    }
    return value.top();
}
int main()
{
    cout << evaluate("2 3 1 * +9 -");
}
