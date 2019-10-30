#include<bits/stdc++.h>
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
            for (int j = 0; j < list[i].size(); j++)
                cout << list[i][j] << " -> ";
            cout << "NULL\n";
        }
    }
    
    void topological_sort_until(vector<bool> &visited, int src, stack<int> &s)
    {
        visited[src] = true;
        for (auto x : list[src])
            if (!visited[x])
                topological_sort_until(visited, x, s);

        s.push(src);
    }
    void topological_sort()
    {
        stack<int> s;
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
            if(!visited[i])
                topological_sort_until(visited, i, s);

        while(!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
};
int main()
{
    graph g(6);
    g.edge(5, 2);
    g.edge(5, 0);
    g.edge(4, 0);
    g.edge(4, 1);
    g.edge(2, 3);
    g.edge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topological_sort();
}
