#include <iostream>
#include <queue>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
class node
{
public:
    node *left, *right;
    int data;
    node(int data)
    {
        this->data = data;
        left = right = 0;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        node *t = new node(data);
        queue<node *> q;
        if (!root)
        {
            root = t;
            return;
        }
        q.push(root); // root ka address pushed in queue
        while (!q.empty())
        {
            node *x = q.front();
            q.pop();
            if (x->left == nullptr)
            {
                x->left = t;
                return;
            }
            else
            {
                q.push(x->left);
            }
            if (x->right == nullptr)
            {
                x->right = t;
                return;
            }
            else
            {
                q.push(x->right);
            }
        }
    }

    void print_levelorder()
    {
        if (!root)
            return;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *x = q.front();
            cout << x->data << " ";
            q.pop();
            if (x->left != nullptr)
                q.push(x->left);
            if (x->right != nullptr)
                q.push(x->right);
        }
    }
    void deleteDeepest(node *t)
    {
        node *x;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            x = q.front();
            q.pop();
            if (x == t)
            {
                x = nullptr;
                delete (t);
                return;
            }
            if (x->left != nullptr)
            {
                if (x->left == t)
                {
                    x->left = nullptr;
                    delete (t);
                    return;
                }
                else
                {
                    q.push(x->left);
                }
            }
            if (x->right != nullptr)
            {
                if (x->right == t)
                {
                    x->right = nullptr;
                    delete (t);
                    return;
                }
                else
                {
                    q.push(x->right);
                }
            }
        }
        free(x);
    }
    void Delete(int data)
    {
        node *x, *t;
        if (!root)
        {
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            t = q.front();
            q.pop();
            if (t->data == data)
            {
                x = t;
            }
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        int p = t->data;
        deleteDeepest(t);
        x->data = p;
    }
};
void preorder(node *root)
{

    if (root)
    {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{

    if (root)
    {

        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
void postorder(node *root)
{

    if (root)
    {

        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}
int count(node *root)
{

    if (root == nullptr)
        return 0;
    return count(root->left) + 1 + count(root->right);
}
int count_leafNodes(node *root)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = count_leafNodes(root->left);
    y = count_leafNodes(root->right);
    if (!root->left && !root->right)
        return x + y + 1;
    else
    {
        return x + y;
    }
}
int count_deg2(node *root)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = count_deg2(root->left);
    y = count_deg2(root->right);
    if (root->left && root->right)
        return x + y + 1;
    else
    {
        return x + y;
    }
}
int count_deg1(node *root)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = count_deg2(root->left);
    y = count_deg2(root->right);
    if ((root->left != nullptr) ^ (root->right != nullptr))
        return x + y + 1;
    //(root->left && !root->right) || (!root->left && root->right)
    else
    {
        return x + y;
    }
}
int count_deg1_or_deg2(node *root)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = count_deg1_or_deg2(root->left);
    y = count_deg1_or_deg2(root->right);
    if (root->left || root->right)
        return x + y + 1;
    else
    {
        return x + y;
    }
}
int height_index1(node *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int x = height_index1(root->left);
        int y = height_index1(root->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
}
int height_0index(node *root)
{

    if (root == nullptr)
    {
        return 0;
    }
    if (!root->left && !root->right)
        return 0;
    else
    {
        int x = height_0index(root->left);
        int y = height_0index(root->right);
        if (x > y)
        {
            return x + 1;
        }
        else
            return y + 1;
    }
}
void printEachLevel(node *root, int index)
{
    if (root == nullptr)
        return;
    if (index == 1)
    {
        cout << root->data << endl;
    }

    else if (index > 1)
    {
        printEachLevel(root->left, index - 1);
        printEachLevel(root->right, index - 1);
    }
}

void levelOrder(node *root)
{
    int h = height_index1(root);
    for (int i = 1; i <= h; i++)
    {
        printEachLevel(root, i);
    }
}
int main()
{
    binaryTree *tree = new binaryTree();
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tree->insert(x); // else insert(&tree,x);
    }
}
