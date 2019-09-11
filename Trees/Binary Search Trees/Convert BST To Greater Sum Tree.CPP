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
int sumNodes(Node *root)
{
    if(!root)
        return 0;
    else
        return root->data + sumNodes(root->left) + sumNodes(root->right);
}
void transformTree(Node *root, int sum)
{
    if(!root)
        return;
    transformTree(root->left, sum);
    sum = sum - root->data;
    root->data = sum;
    transformTree(root->right, sum);
}
int main()
{
    
    Node *root = new Node(11);
    root->left = new Node(2);
    root->right = new Node(29);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(40);
    root->right->right->left = new Node(35);
    cout << "\nInorder Traversal of constructed BST ";
    inorder(root);
    transformTree(root, sumNodes(root));
    cout << "\nInorder Traversal of transformed BST ";
    inorder(root);
    return 0;
}