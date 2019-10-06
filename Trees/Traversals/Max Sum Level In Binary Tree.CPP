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
int maxLevelSum(binaryTree *root)
{
    if (!root)
        return 0;
    queue<binaryTree *> q;
    int max = INT16_MIN;
    int mlevel=0, level=0;
    int i = 0;
    int sum = 0;
    binaryTree *temp;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if(!temp)
        {
            if (!q.empty())
                q.push(nullptr);
            if (max < sum)
            {
                max = sum;
                mlevel = level;
            }
            sum = 0;
            
            level++;
        }
        else
        {
            sum += temp->data;
            if (temp->left)
            {
                q.push(temp->left);
            } 
            if (temp->right)
            {
                q.push(temp->right);
            }
                
        }
        
    }
    return mlevel;
}
/*
int Sum(queue<node *> q)
{
    int s = 0;
    while (!q.empty())
    {
        node *t = q.front();
        if (t)
        {
            s = s + t->data;
        }
        q.pop();
    }
    return s;
}
int maxSumLevel(node *root)
{
    if (!root)
        return -1;
    queue<node *> q;
    int level = 0, maxlevel = 0;
    int curr_sum = 0;
    q.push(root);
    q.push(nullptr);
    curr_sum = root->data;
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (t == nullptr)
        {

            if (!q.empty())
                q.push(nullptr);
            level++;
            if (Sum(q) > curr_sum)
            {
                curr_sum = Sum(q);
                maxlevel = level;
            }
        }
        else
        {
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return maxlevel;
}
*/
int main()
{
    int n;
    binaryTree *root = nullptr;
    cout << "\nEnter no of elements in binary tree : ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        insert(&root, data);
    }
    cout << "\nLevel having max sum : " << maxLevelSum(root);

}
