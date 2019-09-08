#include <iostream>
#include <stack>
using namespace std;
void nextGreaterfreq(int a[], int n, int p[],int freq[])
{
    stack<int> s;
    p[n - 1] = -1;
    s.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && freq[a[i]] >= freq[a[s.top()]])
            s.pop();
        p[i] = (s.empty()) ? -1 : s.top();
        s.push(a[i]);
    }
}
int main()
{
    int n;
    cout << "\nEnter the no of elements :";
    cin >> n;
    int a[n];
    int max;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            max = a[i];
        if (a[i] > max)
            max = a[i];
    }
    int freq[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    int p[n];
    nextGreaterfreq(a, n, p, freq);
    cout << "\nNext greater frequency element : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " -> " << p[i] << "\n";
}