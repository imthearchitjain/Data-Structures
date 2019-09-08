#include <iostream>
using namespace std;

class kStacks
{
    int *array;
    int *top;
    int *next;
    int n, k;
    int f;
public:
    kStacks(int k, int n);

    void push(int data, int sn);

    int pop(int sn);

    bool isEmpty(int sn)
    {
        return top[sn] == -1;
    }

    bool isFull()
    {
        return f == -1;
    }

};

kStacks::kStacks(int k1, int n1)
{
    k = k1;
    n = n1;
    array = new int[n];
    top = new int[k];
    next = new int[n];
    f = 0;
    for (int i = 0; i < k; i++)
        top[i] = -1;
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1;
}

void kStacks::push(int data, int sn)
{
    if(isFull())
    {
        cout << "\nstack Full...";
        return;
    }
    
    int i = f;
    f = next[i];
    next[i] =top[sn];
    top[sn] = i;

    array[i] = data;
}

int kStacks::pop(int sn)
{
    if(isEmpty(sn))
    {
        cout << "\nStack is empty...";
        return INT16_MIN;
    }

    int i = top[sn];
    top[sn] = next[i];
    next[i] = f;
    f = i;
    return array[i];
}
int main()
{
    kStacks ks(3, 10); // 3 stacks in an array of 10 elements
    // pushing items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // pushing items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // pushing items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}