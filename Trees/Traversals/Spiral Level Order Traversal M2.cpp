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
int height(binaryTree *root)
{
    if (!root)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

void print_given_level(binaryTree *root, int level, int status)
{
    if(!root)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        if (status)
        {
            print_given_level(root->left, level - 1, status);
            print_given_level(root->right, level - 1, status);
        }
        else
        {
            print_given_level(root->right, level - 1, status);
            print_given_level(root->left, level - 1, status);
        }
    }
}
void level_order_spiral(binaryTree *root)
{
    int h = height(root);
    int i;
    bool status = false;
    for (i = 1; i <= h; i++)
    {
        print_given_level(root, i, status);
        status = !status;
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
    level_order_spiral(root);
}
