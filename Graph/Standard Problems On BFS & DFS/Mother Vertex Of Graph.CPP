#include <bits/stdc++.h>
using namespace std;

bool True(bool a)
{
    return a == true;
}

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
        for (auto x : list[src])
            if (!visited[x])
                DFS_until(visited, x);
    }
    void DFS(int src)
    {
        vector<bool> visited(v, false);
        DFS_until(visited, src);
    }
    int mother_vertex()
    {
        vector<bool> visited(v, false);
        int x = 0;
        for (int i = 0; i < v; i++)
            if (!visited[i])
            {
                DFS_until(visited, i);
                x = i;
            }
        // idea is that DFS mother vertex has maximum finish time
        fill(visited.begin(), visited.end(), false);

        DFS_until(visited, x);

        if (count(visited.begin(), visited.end(), false) == 0)
            return x;
        else
            return -1;
    }
};

int main()
{
    int n;
    cout << "Enter the nof of vertices in the graph : ";
    cin >> n;
    graph g(n);

    g.edge(0, 1);
    g.edge(0, 2);
    g.edge(1, 3);
    g.edge(4, 1);
    g.edge(6, 4);
    g.edge(5, 6);
    g.edge(5, 2);
    g.edge(6, 0);

    g.print();
    cout << "\nMother Vertex Of Graph is : " << g.mother_vertex();
}