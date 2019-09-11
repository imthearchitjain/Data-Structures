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

void inorder(Node *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int nextGreater(int pre[], int n, int a)
{
    for (int i = 0; i < n; i++)
        if(pre[i] > a)
            return i;
}
Node* constructBST(int pre[],int n)
{
    if(n == 0)
        return nullptr;
    Node *root = new Node(pre[0]);
    int pos = nextGreater(pre, n, pre[0]);
    root->left = constructBST(pre + 1, pos - 1);
    root->right = constructBST(pre + pos, n - pos);
    return root;
}
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    Node *root = constructBST(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    inorder(root);

    return 0;
}