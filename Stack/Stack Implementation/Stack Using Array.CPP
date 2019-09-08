// stack implementation using array
#include<iostream>
using namespace std;
#define Max 100
class stack
{
    int top;
    int a[Max];
public:
    stack()
    {
        top = -1;
    }
    void push(int s)
    {
        if (top <= Max - 1)
        {
            ++top;
            a[top] = s;
        }
        else
        {
            cout << "\nStack Overflow....\n";
            return;
        }
    }
    bool isEmptyStack()
    {
        if (top == -1)
            return true;
        return false;
    }
    int pop()
    {
        if (isEmptyStack())
        {
            cout << "\nStack Underflow....\n";
            return INT16_MIN;
        }
        return a[top--];
    }
    int peek()
    {
        if (isEmptyStack())
        {
            cout << "\nStack Underflow....\n";
            return INT16_MIN;
        }
        return a[top];
    }
    void printStack()
    {
        int i = top;
        if(i>=0)
            cout << "\nTop->";
        while(i>=0)
        {
            cout << a[i] << " ";
            i--;
        }
        cout << "\n";
    }

};
int main()
{
    stack s;
    int n;
    s.printStack();
    cout << "\nEnter the no of elements to be pushed : ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter data :";
        cin >> data;
        s.push(data);
    }
    s.printStack();
    cout << "\nPopped Element is : " << s.pop();
    s.printStack();
}
