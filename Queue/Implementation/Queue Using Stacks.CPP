#include <iostream>
#include<stack>
using namespace std;
class queue
{
public:
    stack<int> s1;
    stack<int> s2;
    int size;


    queue()
    {
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(int data)
    {
        size++;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(data);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void dequeue()
    {
        if(isEmpty())
            return;
        s1.pop();
        size--;
    }
    

};
int main()
{
    int n;
    cout << "\nEnter the no of elements in the queue : ";
    cin >> n;
    queue q;
    int data;
    for (int i = 0; i < n; i++)
    {
        
        cout << "\nEnter the data : ";
        cin >> data;
        q.enqueue(data);
    }
    cout << "\nFront : " << q.s1.top();
    cout << "\nRemoving element ....\n";
    cout << "\nUpdated front : " << q.s1.top();
}
