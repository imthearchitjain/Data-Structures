#include <iostream>
#include <queue>
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

//traversels using recursion
void postorder(binaryTree *root)
{
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<" ";
}
void preorder(binaryTree *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);    
    preorder(root->right);
}
void inorder(binaryTree *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
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