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
int maxElementTree(binaryTree *root)
{
    int max = INT16_MIN;
    queue<binaryTree *> q;
    binaryTree *temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (max < temp->data)
            max = temp->data;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return max;
}
int minElementTree(binaryTree *root)
{
    int min = INT16_MAX;
    queue<binaryTree *> q;
    binaryTree *temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (min > temp->data)
            min = temp->data;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return min;
}
int main()
{
    int n;
    binaryTree *root = nullptr;
    cout << "\nEnter no of elements in a binary tree : ";
    cin>>n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nMaximum is : " << maxElementTree(root);
    cout << "\nMinimum is : " << minElementTree(root);
} 