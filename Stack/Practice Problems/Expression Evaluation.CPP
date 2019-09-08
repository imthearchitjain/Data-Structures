#include <iostream>
#include <stack>
#include <string>
using namespace std;
int prec(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
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
int evaluate(string exp)
{
    stack<int> operand;
    stack<char> symbol;
    int n = exp.size();
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ')
            continue;
        else if (exp[i] == '(')
            symbol.push(exp[i]);
        else if (isdigit(exp[i]))
        {
            int val=0;
            while (i < n && isdigit(exp[i]))
            {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            operand.push(val);
        }
        else if (exp[i] == ')')
        {
            while (!symbol.empty() && symbol.top() != '(')
            {
                int a = operand.top();
                operand.pop();
                int b = operand.top();
                operand.pop();
                char op = symbol.top();
                symbol.pop();
                int temp = operation(a, b, op);
                operand.push(temp);
            }
            symbol.pop();
        }
        else
        {
            while (!symbol.empty() && prec(symbol.top()) >= prec(exp[i]))
            {
                int a = operand.top();
                operand.pop();
                int b = operand.top();
                operand.pop();
                char op = symbol.top();
                symbol.pop();
                int temp = operation(b, a, op);
                operand.push(temp);
            }
            symbol.push(exp[i]);
        }
        

    }
    while (!symbol.empty())
    {
        int val2 = operand.top();
        operand.pop();

        int val1 = operand.top();
        operand.pop();

        char op = symbol.top();
        symbol.pop();

        operand.push(operation(val1, val2, op));
    }
    return operand.top();
}
int main()
{
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
}
