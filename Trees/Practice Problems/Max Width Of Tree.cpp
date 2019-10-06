int maxWidth(node *root)
{
    if (!root)
        return 0;
    int wMax = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        wMax = max(wMax, count);
        for (int i = 0; i < count; i++)
        {
            node *t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return wMax;
}
