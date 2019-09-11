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
    void print()
    {
        //pre order traversal technique
        if(!this)
            return;
        cout << data << " ";
        left->print();
        right->print();
    }

};
void insert(binaryTree **root, int data)
{
    if(!(*root))
    {
        *root = new binaryTree(data);
        return;
    }
    // insertion using level order traversel
    binaryTree *newnode = new binaryTree(data);
    queue<binaryTree *> q;
    q.push(*root);
    while(!q.empty())
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
void deletedeepest(binaryTree **root, binaryTree *dnode)
{
    queue<binaryTree *> q;
    q.push(*root);
    binaryTree *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == dnode)
        {
            temp = nullptr;
            delete (temp);
            return;
        }
        if (temp->left)
        {
            if(temp->left == dnode)
            {
                temp->left = nullptr;
                delete (temp->left);
                return;
            }
            else
                q.push(temp->left);
        }
        if (temp->right)
        {
            if (temp->right == dnode)
            {
                temp->right = nullptr;
                delete (temp->right);
                return;
            }
            else
                q.push(temp->right);
        }
    }
}
void deletion(binaryTree **root, int data)
{
    queue<binaryTree *> q;
    q.push(*root);
    binaryTree *temp = new binaryTree() , *keynode =nullptr;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == data)
            keynode = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    int x = temp->data;
    deletedeepest(root, temp);
    keynode->data = x;
}
int main()
{
    binaryTree *root=nullptr;
    int n, data;
    cout << "\nEnter the no of elements in the tree : ";
    cin >> n;
    while(n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nTree : ";
    root->print();
    cout << "\nEnter the data to be deleted : ";
    cin >> data;
    deletion(&root, data);
    root->print();
}