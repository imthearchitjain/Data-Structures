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
    void pop()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty .";
            return;
        }
        top--;
    }
};
void remove(int arr[], int &n, int k)
{
    stack s;
    int count = 0;
    for (int i = 0; i < n ; i++)
    {
        if(i==0)
        {
            s.push(arr[i]);
        }
        while(arr[i] >= s.peek() && count < k && !s.isEmpty())
        {
            s.pop();
            count++;
        }
        s.push(arr[i]);
    }
    n = n - count;
    for (int i = n-1; i >=0; i--)
    {
        arr[i] = s.peek();
        s.pop();
    }
}
int main()
{
    int arr[] = {10, 20, 25, 30, 40};
    int k = 2;
    int n = 5;
    remove(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
