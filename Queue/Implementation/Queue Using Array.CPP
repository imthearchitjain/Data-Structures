#include <iostream>
using namespace std;

class queue
{
    int *array;
    int capacity;
    int front, rear;
    int size;
public:
    queue(int n)
    {
        array = new int[n];
        capacity = n;
        front = 0;
        rear = n - 1;
        size = 0;
    }
    bool isFull()
    {
        return capacity == size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(int data)
    {
        if(isFull())
            return;
        rear = (rear + 1) % capacity;
        array[rear] = data;
        size++;
    }
    void dequeue()
    {
        if(isEmpty())
            return;
        front = (front + 1) % capacity;
        size--;
    }
    int first()
    {
        if(isEmpty())
            return INT16_MIN;
        return array[front];
    }
    int last()
    {
        if (isEmpty())
            return INT16_MIN;
        return array[rear];
    }

};
int main()
{
    int n;
    cout << "\nEnter the no of elements in the queue : ";
    cin >> n;
    queue q(n);
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        q.enqueue(data);
    }

    cout << "\nThe front : " << q.first();
    cout << "\nThe rear : " << q.last();
    cout << "\nRemoving element ...\n";
    q.dequeue();
    cout << "\nUpdated Front : " << q.first();
}
