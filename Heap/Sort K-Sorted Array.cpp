#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    reverse(v.begin(), v.end());

    int n = 7, k = 3;
    for (int i = 0; i < n; i++)
    {
        if(i + k < n)
            make_heap(v.begin() + i, v.begin() + i + k);
        else
            make_heap(v.begin() + i, v.end());
    }
    for (int i = 0; i < n; i++)
        cout << v[n - 1 - i] << " ";
}