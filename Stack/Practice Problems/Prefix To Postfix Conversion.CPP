// CPP Program to convert prefix to Infix
#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char t)
{
    if (t == '^' || t == '/' || t == '*' || t == '+' || t == '-')
        return 1;
    return 0;
}

// Convert prefix to postfix expression
string preToPost(string pre_exp)
{
    stack<string> s;
    int n = pre_exp.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (isOperator(pre_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + pre_exp[i];
            s.push(temp);
        }
        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}
