#include<bits/stdc++.h>
using namespace std;
class Btree{
public:
    int data;
    Btree *left;
    Btree *right;
    Btree(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

bool mirror(Btree *n1, Btree *n2)
{
    if(!n1 && !n2)
        return true;
    if(!n1 || !n2)
        return false;
    else
        return (n1->data == n2->data) && mirror(n1->left, n2->right) && mirror(n1->right, n2->left);
    
}
bool symmetric(Btree *root)
{
    if(!root)
        return true;
    else
        return mirror(root->left, root->right);
}


int main()
{
    Btree *root = new Btree(1);
    root->left = new Btree(2);
    root->right = new Btree(2);
    root->left->left = new Btree(3);
    root->left->right = new Btree(4);
    root->right->left = new Btree(4);
    root->right->right = new Btree(3);

    cout << symmetric(root);
}