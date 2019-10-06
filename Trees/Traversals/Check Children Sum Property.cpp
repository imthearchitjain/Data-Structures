bool childrenSum(node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (!t->left && !t->right)
        {
            continue;
        }
        if (t->left && t->right)
        {
            if (t->left->data + t->right->data != t->data)
            {
                return false;
            }
            else
            {
                q.push(t->left);
                q.push(t->right);
            }
        }
        if (t->left && !t->right)
        {
            if (t->left->data != t->data)
                return false;
            else
            {
                q.push(t->left);
            }
        }
        if (t->right && !t->left)
        {
            if (t->right->data != t->data)
                return false;
            else
            {
                q.push(t->right);
            }
        }
    }
    return true;
}
bool RchildrenSum(node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;
    if (sum == root->data && RchildrenSum(root->left) && RchildrenSum(root->right))
        return true;
    return false;
}
