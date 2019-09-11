#include <bits/stdc++.h>
using namespace std;
#define ChangeDirection(Dir) ((Dir) = 1 - (Dir))
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
    void print()
    {
        //pre order traversal technique
        if (!this)
            return;
        cout << data << " ";
        left->print();
        right->print();
    }
};
void insert(binaryTree **root, int data)
{
    if (!(*root))
    {
        *root = new binaryTree(data);
        return;
    }
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

void reverse_level_order(binaryTree *root)
{
    if(!root)
        return;
    stack<binaryTree *> s;
    queue<binaryTree *> q;
    q.push(root);
    binaryTree *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        s.push(temp);
        if (temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        
    }
    while(!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    binaryTree *root = nullptr;
    int n, data;
    cout << "\nEnter the no of elements in the tree : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        insert(&root, data);
    }
    reverse_level_order(root);
}