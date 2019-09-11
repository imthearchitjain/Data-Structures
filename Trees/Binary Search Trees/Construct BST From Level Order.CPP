#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    bool Ltag, Rtag;
    Node *left;
    Node *right;

    Node(int data = 0)
    {
        left = right = nullptr;
        this->data = data;
    }
};
void insert(Node **root, int data)
{
    if (!*root)
        *root = new Node(data);
    else if (data < (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}
void inorder(Node *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *LevelOrder(Node *root, int data)
{
    if(!root)
    {
        root = new Node(data);
        return root;
    }
    if (data <= root->data)
        root->left = LevelOrder(root->left, data);
    else
        root->right = LevelOrder(root->right, data);
    return root;
}
Node *constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = LevelOrder(root, arr[i]);

    return root;
}
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = constructBst(arr, n);

    cout << "Inorder Traversal: ";
    inorder(root);
    return 0;
}