#include<bits/stdc++.h>
using namespace std;
class Btree{
public:
    int data;
    Btree *left;
    Btree *right;
    Btree(int data = 0)
    {
        this->data = data;
        left = right = nullptr;
    }
};
bool isFoldableUntil(Btree *n1, Btree *n2)
{
    if(!n1 && !n2)
        return true;
    if(!n1 || !n2)
        return false;
    else
        return isFoldableUntil(n1->right, n2->left) && isFoldableUntil(n1->left, n2->right);
}
bool checkFoldableBtree(Btree *root)
{
    if(!root)
        return true;
    else
        return isFoldableUntil(root->left, root->right);
}
int main()
{
    Btree *root = new Btree(1);
    root->left = new Btree(2);
    root->right = new Btree(3);
    root->right->left = new Btree(4);
    root->left->right = new Btree(5);
    cout << checkFoldableBtree(root);
}