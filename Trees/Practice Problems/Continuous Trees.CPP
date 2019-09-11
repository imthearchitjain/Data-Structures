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

bool check_continuous_tree(Btree *root)
{
    int x, y;
    if(!root)
        return 1;
    else if(!root->left && !root->right)
        return 1;
    else if(!root->right)
    {    
        x = root->data - root->left->data;
        if(x == -1 || x == 1)
            return 1 && check_continuous_tree(root->left);
        else
            return 0;
    }
    else if(!root->left)
    {
        y = root->data - root->right->data;
        if (y == -1 || y == 1)
            return 1 && check_continuous_tree(root->right);
        else
            return 0;
    }
    x = root->data - root->left->data;
    y = root->data - root->right->data;
    if((x == 1 || x == -1) && (y == 1 || y == -1))
        return 1 && check_continuous_tree(root->left) && check_continuous_tree(root->right);
    else
        return 0;
}
int main()
{
    Btree *root = new Btree(3);
    root->left = new Btree(2);
    root->right = new Btree(4);
    root->left->left = new Btree(1);
    root->left->right = new Btree(3);
    root->right->right = new Btree(5);
    check_continuous_tree(root) ? cout << "Yes" : cout << "No";
}