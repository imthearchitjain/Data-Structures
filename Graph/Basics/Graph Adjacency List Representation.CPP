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
            for (auto x : list[i])
                cout << x << " -> ";
            cout << "NULL\n";
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
}