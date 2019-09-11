#include<bits/stdc++.h>
using namespace std;
class Btree{
public:
    string data;
    Btree *left;
    Btree *right;
    Btree(string data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
int calculate(int a, int b, char c)
{
    if(c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
    
}

int evaluateTree(Btree *root)
{
    if(root)
    {
        if(!root->left && !root->right)
            return stoi(root->data);
        int a = evaluateTree(root->left);
        int b = evaluateTree(root->right);
        return calculate(a, b, root->data[0]);
    }
    else
        return 0;
}


int main()
{
    // create a syntax tree
    Btree *root = new Btree("+");
    root->left = new Btree("*");
    root->left->left = new Btree("5");
    root->left->right = new Btree("-4");
    root->right = new Btree("-");
    root->right->left = new Btree("100");
    root->right->right = new Btree("20");
    cout << evaluateTree(root) << endl;

    delete (root);

    root = new Btree("+");
    root->left = new Btree("*");
    root->left->left = new Btree("5");
    root->left->right = new Btree("4");
    root->right = new Btree("-");
    root->right->left = new Btree("100");
    root->right->right = new Btree("/");
    root->right->right->left = new Btree("20");
    root->right->right->right = new Btree("2");

    cout << evaluateTree(root);
    return 0;
}