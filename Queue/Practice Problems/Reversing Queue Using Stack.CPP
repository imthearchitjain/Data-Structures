#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(queue <int> &q)
{
    int n = q.size();
    if (n == 1)
        return;
    stack<int> s;
    while (n--)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void printQueue(queue<int> q)
{
    cout << "\nFront -> ";
    while (q.size())
    {
        cout << q.front() << " -> ";
        q.pop();
    }
    cout << "Rear\n";
}
int main()
{
    queue<int> q;
    int n;
    cout << "\nEnter the no of elements : ";
    cin >> n;
    int data;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        q.push(data);
    }
    printQueue(q);
    reverse(q);
    printQueue(q);
}