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
void preorder(binaryTree *root)
{
    if (!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
vector<binaryTree*> build_all_trees(int *a, int start, int end)
{
    vector<binaryTree *> trees;
    if (start > end)
    {
        trees.push_back(nullptr);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<binaryTree *> ltrees = build_all_trees(a, start, i - 1);
        vector<binaryTree *> rtrees = build_all_trees(a, i + 1, end);
        binaryTree *root = new binaryTree(a[i]);
        for (int k = 0; k < ltrees.size(); k++)
            for (int j = 0; j < rtrees.size(); j++)
            {
                root->left = ltrees[k];
                root->right = rtrees[j];
                trees.push_back(root);
            }
    }
    return trees;
}
int main()
{
    /*binaryTree *root = nullptr;
    int n, data;
    cout << "\nEnter th eno of elements in the tree : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        insert(&root, data);
    }*/
    int n;
    cout << "\nEnter the no of nodes :";
    cin >> n;
    int a[n] ,b[n];
    cout << "\nEnter the preorder traversel of tree : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<binaryTree *> trees = build_all_trees(a, 0, n - 1);
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        cout << endl;
    }
}                         