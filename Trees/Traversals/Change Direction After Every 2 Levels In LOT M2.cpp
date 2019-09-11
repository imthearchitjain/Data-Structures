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

void level_order_modified(binaryTree *root)
{
    
    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data;
        return;
    }

    queue<binaryTree *> myQueue;
    stack<binaryTree *> myStack;

    binaryTree *temp;
    int sz;
    int ct = 0;
    bool rightToLeft = false;
    myQueue.push(root);
    while (!myQueue.empty())
    {
        ct++;

        sz = myQueue.size();
        for (int i = 0; i < sz; i++)
        {
            temp = myQueue.front();
            myQueue.pop();
            if (rightToLeft == false)
                cout << temp->data << " ";
            else
                myStack.push(temp);

            if (temp->left)
                myQueue.push(temp->left);

            if (temp->right)
                myQueue.push(temp->right);
        }

        if (rightToLeft == true)
        {
            while (!myStack.empty())
            {
                temp = myStack.top();
                myStack.pop();

                cout << temp->data << " ";
            }
        }
        if (ct == 2)
        {
            rightToLeft = !rightToLeft;
            ct = 0;
        }

        cout << "\n";
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
    level_order_modified(root);
}
