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
    if (n == 1)
        return 0;
    int k = findCelebrity(n - 1);
    if (MATRIX[n][k] || !MATRIX[k][n])
        return k;
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (!MATRIX[i][n] || MATRIX[n][i])
            {
                return -1;
            }
        }
        return n;
    }
}
int main()
{
    cout << "\nCelebrity is :" << findCelebrity(N);
}
