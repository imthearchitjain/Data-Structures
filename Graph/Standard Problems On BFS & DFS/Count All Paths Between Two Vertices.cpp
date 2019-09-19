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
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " : ";
            for (auto x : list[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};
void DFS(graph g, int src, int dest, int &count, vector<bool> &visited)
{
    visited[src] = true;
    for(auto x : g.list[src])
    {
        if(x == dest)
            count++;
        if(!visited[x])
            DFS(g, x, dest, count, visited);
    }
    visited[src] = false;
}
int all_paths(graph g, int src, int dest)
{
    int count = 0;
    vector<bool> visited(g.v, false);
    DFS(g, src, dest, count, visited);
    return count;
}
int main()
{
    graph g(4);
    g.edge(0, 1);
    g.edge(0, 2);
    g.edge(0, 3);
    g.edge(2, 0);
    g.edge(2, 1);
    g.edge(1, 3);
    cout << all_paths(g, 0, 2);
}