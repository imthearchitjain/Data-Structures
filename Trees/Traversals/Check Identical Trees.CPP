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
bool checkIdentical(binaryTree *root1, binaryTree *root2)
{
    if (!root1 && !root2)
        return 1;
    if (!root1 || !root2)
        return 0;
    return (root1->data == root2->data && checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right));
}

int main()
{
    int n;
    binaryTree *root1 = nullptr, *root2 = nullptr;
    cout << "\nEnter no of elements in 1st binary tree : ";
    cin >> n;
    int data;
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
    if (checkIdentical(root1, root2))
        cout << "\nTrees are identical....\n";
    else
        cout << "\nTrees are not identical....\n";
}