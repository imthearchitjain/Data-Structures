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

void level_order_modified(binaryTree *root)
{

    if (!root)
        return;

    int dir = 0;
    binaryTree *temp;
    queue<binaryTree *> Q;
    stack<binaryTree *> S;

    S.push(root);
    while (!Q.empty() || !S.empty())
    {
        while (!S.empty())
        {
            temp = S.top();
            S.pop();
            cout << temp->data << " ";

            if (dir == 0)
            {
                if (temp->left)
                    Q.push(temp->left);
                if (temp->right)
                    Q.push(temp->right);
            }
            else
            {
                if (temp->right)
                    Q.push(temp->right);
                if (temp->left)
                    Q.push(temp->left);
            }
        }

        cout << endl;
        while (!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            cout << temp->data << " ";

            if (dir == 0)
            {
                if (temp->left)
                    S.push(temp->left);
                if (temp->right)
                    S.push(temp->right);
            }
            else
            {
                if (temp->right)
                    S.push(temp->right);
                if (temp->left)
                    S.push(temp->left);
            }
        }
        cout << endl;
        ChangeDirection(dir);
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
