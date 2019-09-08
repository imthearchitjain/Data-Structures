#include <iostream>
#include <queue>
using namespace std;
void reverse(queue <int> &q)
{
    if (q.size() == 1)
        return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
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