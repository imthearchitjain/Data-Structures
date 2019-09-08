// stack implementation using array
#include <iostream>
using namespace std;
#define Max 100
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks()
    {
        size = Max;
        arr = new int[Max];
        top1 = -1;
        top2 = Max;
    }
    void push1(int);
    void push2(int);
    int pop1();
    int pop2();
};

void twoStacks::push1(int a)
{
    if (top1 < top2 - 1)
    {
        top1++;
        arr[top1]=a;
    }
    else
        cout << "\nStack is Full...";
}
void twoStacks::push2(int a)
{
    if (top1 < top2 - 1)
    {
        top2--;
        arr[top2] = a;
    }
    else
        cout << "\nStack is Full...";
}
int twoStacks::pop1()
{
    if (top1 == -1)
        cout << "\nStack 1 is empty.";
    else
        return arr[top1--];
}
int twoStacks::pop2()
{
    if (top2 == Max)
        cout << "\nStack 2 is empty.";
    else
        return arr[top2++];
}
int main()
{
    twoStacks s;
    int m, n;
    int data;
    cout << "\nEnter the no of elements in stack 1 : ";
    cin >> m;
    while (m--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s.push1(data);
    }
    cout << "\nEnter the no of elements in stack 2 : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s.push2(data);
    }
    cout << "\nPoped element from stack 1 : " << s.pop1();
    cout << "\nPoped element from stack 2 : " << s.pop2();
}
