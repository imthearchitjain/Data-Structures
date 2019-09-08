#include<bits/stdc++.h>
using namespace std;
int get_min_pop(stack<int> s)
{
    if(s.size() == 1)
        return s.top();
    int min = s.top();
    s.pop();
    int min1 = get_min_pop(s);
    if(min > min1)
        min = min1;
    return min;
}
void get_min_every_pop(stack<int> s)
{
    while(!s.empty())
    {
        cout << get_min_pop(s) << " ";
        s.pop();
    }
}
int main()
{
    stack<int> s;
    s.push(23);
    s.push(-31);
    s.push(-1);
    s.push(-4);
    s.push(-40);
    get_min_every_pop(s);
}