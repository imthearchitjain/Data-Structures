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
    int i = 0, j = n - 1;
    while (i != j)
    {
        if(MATRIX[i][j])
            i++;
        else
            j--;
    }
    int pos = i;
    int status = 1;
    for (i = 0; i < n; i++)
    {
        if (pos != i)
            if (!MATRIX[i][pos] || MATRIX[pos][i])
            {
                return -1;
            }
    }
    return pos+1;
    
}
int main()
{
    cout << "\nCelebrity is :" << findCelebrity(N);
}
