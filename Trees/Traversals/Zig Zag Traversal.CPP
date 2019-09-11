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
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
bool allAncestors(binaryTree *root, binaryTree *node)
{
    if (!root)
        return 0;
    if (root == node || allAncestors(root->left, node) || allAncestors(root->right, node))
    {
        cout << root->data << " ";
        return 1;
    }
    return 0;
}
void zigzag(binaryTree *root)
{
    binaryTree *temp;
    stack<binaryTree *> curr, next;
    int ltor = 1;
    if (!root)
        return;
    curr.push(root);
    while (!curr.empty())
    {
        temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (ltor)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
            
        }
        if (curr.empty())
        {
            ltor = 1 - ltor;
            curr.swap(next);
        }
    }
}

int main()
{
    binaryTree *root = nullptr;
    int n, data;
    cout << "\nEnter th eno of elements in the tree : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nZig Zag traversel of tree : ";
    zigzag(root);
}                        