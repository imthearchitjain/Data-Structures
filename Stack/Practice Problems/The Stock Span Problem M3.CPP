#include <iostream>
/*
STL Stack: functions to perform stack operations.
push()  : push element to stack , does not return anything.
pop()   : removes the top element from the stack without returning anything.
top()   : returns the top element of the stack.

syntax to create stack :
stack < data-type > name_of_stack;
*/
using namespace std;
void calculateSpan(int a[],int n,int stock[])
{
    stock[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int count = 1;
        while ((i - count) >= 0 && a[i] > a[i - count])
        {
            count += stock[i - count];
        }
        stock[i] = count;
    }
}
int main()
{
    int n,data;
    cout << "\nEnter the no of elements : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> a[i];
    }
    int stock[n];
    calculateSpan(a, n, stock);
    cout << "\nSpan of stocks :";
    for (int i = 0; i < n; i++)
    {
        cout << stock[i] << " ";
    }
}