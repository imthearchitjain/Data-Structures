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

void MorrisTraversel(binaryTree *root)
{
    if (!root)
        return;
    binaryTree *curr, *pre;
    curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->right && pre->right != curr)
                pre = pre->right;
            if (!pre->right)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
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
    cout << "\nMorris Traversel : ";
    MorrisTraversel(root);
}