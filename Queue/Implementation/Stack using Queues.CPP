#include <iostream>
#include <queue>
/*
STL queue, function suppported are:
empty() – Returns whether the queue is empty.
size() – Returns the size of the queue.
swap() : Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
emplace() : Insert a new element into the queue container, the new element is added to the end of the queue.
front() and back() – front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.
filter_none

*/
using namespace std;

class stack
{
    queue<int> q1, q2;
public:
    void push(int data)
    {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        if(q1.empty())
            return ;
        
        q1.pop();
    }
    int top()
    {
        if(q1.empty())
            return INT16_MIN;
        return q1.front();
    }

};

int main()
{
    stack s;
    int n, data;
    cout << "\nEnter the no of elements : ";
    cin>>n;
    while(n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s.push(data);
    }
    cout << "\nTop elememt : " << s.top();
    cout << "\nPopping element : ";
    s.pop();
    cout << "\nTop element : " << s.top();
}
