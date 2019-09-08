#include <iostream>
using namespace std;
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
    int greater=a[n-1];
    int ng[n];
    ng[n - 1] = -1;
    for (int i = n - 2; i >=0; i--)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                ng[i] = a[j];
                break;
            }
        }
    }
    cout << "\nNext greater:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " -> " << ng[i] << "\n";
    }
}