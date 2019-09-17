#include <bits/stdc++.h>
using namespace std;

class graph
{

public:
    int v;
    vector<vector<int>> list;
    graph(int v)
    {
        this->v = v;
        list.resize(v);
    }
    void edge(int src, int dest)
    {
        list[src].insert(lower_bound(list[src].begin(), list[src].end(), dest), dest);
        list[dest].insert(lower_bound(list[dest].begin(), list[dest].end(), src), src);
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " : ";
            for (int j = 0; j < list[i].size(); j++)
                cout << list[i][j] << " -> ";
            cout << "NULL\n";
        }
    }
    
    
    
};

int nodes_at_given_level(graph g, int src, int level)
{
    queue<int> q;
    vector<int> d(g.v, INT_MAX);
    d[src] = 0;
    vector<bool> visited(g.v, false);
    visited[src] = true;
    q.push(src);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for (auto i : g.list[x])
            if (!visited[i])
            {
                d[i] = d[x] + 1;
                visited[i] = true;
                q.push(i);
            }
    }

    return count(d.begin(), d.end(), level);
}
int main()
{
    graph g(6);
    g.edge(0, 1);
    g.edge(0, 2);
    g.edge(1, 3);
    g.edge(2, 4);
    g.edge(2, 5);

    int level = 2;
    cout << "\nNumber of nodes at level " << level << " is " << nodes_at_given_level(g, 0, level);
}