#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    reverse(v.begin(), v.end());
    int n = 7, k = 3;
    vector<int> temp;
    temp.assign(v.begin(), v.begin() + k + 1);
    make_heap(temp.begin(), temp.end());
    vector<int> arr;
    for (int i = k + 1; i < n; i++)
    {
        arr.push_back(temp.front());
        pop_heap(temp.begin(), temp.end());
        temp.pop_back();
        temp.push_back(v[i]);
        push_heap(temp.begin(), temp.end());
    }
    while(temp.size() != 0)
    {
        arr.push_back(temp.front());
        pop_heap(temp.begin(), temp.end());
        temp.pop_back();
    }
    for (int i = 0; i < n; i++)
        cout << arr[n - 1 - i] << " ";
}