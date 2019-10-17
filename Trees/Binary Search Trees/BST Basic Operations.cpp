#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class bst
{
public:
    node *root;
    bst()
    {
        root = 0;
    }
};

node *insert(node *root, int x)
{
    node *t = new node(x);
    if (!root)
    {
        root = t;
        return root;
    }
    if (root->data < x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return t;
}
bool rec_search(node *root, int x)
{
    if (root == nullptr)
        return false;
    if (root->data == x)
        return true;
    else if (root->data < x)
        return rec_search(root->left, x);
    else
        return rec_search(root->right, x);
}
bool iterative_search(node *root, int x)
{
    if (!root)
        return false;
    node *t = root;
    while (t != nullptr)
    {
        if (t->data == x)
            return true;
        else if (t->data < x)
            t = t->left;
        else
            t = t->right;
    }
    return false;
}

int minValue(node *root)
{
    if (!root)
        return INT_MIN;
    else if (!root->left)
        return root->data;
    else
        return minValue(root->left);
}
int maxValue(node *root)
{
    if (!root)
        return INT_MAX;
    else if (!root->right)
        return root->data;
    else
        return maxValue(root->right);
}
node *minI(node *root)
{
    if (!root)
        return root;

    while (root->left)
    {
        root = root->left;
    }
    return root;
}
node *deleteNode(node *root, int x)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,then it lies in left subtree

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    // if key is same as root's key, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete (root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = minI(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
bool isBST(node *root)
{
    if (!root)
        return false;
    if (root->left && maxValue(root->left) > root->data)
        return (false);

    if (root->right && minValue(root->right) < root->data)
        return (false);

    if (!isBST(root->left) || !isBST(root->right))
        return (false);

    return (true);
}

node *createBST(int arr[], int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        node *root = new node(arr[mid]);
        root->left = createBST(arr, start, mid - 1);
        root->right = createBST(arr, mid + 1, end);
        return root;
    }
    return nullptr;
}

void reverseinorder(node * root, int a, int prev, int &succ)
{
    if(root)
    {
        reverseinorder(root->right, a, prev, succ);
        if(root->data == a)
            succ = prev;
        else
            prev = root->data;
        reverseinorder(root->left, a, prev, succ);
        
    }
}
void inorderpred(node * root, int a, int prev, int &pred)
{
    if(root)
    {
        inorderpred(root->left, a, prev, pred);
        if(root->data == a)
            pred = prev;
        else
            prev = root->data;
        inorderpred(root->right, a, prev, pred);
        
    }
}

int inorderpredeccesor(node *root, int a)
{
    int prev = INT_MIN;
    int pred = 0;
    inorderpred(root, a, prev, pred);
    return pred;
}

int inordersuccesor(node *root, int a)
{
    int prev = INT_MIN;
    int succ = 0;
    reverseinorder(root, a, prev, succ);
    return succ;
}

void preorder(node *root)
{
    if(root)
    {
        cout << root->data <<  " ";
        preorder(root->left);
        preorder(root->right);
    }

}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }    
}

int main()
{
    bst *tree = new bst();
    int n;
    cin >> n;
    int data;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bst *t = new bst();
    t->root = createBST(arr, 0, n - 1);
    inorder(t->root);
    cout << endl;
    preorder(t->root);
    cout << endl;
    int a;
    cin >> a;
    cout << inordersuccesor(t->root, a);
    cout << inorderpredeccesor(t->root, a);
}
