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
    void BFS(int src)
    {
        queue<int> q;
        vector<bool> visited(v, false);
        visited[src] = true;
        q.push(src);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cout << x << " ";
            for (auto i : list[x])
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
        }
    }
};

bool DFS_until(graph g, vector<bool> &visited, vector<int> &degree, int src, int k)
{
    visited[src] = true;
    for (auto x : g.list[src])
    {
        if (degree[src] < k)
            degree[x]--;
        if (!visited[x])
        {
            if (DFS_until(g, visited, degree, x, k))
                degree[src]--;
        }
    }
    return degree[src] < k;
}

void K_cores(graph g, int k)
{
    vector<int> degree(g.v);
    vector<bool> visited(g.v, false);
    int start;
    int min_deg = INT_MAX;
    for (int i = 0; i < g.v; i++)
    {
        degree[i] = g.list[i].size();
        if (degree[i] < min_deg)
        {
            start = i;
            min_deg = degree[i];
        }
    }
    DFS_until(g, visited, degree, start, k);
    for (int i = 0; i < g.v; i++)
        if (!visited[i])
            DFS_until(g, visited, degree, i, k);

    for (int i = 0; i < g.v; i++)
    {
        if (degree[i] >= k)
        {
            cout << "\n[" << i << "] : ";
            for (auto x : g.list[i])
                if (degree[x] >= k)
                    cout << x << " -> ";
            cout << "NULL";
        }
    }
}
int main()
{
    int k = 3;
    graph g1(9);
    g1.edge(0, 1);
    g1.edge(0, 2);
    g1.edge(1, 2);
    g1.edge(1, 5);
    g1.edge(2, 3);
    g1.edge(2, 4);
    g1.edge(2, 5);
    g1.edge(2, 6);
    g1.edge(3, 4);
    g1.edge(3, 6);
    g1.edge(3, 7);
    g1.edge(4, 6);
    g1.edge(4, 7);
    g1.edge(5, 6);
    g1.edge(5, 8);
    g1.edge(6, 7);
    g1.edge(6, 8);
    K_cores(g1, k);
}