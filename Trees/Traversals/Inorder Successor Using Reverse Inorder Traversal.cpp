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
void InorderSuccessor(binaryTree *root, int n)
{
    static binaryTree *next = nullptr;
    if(!root)
        return;
    InorderSuccessor(root->right, n);
    if(root->data == n)
    {
        if(next)
            cout << next->data << endl;
        else
            cout << "Inorder Successor does not exist ..\n";
        return;
    }
    next = root;
    InorderSuccessor(root->left, n);

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
    cout << "\nEnter the value of n : ";
    cin >> n;
    InorderSuccessor(root, n);
}
