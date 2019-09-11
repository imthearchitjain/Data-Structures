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
int preIndex(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
}
binaryTree *buildTree(int in[], int pre[], int n)
{
    binaryTree *root = new binaryTree(pre[0]);
    int p = preIndex(in, n, pre[0]);
    root->data = pre[0];
    if (p != 0)
    {
        binaryTree *newnode = buildTree(in, pre + 1, p);
        root->left = newnode;
    }
    if (p != n - 1)
    {
        binaryTree *newnode = buildTree(in+p+1, pre +p+ 1, n-p-1);
        root->right = newnode;
    }
    return root;
}

int main()
{
    int n;
    cin>>n;
    int in[n], pre[n];
    cout << "\nEnter inorder traversel array : ";
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "\nEnter preorder traversel array : ";
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    binaryTree *root = buildTree(in, pre, n);
    levelOrder(root);
}