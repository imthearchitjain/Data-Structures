#include <iostream>
#include <stack>
using namespace std;
#define N 4
bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

int findCelebrity(int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(MATRIX[a][b])
            s.push(b);
        else
            s.push(a);
    }
    int pos = s.top();
    int status = 1;
    for (int i = 0; i < n; i++)
    {
        if (pos != i)
            if (!MATRIX[i][pos] || MATRIX[pos][i])
            {
                return -1;
            }
    }
    return pos;
    
}
int main()
{
    cout << "\nCelebrity is :" << findCelebrity(N);
}
