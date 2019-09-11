#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Btree
{
public:
	int data;
	Btree* left;
	Btree* right;
	Btree* next;
	Btree(int data = 0)
	{
		this->data = data;
		next = left = right = nullptr;
	}
};

void inorder(Btree* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void populate_inorder_successor(Btree* root)
{
	static Btree* next = nullptr;
	if (!root)
		return;
	populate_inorder_successor(root->right);
	root->next = next;
	next = root;
	populate_inorder_successor(root->left);
	
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
	Btree* root = new Btree(1);
	root->left = new Btree(2);
	root->right = new Btree(3);
	root->left->left = new Btree(4);
	root->left->right = new Btree(5);
	root->right->left = new Btree(6);
	root->right->right = new Btree(7);
	populate_inorder_successor(root);
	Btree* ptr = root;
	while (ptr->left)
		ptr = ptr->left;
	while (ptr)
	{
		if (!ptr->next)
			cout << "Inorder Successor of "<< ptr->data << " is " << -1 <<endl;
		else
			cout << "Inorder Successor of " << ptr->data << " is " << ptr->next->data << endl;
		ptr = ptr->next;
	}

}