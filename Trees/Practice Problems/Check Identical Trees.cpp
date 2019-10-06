bool identical(node *root1, node *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (!root1 || !root2)
    {
        return false;
    }
    if (root1 && root2)
    {
        return root1->data == root2->data && identical(root1->left, root2->left) && identical(root1->right, root2->right);
    }
    
}
