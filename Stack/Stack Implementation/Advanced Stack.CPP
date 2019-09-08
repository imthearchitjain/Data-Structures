#include<iostream>
using namespace std;
#define Max 100
class Advancedstack
{
public:
    int arr[Max];
    int top;
    int minimum;

    Advancedstack()
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

    void push(int data)
    {
        if(isFull())
        {
            cout << "\nStack is Full ...";
            return;
        }
        if (top == -1)
        {
            minimum = data;
            arr[++top] = data;
        }
        else
        {
            if (data < minimum)
            {
                arr[++top] = 2 * data - minimum;
                minimum = data;
            }
            else
            {
                arr[++top] = data;
            }
            
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "\nStack is empty .";
            return INT16_MIN;
        }
        if (arr[top] >= minimum)
            return arr[top];
        else
        {
            int d = minimum;
            minimum = 2 * minimum - arr[top];
            return d;
        }
    }
    int getmin()
    {
        return minimum;
    }
};
int main()
{
    Advancedstack s;
    int n, data;
    cout << "\nEnter the no of elements in the stack : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s.push(data);

    }
    cout << "\nMinimum element is " << s.getmin();
    
}