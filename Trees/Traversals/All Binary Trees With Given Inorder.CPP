#include<iostream>
#include<vector>
using namespace std;
class Btree
{
public:
	int data;
	Btree* left;
	Btree* right;
	Btree(int data = 0)
	{
		this->data = data;
		left = right = nullptr;
	}
};
vector<Btree*> allTrees(int in[], int start, int end)
{
	vector<Btree*> trees;
	if (start > end)
	{
		trees.push_back(nullptr);
		return trees;
	}
	for (int i = start; i <= end; i++)
	{
		vector<Btree*> ltrees = allTrees(in, start, i - 1);
		vector<Btree*> rtrees = allTrees(in, i + 1, end);
		for (int j = 0; j < ltrees.size(); j++)
		{
			for (int k = 0; k < rtrees.size(); k++)
			{
				Btree* root = new Btree(in[i]);
				root->left = ltrees[j];
				root->right = rtrees[k];
				trees.push_back(root);
			}
		}
	}
	return trees;
}

void preorder(Btree* root)
{
	if (!root)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int in[] = { 4, 5, 7 };
	int n = sizeof(in) / sizeof(in[0]);
	vector<Btree*> t = allTrees(in, 0, n - 1);
	for (int i = 0; i < t.size(); i++)
	{
		preorder(t[i]);
		cout << endl;
	}
}