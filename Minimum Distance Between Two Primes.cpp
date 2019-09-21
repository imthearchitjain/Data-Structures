#include<bits/stdc++.h>
using namespace std;

class graph
{
public:
    int v;
    vector<int> *adj;
    graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }
    void edge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

};
bool gap(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    int c = 0;
    if (sa[0] != sb[0])
        c++;
    if (sa[1] != sb[1])
        c++;
    if (sa[2] != sb[2])
        c++;
    if (sa[3] != sb[3])
        c++;
    return c == 1;
}
void prime(vector<bool> &a)
{
    a.assign(10000, true);
    for (int i = 2; i * i < 10000; i++)
    {
        if(a[i] = true)
        {
            for (int p = i * i; p < 10000; p += i)
                a[p] = false;
        }
    }
}
int BFS(graph g, int a, int b)
{
    if(a == b)
        return 0;
    vector<bool> visited(g.v, false);
    visited[a] = true;
    vector<int> d(g.v, -1);
    d[a] = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : g.adj[x])
        {
            if(!visited[i])
            {
                visited[i] = true;
                d[i] = d[x] + 1;
                q.push(i);
                
            }
            if (i == b)
                return d[i];
        }
    }
    return -1;
}
int shortest_distance(int a, int b)
{
    vector<int> primes;
    vector<bool> p;
    prime(p);
    for (int i = 1001; i < p.size(); i++)
        if(p[i])
            primes.push_back(i);
    

    graph g(primes.size());
    for (int i = 0; i < primes.size(); i++)
        for (int j = i + 1; j < primes.size(); j++)
            if(gap(primes[i], primes[j]))
                g.edge(i, j);
    int i = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
    int j = lower_bound(primes.begin(), primes.end(), b) - primes.begin();
    int s = BFS(g, i, j);
    return s;
}

int main()
{
    int a = 1033, b = 8179;
    cout << "Shortest distance between " << a << " and " << b << " is : ";
    cout << shortest_distance(a, b);
}