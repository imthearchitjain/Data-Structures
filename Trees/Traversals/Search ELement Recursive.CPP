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
//searching using recursion using recursion
bool searchTree(binaryTree *root, int data)
{
    if (!root)
        return 0;
    if (data == root->data)
        return 1;
    bool temp = searchTree(root->left, data);
    if (temp != 0)
        return temp;
    else
        return searchTree(root->right, data);
}

int main()
{
    int n;
    binaryTree *root = nullptr;
    cout << "\nEnter no of elements in a binary tree : ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nEnter element to be searched : ";
    cin >> data;
    if (searchTree(root, data))
        cout << "\nElement found...";
    else
        cout << "\nElement not found...";
}