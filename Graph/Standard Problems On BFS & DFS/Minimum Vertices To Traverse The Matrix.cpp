#include<bits/stdc++.h>
using namespace std;

void DFS(int n, int m, vector<vector<int>> adj, vector<bool> &visited, int x, int y)
{
    visited[x * m + y] = true;
    int i = x + 1, j = y;
    if(i < n && !visited[i * m + j] && adj[x][y] >= adj[i][j])
        DFS(n, m, adj, visited, i, j);
    i = x - 1;
    j = y;
    if (i >= 0 && !visited[i * m + j] && adj[x][y] >= adj[i][j])
        DFS(n, m, adj, visited, i, j);
    i = x;
    j = y - 1;
    if (j >= 0 && !visited[i * m + j] && adj[x][y] >= adj[i][j])
        DFS(n, m, adj, visited, i, j);
    i = x;
    j = y + 1;
    if (j < m && !visited[i * m + j] && adj[x][y] >= adj[i][j])
        DFS(n, m, adj, visited, i, j);
}
int min_vertices(int n, int m, vector<vector<int>> adj)
{
    vector<bool> visited(n * m, false);
    vector<pair<long int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v.push_back(make_pair(adj[i][j], make_pair(i, j)));
    sort(v.begin(), v.end());

    int vet = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        
        if(!visited[v[i].second.first * m + v[i].second.second])
        {
            vet++;
            DFS(n, m, adj, visited, v[i].second.first, v[i].second.first);
            cout << v[i].second.first << " " << v[i].second.second << endl;
        }   
        
        
        
    }
    return vet;
}
int main()
{
    int N = 3, M = 3;
    int data;
    vector<int> x = {1, 2, 3};
    vector<int> y = {2, 3, 1};
    vector<int> z = {1, 1, 1};
    vector<vector<int>> adj;
    adj.push_back(x);
    adj.push_back(y);
    adj.push_back(z);

    int n = min_vertices(N, M, adj);
    cout << "Minimum number Of vertices to traverse the whole matrix : " << n;
}