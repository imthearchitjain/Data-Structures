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
void inorder_array(binaryTree *root,vector<int> &in)
{
    if (!root)
        return;
    inorder_array(root->left, in);
    in.push_back(root->data);
    inorder_array(root->right, in);
}
int sum_pre_succ(vector <int> in,binaryTree *node)
{
    int i;
    for (i = 0; i < in.size(); i++)
        if (in[i] == node->data)
            break;
    if (i == 0)
        return in[i + 1];
    if (i == in.size() - 1)
        return in[i - 1];
    return in[i - 1] + in[i + 1];
}       
void sum_inorder_pre_succ(binaryTree *root,vector<int> in, int &i)
{
    if (!root)
        return;
    sum_inorder_pre_succ(root->left, in, i);
    root->data = in[i - 1] + in[i + 1];
    i++;
    sum_inorder_pre_succ(root->right, in, i);
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
    vector<int> in;
    in.push_back(0);
    inorder_array(root, in);
    in.push_back(0);
    int i = 1;
    sum_inorder_pre_succ(root, in, i);
    levelOrder(root);
}                         