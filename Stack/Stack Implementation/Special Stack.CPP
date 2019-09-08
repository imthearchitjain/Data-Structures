// stack implementation using array
#include <iostream>
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
    bool isFullStack()
    {
        return top == Max - 1;
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
        if (i >= 0)
            cout << "\nTop->";
        while (i >= 0)
        {
            cout << a[i] << " ";
            i--;
        }
        cout << "\n";
    }
};
class SpecialStack:public stack
{
    stack min;
public:
    int pop();
    void push(int data);
    int getMin();
};
int SpecialStack::getMin()
{
    int x = min.pop();
    min.push(x);
    return x;
}
void SpecialStack::push(int data)
{
    if(isEmptyStack())
    {
        stack::push(data);
        min.push(data);
    }
    else
    {
        stack::push(data);
        int y = min.peek();
        if (data <= y)
            min.push(data);
    }
    
}
int SpecialStack::pop()
{
    int x = stack::pop();
    int y = min.pop();

    /* Push the popped element y  back only if it is not equal to x */
    if (y != x)
        min.push(y);
    return x;
}

int main()
{
    SpecialStack s;
    int n, data;
    cout << "\nEnter the no  of elements you want to enter :";
    cin >> n;
    while(n--)
    {
        cin >> data;
        s.push(data);
    }
    cout << "\nThe minimum element is : " << s.getMin();
}
