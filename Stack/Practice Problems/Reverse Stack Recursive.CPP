#include<iostream>
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
        if(!isEmpty())
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
        if(isFull())
        {
            cout << "\nStack is Full ...";
            return;
        }
        arr[++top] = data;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "\nStack is empty .";
            return INT16_MIN;
        }
        return arr[top--];
    }
};
void insertBottom(stack &s,int x)
{
    if(s.isEmpty())
        s.push(x);
    else
    {
        int a = s.pop();
        insertBottom(s, x);
        s.push(a);
    }
    
}
void reverse(stack &s)
{
    if(s.isEmpty())
        return;
    else
    {
        int x = s.pop();
        reverse(s);
        insertBottom(s, x);
    }
    
}
void printStack(stack s)
{
    while(!s.isEmpty())
    {
        cout << s.arr[s.top--] << " ";
    }
    cout << endl;
}
int main()
{
    stack s;
    int n, data;
    cout << "\nEnter the no of elements in the stack : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s.push(data);
    }
    printStack(s);
    reverse(s);
    printStack(s);
}