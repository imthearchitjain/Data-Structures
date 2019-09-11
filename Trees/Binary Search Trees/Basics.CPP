#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    bool Ltag, Rtag;
    Node *left;
    Node *right;

    Node(int data = 0)
    {
        left = right = nullptr;
        this->data = data;
    }
};

void insert(Node **root, int data)
{
    if (!*root)
        *root = new Node(data);
    else if (data < (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}
Node *Min(Node *root)
{
    if (!root)
        return root;
    else if (!root->left)
        return root;
    else
        return Min(root->right);
}
Node *deleteNode(Node *root, int data)
{
    if (!root)
        return root;
    else if (data < (root)->data)
        (root)->left = deleteNode((root)->left, data);
    else if (data > (root)->data)
        (root)->right = deleteNode((root)->right, data);
    else
    {
        if (!(root)->left)
        {
            Node *temp = (root)->right;
            free(root);
            return temp;
        }
        else if (!(root)->right)
        {
            Node *temp = (root)->left;
            free(root);
            return temp;
        }
        else
        {
            Node *min = Min((root)->right);
            (root)->data = min->data;
            (root)->right = deleteNode((root)->right, min->data);
        }
    }
    return root;
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /
           \ 
       20   40  60   80 */

    Node *root = new Node(50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // print inoder traversal of the BST
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}