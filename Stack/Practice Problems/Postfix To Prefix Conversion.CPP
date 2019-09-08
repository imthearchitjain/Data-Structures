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
// Convert postfix to Prefix expression
string postToPre(string post_exp)
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
            string temp = post_exp[i] + op2 + op1;
            s.push(temp);
        }
        else
            s.push(string(1, post_exp[i]));
        
    }
    return s.top();
}
int main()
{
    string post_exp = "ABC/-AK/L-*";
    cout << "Prefix : " << postToPre(post_exp);
    return 0;
}
