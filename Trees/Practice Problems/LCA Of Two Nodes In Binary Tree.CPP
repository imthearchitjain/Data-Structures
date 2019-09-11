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
void levelOrder(binaryTree *root)
{
    queue<binaryTree *> q;
    binaryTree *temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
binaryTree* LCA(binaryTree *root, binaryTree *a, binaryTree *b)
{
    binaryTree *left, *right;
    if (!root)
        return root;
    if ((root->left) == a && (root->right) == b)
        return root;
    left = LCA(root->left, a, b);
    right = LCA(root->right, a, b);
    if (left && right)
        return root;
    else
        return left ? left : right;
}

int main()
{
    int n;
    int data;
    binaryTree *root = nullptr,*a,*b;
    cout << "\nEnter no of elements in binary tree : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nLCA of two nodes is : " << LCA(root, root->left, root->right)->data;
}