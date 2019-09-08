#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(queue<int> &q, int k)
{
    if (k == 0)
        return;
    else
    {
        int x = q.front();
        q.pop();
        reverse(q, k - 1);
        q.push(x);
    }
}
void kElementReverse(queue<int> &q, int k)
{
    reverse(q, k);
    int n = q.size();
    while ((n--) - k)
    {
        q.push(q.front());
        q.pop();
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
    int k;
    cout << "\nEnter k : ";
    cin >> k;
    printQueue(q);
    kElementReverse(q,k);
    printQueue(q);
}