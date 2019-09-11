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
int number(binaryTree *root)
{
    if (!root)
        return 0;
    else
        return 1 + number(root->left) + number(root->right);
}
void level_order_spiral(binaryTree *root)
{
    if (!root)
        return;
    stack<binaryTree *> s1, s2;
    s1.push(root);
    binaryTree *temp;
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            temp = s1.top();
            cout << temp->data << " ";
            s1.pop();
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        
        }
        while(!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
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
    cout << number(root) << endl;
    level_order_spiral(root);
}
