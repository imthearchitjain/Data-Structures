int max_recursive(node *root)
{
    if (!root)
        return INT_MIN;
    int l = max_recursive(root->left);
    int r = max_recursive(root->right);
    if (l >= r && l >= root->data)
    {
        return l;
    }
    else if (r >= l && r >= root->data)
    {
        return r;
    }
    else
        return root->data;
}
int maxElementTree(node *root)
{
    int max = INT16_MIN;
    int left, right;
    if (root)
    {
        left = maxElementTree(root->left);
        right = maxElementTree(root->right);

        if (right < left)
            max = left;
        else
            max = right;
        if (max < root->data)
            max = root->data;
    }
    return max;
}
int max_iterative(node *root)
{
    queue<node *> q;
    int max = INT_MIN;
    q.push(root);
    while (!q.empty())
    {
        node *t = q.front();
        if (t->data > max)
        {
            max = t->data;
        }
        q.pop();
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
    return max;
}
int search_iterative(node *root, int x)
{
    queue<node *> q;

    q.push(root);
    while (!q.empty())
    {
        node *t = q.front();
        if (t->data == x)
            return 1;
        q.pop();
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
    return 0;
}

bool search_recursive(node *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }

    bool l = search_recursive(root->left, x);
    bool r = search_recursive(root->right, x);
    return l || r;
}
bool searchTree(node *root, int data)
{
    if (!root)
        return 0;
    if (data == root->data)
        return 1;
    bool temp = searchTree(root->left, data);
    if (temp != 0)
        return temp;
    else
        return searchTree(root->right, data);
}
