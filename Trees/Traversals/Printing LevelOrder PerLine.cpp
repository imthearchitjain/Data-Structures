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

void level_order_line(binaryTree *root)
{
    queue<binaryTree *> q;
    q.push(root);
    q.push(NULL);
    binaryTree *temp;
    while(q.size() > 1)
    {
        temp = q.front();
        q.pop();
        if(temp)
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        else
        {
            q.push(temp);
            cout << endl;
        }
        
    }
}
/*
void level_order_line1(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (t)
        {
            cout << t->data << " ";
        }
        if (!t)
        {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return;
}

void level_order_line2(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *t = q.front();
            q.pop();

            cout << t->data << " ";
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        cout << endl;
    }
}
*/

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
    level_order_line(root);
}
