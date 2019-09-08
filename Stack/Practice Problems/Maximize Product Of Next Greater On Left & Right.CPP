#include <iostream>
#include <stack>
using namespace std;

void nextGreaterLeft(int a[], int n, int p[])
{
    stack<int> s;
    p[0] = 0;
    s.push(0);
    for (int i = 1; i <n; i++)
    {
        while (!s.empty() && a[i] >= a[s.top()])
            s.pop();
        p[i] = (s.empty()) ? 0 : s.top();
        s.push(i);
    }
}
void nextGreaterRight(int a[], int n, int p[])
{
    stack<int> s;
    p[n-1] = 0;
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && a[i] >= a[s.top()])
            s.pop();
        p[i] = (s.empty()) ? 0 : s.top();
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
    int L[n], R[n];
    nextGreaterLeft(a, n, L);
    nextGreaterRight(a, n, R);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < (L[i] + 1) * (R[i] + 1))
            max = (L[i] + 1) * (R[i] + 1);
    }
    cout << "\nMax = : " << max;
}
