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
bool mirror(binaryTree *root1, binaryTree *root2)
{
    if (!root1 && !root2)
        return 1;
    else if (!root1 || !root2)
        return 0;
    else if (root1->data != root2->data)
        return 0;
    return mirror(root1->left, root2->right) && mirror(root1->right, root2->left);
}

int main()
{
    int n;
    int data;
    binaryTree *root1 = nullptr, *root2 = nullptr;
    cout << "\nEnter no of elements in 1st binary tree : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root1, data);
    }
    cout << "\nEnter no of elements in 2nd binary tree : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root2, data);
    }
    if(mirror(root1,root2))
        cout << "\nTrees are mirror image oof each other...";
    else
        cout << "\nTrees are not mirror....";
}