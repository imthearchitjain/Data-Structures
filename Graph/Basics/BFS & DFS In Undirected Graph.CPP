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
    void DFS_until(vector<bool> &visited, int src)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto x : list[src])
            if (!visited[x])
                DFS_until(visited, x);
    }
    void DFS(int src)
    {
        vector<bool> visited(v, false);
        DFS_until(visited, src);
    }
};

int main()
{
    int n;
    cout << "Enter the nof of vertices in the graph : ";
    cin >> n;
    graph g(n);

    g.edge(1, 4);
    g.edge(1, 3);
    g.edge(1, 2);
    g.edge(2, 3);
    g.edge(3, 4);
    g.edge(0, 4);
    g.edge(0, 1);

    g.print();
    g.BFS(0);
    cout << endl;
    g.DFS(0);
}