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
    void iterative_DFS(int src)
    {
        stack<int> s;
        vector<bool> visited(v, false);
        s.push(src);
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            if (!visited[x])
            {
                cout << x << " ";
                visited[x] = true;
            }
            for (auto i : list[x])
                if (!visited[i])
                    s.push(i);
        }
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
    g.iterative_DFS(0);
    cout << endl;
}