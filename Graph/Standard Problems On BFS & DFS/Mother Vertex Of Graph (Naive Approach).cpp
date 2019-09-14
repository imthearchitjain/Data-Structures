#include<bits/stdc++.h>
using namespace std;

class graph{

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
        list[src].insert(lower_bound(list[src].begin(), list[src].end(), dest),dest);
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex "<< i << " : ";
            for (int j = 0; j < list[i].size(); j++)
                cout << list[i][j] << " -> ";
            cout << "NULL\n";
        }
    }
    
    
};
void BFS(graph g, int src, vector<bool> &visited)
{
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : g.list[x])
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
    }
}
bool True(bool a)
{
    return a == true;
}
int mother_vertex(graph g)
{
    vector<bool> visited(g.v);
    for (int i = 0; i < g.v; i++)
    {
        visited.assign(g.v, false);
        BFS(g, i, visited);
        if(count_if(visited.begin(), visited.end(), True) == g.v)
            return i;
    }
}

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

    cout << "\nMother Vertex Of Graph is : " << mother_vertex(g);
}