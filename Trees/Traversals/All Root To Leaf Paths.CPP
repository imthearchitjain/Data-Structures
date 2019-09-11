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
void printarray(int a[], int n) 
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}
void rootToLeafPaths(binaryTree *root, int a[], int pathlen)
{
    if (!root)
        return;
    a[pathlen] = root->data;
    pathlen++;
    if (!root->left && !root->right)
        printarray(a, pathlen);
    else
    {
        rootToLeafPaths(root->left, a, pathlen);
        rootToLeafPaths(root->right, a, pathlen);
    }
    
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
    cout << "\nAll root to leaf paths :";
    int arr[5], pathlen = 0;
    rootToLeafPaths(root, arr, pathlen);

}