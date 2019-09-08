#include <iostream>
#include <stack>
using namespace std;

void nextGreater(int a[], int n, int p[])
{
    stack<int> s;
    p[n - 1] = -1;
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && a[i] >= a[s.top()])
            s.pop();
        p[i] = (s.empty()) ? -1 : a[s.top()];
        s.push(i);
    }
}

int main()
{
    int n;
    cout << "\nEnter the no of elements : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> a[i];
    }
    int p[n];
    nextGreater(a, n, p);
    cout << "\nNext greater : \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " -> " << p[i] << endl;
    }
}