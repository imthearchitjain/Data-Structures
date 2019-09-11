#include <bits/stdc++.h>
using namespace std;
class binaryTree
{
public:
    int data;
    binaryTree *left;
    binaryTree *right;

    binaryTree(int data = 0)
    {
        left = right = nullptr;
        this->data = data;
    }
};
void insert(binaryTree **root, int data)
{
    if (!(*root))
    {
        *root = new binaryTree(data);
        return;
    }
    // insertion using level order traversel
    binaryTree *newnode = new binaryTree(data);
    queue<binaryTree *> q;
    q.push(*root);
    while (!q.empty())
    {
        binaryTree *temp = q.front();
        q.pop();
        if (!temp->left)
        {
            temp->left = newnode;
            return;
        }
        else
            q.push(temp->left);
        if (!temp->right)
        {
            temp->right = newnode;
            return;
        }
        else
            q.push(temp->right);
    }
}
int height(binaryTree *root)
{
    if (!root)
        return 0;
    return 1 + height(root->left) + height(root->right);
}
int daimeterTree(binaryTree *root)
{
    int lh, rh, ld, rd;
    if (!root)
        return 0;
    lh = height(root->left);
    rh = height(root->right);
    ld = daimeterTree(root->left);
    rd = daimeterTree(root->right);
    return max(rh + lh + 1, max(ld, rd));
}

int main()
{
    int n;
    binaryTree *root = nullptr;
    cout << "\nEnter no of elements in binary tree : ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root, data);
    }
    cout << "\ndaimeter of binary tree : " << daimeterTree(root);

}