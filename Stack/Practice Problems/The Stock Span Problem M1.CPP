#include <iostream>
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
int spanStock(stack<int> s)
{
    int j = 1;
    int a = s.top();
    s.pop();
    while(!s.empty() && s.top()<=a)
    {
        j++;
        s.pop();
    }
    return j;
}
int main()
{
    stack<int> s;
    int n,data;
    cout << "\nEnter the no of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s.push(data);
    }
    int stock[n];
    for (int i = n-1; i >= 0; i--)
    {
        stock[i] = spanStock(s);
        s.pop();
    }
    cout << "\nSpan of stocks :";
    for (int i = 0; i < n; i++)
    {
        cout << stock[i] << " ";
    }
}