// USING STL STACK
#include <iostream>
using namespace std;
#define Max 100
class stack
{
public:
    int arr[Max];
    int top;

    stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == Max - 1;
    }
    int peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        else
        {
            cout << "\nStack is empty...";
            return INT16_MIN;
        }
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "\nStack is Full ...";
            return;
        }
        arr[++top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty .";
            return INT16_MIN;
        }
        return arr[top--];
    }
};

stack sortStack(stack input)
{
    stack tmpStack;

    while (!input.isEmpty())
    {

        int tmp = input.pop();

        while (!tmpStack.isEmpty() && tmpStack.peek() < tmp)
        {
            input.push(tmpStack.pop());
        }

        tmpStack.push(tmp);
    }

    return tmpStack;
}
void sortArrayUsingStacks(int a[], int n)
{
    stack s;
    for (int i = 0; i < n; i++)
        s.push(a[i]);

    stack tmps = sortStack(s);
    for (int i = 0; i < n; i++)
        a[i] = tmps.pop();
}
void printStack(stack s)
{
    while (!s.isEmpty())
    {
        cout << s.arr[s.top--] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {1, 6, 3, 5, 2, 4};
    int n = sizeof(a) / sizeof(a[0]);
    sortArrayUsingStacks(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
