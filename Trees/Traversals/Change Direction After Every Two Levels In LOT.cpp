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
    if(!root)
        return;
    list<binaryTree *> l1;
    list<binaryTree *> l2;
    l1.push_back(root);
    binaryTree *temp;
    bool status = 1;
    while(!l1.empty() || !l2.empty())
    {
        if(status == 1)
        {
            while(!l1.empty())
            {
                temp = l1.front();
                l1.pop_front();
                cout << temp->data << " ";
                if(temp->left)
                    l2.push_back(temp->left);
                if(temp->right)
                    l2.push_back(temp->right);
            }
            cout << endl;
            while(!l2.empty())
            {
                temp = l2.front();
                l2.pop_front();
                cout << temp->data << " ";
                if(temp->left)
                    l1.push_front(temp->left);
                if(temp->right)
                    l1.push_front(temp->right);
            }
            cout << endl;
            status = 0;
        }
        else
        {
            while (!l1.empty())
            {
                temp = l1.front();
                l1.pop_front();
                cout << temp->data << " ";
                if (temp->right)
                    l2.push_back(temp->right);
                if (temp->left)
                    l2.push_back(temp->left);
            }
            cout << endl;
            while (!l2.empty())
            {
                temp = l2.front();
                l2.pop_front();
                cout << temp->data << " ";
                if (temp->right)
                    l1.push_front(temp->right);
                if (temp->left)
                    l1.push_front(temp->left);                
            }
            cout << endl;
            status = 1;
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
    level_order_modified(root);
}
