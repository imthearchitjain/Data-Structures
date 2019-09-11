#include <bits/stdc++.h>
using namespace std;
class binaryTree
{
public:
    int data;
    binaryTree *left;
    binaryTree *right;

    binaryTree(int data =0)
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
int find(int *arr,int x,int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
void printPostorder(int *in, int *pre, int n)
{
    int root;
    root = find(in,pre[0],n);
    if (root != 0)
        printPostorder(in, pre + 1, root);
    if (root != n - 1)
        printPostorder(in + root + 1, pre + root + 1, n - root - 1);
    cout << pre[0] << " ";
}
int main()
{
    int n;
    cout << "\nEnter the no of nodes in tree : ";
    cin >> n;
    int in[n], pre[n];
    cout << "\nEnter the inorder traversel array: ";
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "\nEnter the preorder traversel array: ";
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    cout << "\nPostorder traversel of tree : ";
    printPostorder(in, pre, n);
} 