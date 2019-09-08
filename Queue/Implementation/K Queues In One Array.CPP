#include <iostream>
#include<stack>
using namespace std;
class kQueue
{
    int *array;
    int *front;
    int *rear;
    int *next;
    int size;
    int k, f;

public: 


    kQueue(int a,int b)
    {
        size = a;
        k = b;
        array = new int[size];
        next = new int[size];
        front = new int[k];
        rear = new int[k];
        f = 0;
        for (int i = 0; i < k; i++)
            front[i] = -1;
        for (int i = 0; i < size - 1; i++)
            next[i] = i + 1;
        next[size - 1] = -1;
    }
    bool isEmpty(int qn)
    {
        return front[qn] == -1;
    }
    void enqueue(int data,int qn)
    {
        int i = f;
        f = next[i];
        if(isEmpty(qn))
            front[qn] = i;
        else
            next[rear[qn]] = i;
        next[i] = -1;
        rear[qn] = i;
        array[i] = data;
    }
    int dequeue(int qn)
    {
        if(isEmpty(qn))
            return INT16_MIN;
        int i = front[qn];
        front[qn] = next[i];
        next[i] = f;
        f = i;
        return array[i];
    }
    

};
int main()
{
    int k = 3, n = 10;
    kQueue ks(n, k);

    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;
}
