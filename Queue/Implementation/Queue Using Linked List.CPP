#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};
class queue
{
    node *front;
    node *rear;
    int size;

public:
    queue(int n)
    {
        front = rear = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(int data)
    {
        
        node *newnode = new node();
        newnode->data = data;
        newnode->prev = nullptr;
        newnode->next = nullptr;
        if (size == 0)
        {
            front = rear = newnode;
            size++;
        }
        else
        {
            newnode->prev = rear;
            rear->next = newnode;
            rear = newnode;
            size++;
        }
        
        newnode->prev = rear;
        rear->next = newnode;
        rear = newnode;
        size++;
    }
    void dequeue()
    {
        if(isEmpty())
            return;
        node *temp = front;
        front = front->next;
        front->prev = nullptr;
        free(temp);
        size--;
    }
    int first()
    {
        if(isEmpty())
            return INT16_MIN;
        return front->data;
    }
    int last()
    {
        if (isEmpty())
            return INT16_MIN;
        return rear->data;
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
