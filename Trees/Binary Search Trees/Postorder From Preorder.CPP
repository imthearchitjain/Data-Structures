#include<iostream>
using namespace std;

int search_next_greater(int pre[], int n)
{
	for (int i = 0; i < n; i++)
		if (pre[i] > pre[0])
			return i;
	return -1;
}
void postorder(int pre[], int n)
{
	if (n == 1)
	{
		cout << pre[0] << " ";
		return;
	}
	int i = search_next_greater(pre, n); 
	if (i != 1)
		postorder(pre + 1, i - 1);
	postorder(pre + i, n - i);
	cout << pre[0] << " ";

}

int main()
{
	int pre[] = { 40, 30, 32, 35, 80, 90, 100, 120 };

	int n = sizeof(pre) / sizeof(pre[0]);

	// Calling function 
	postorder(pre, n);
	return 0;
}