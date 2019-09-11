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

void store_inorder(Btree* root, vector<int> &in)
{
	if (!root)
		return;
	store_inorder(root->left, in);
	in.push_back(root->data);
	store_inorder(root->right, in);
}
void inorder(Btree* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void inorder_successor_predeccessor_sum(Btree* root, vector<int> v, int &i)
{
	if (!root)
		return;
	inorder_successor_predeccessor_sum(root->left, v, i);
	if (i != 0 && i != v.size() - 1)
		root->data = v[i - 1] + v[i + 1];
	else if (i != 0)
		root->data = v[i - 1];
	else
		root->data = v[i + 1];
	i++;
	inorder_successor_predeccessor_sum(root->right, v, i);
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
	vector<int> v;
	Btree* root = new Btree(1);
	root->left = new Btree(2);
	root->right = new Btree(3);
	root->left->left = new Btree(4);
	root->left->right = new Btree(5);
	root->right->left = new Btree(6);
	root->right->right = new Btree(7);
	store_inorder(root, v);
	int i = 0;
	inorder_successor_predeccessor_sum(root, v, i);
	preorder(root);
}