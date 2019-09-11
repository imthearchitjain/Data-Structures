#include <bits/stdc++.h>
using namespace std;
class binaryTree
{
public:
    int data;
    binaryTree *left;
    binaryTree *right;

    binaryTree(int data =0)
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

void postorder(binaryTree *root)
{
    stack<binaryTree *> s;
    binaryTree *prev = nullptr;
    do
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
        while (root == nullptr && !s.empty())
        {
            root = s.top();
            if (root->right == nullptr || root->right == prev)
            {
                cout << root->data << " ";
                s.pop();
                prev = root;
                root = nullptr;
            }
            else
                root = root->right;
        }

    } while (!s.empty());
}
void preorder(binaryTree *root)
{
    stack<binaryTree *> s;
    while (1)
    {
        while (root)
        {
            cout << root->data << " ";
            s.push(root);
            root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        s.pop();
        root = root->right;
    }

}
void inorder(binaryTree *root)
{
    stack<binaryTree *> s;
    while (1)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        if (s.empty())
            break;
        root = s.top();
        cout << root->data << " ";
        s.pop();
        root = root->right;
    }
}
int main()
{
    binaryTree *root=nullptr;
    int n, data;
    cout << "\nEnter th eno of elements in the tree : ";
    cin >> n;
    while(n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nPostorder traversel of tree : ";
    postorder(root);
    cout << "\nPreorder traversel of tree : ";
    preorder(root);
    cout << "\nInorder traversel of tree : ";
    inorder(root);
}