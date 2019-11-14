#include<bits/stdc++.h>
using namespace std;
/*
class Node
{
    public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

int height_balanced(Node *root, bool &status)
{
    if(!root)
        return 0;
    else if(!root->left && !root->right)
        return 0;
    else if(!status)
        return 0;
    int hl = height_balanced(root->left, status);
    int hr = height_balanced(root->right, status);

    if(abs(hl - hr) > 1)
        status = false;
    else
        return max(hl, hr) + 1;
}

void fill_stack(Node *root, stack <Node *> &s, Node *p, bool &status)
{
    if(root)
    {
        s.push(root);
        if(root == p)
        {
            status = 1;
            return;           
        }
        fill_stack(root->left, s, p, status);
        if(!status)
            fill_stack(root->right, s, p, status);
        if(!status)
            s.pop();
    }
    
}
bool cousin_node(Node *root, Node *p, Node *q)
{
    stack<Node *> s, a;
    bool status = false;
    
    fill_stack(root, s, p, status);
    status = false;
    fill_stack(root, a, q, status);

    if(s.size() != a.size())
        return 0;
    else if(s.size() <= 2)
        return 0;
    s.pop();
    a.pop();
    if(s.top() == a.top())
        return 0;
    s.pop();
    a.pop();
    if(s.top() == a.top())
        return 1;
    return 0;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    //root->left->left->left = new Node(8);

    bool status = true;
    height_balanced(root, status);

    if (status)
        cout << "\nTree is Balanced.";
    else
        cout << "\nTree is Not Balanced.";

    if(cousin_node(root, root->right, root->left))
        cout << "\nCousin";
    else
        cout << "\nNo Cousin";

    cout << endl;
}
*/
typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;
typedef struct Qnode
{
    Node *data;
    Qnode *next;
}QNode;

typedef struct Queue
{
    Qnode *front, *rear;
} Queue;

QNode *createQN(Node *n)
{
    Qnode *qn = (QNode *)malloc(sizeof(Qnode));
    qn->data = n;
    qn->next = NULL;
    return qn;
}
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void Insert(Queue *q, Node *n)
{
    Qnode *qn = createQN(n);
    if(q->front == NULL)
    {
        q->front = q->rear = qn;
        return;
    }
    else
    {
        q->rear->next = qn;
        q->rear = qn;
    }
}
void pop(Queue *q)
{
    if(q->front == NULL)
        return;
    else if(q->front == q->rear)
    {
        q->front = q->rear = NULL;
        return;
    }
    else
        q->front = q->front->next;
}
Node *createN(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
Node* peek(Queue *q)
{
    if(q->front == NULL)
        return NULL;
    else
        return q->front->data;
}

Node* insert(Node *root, int data)
{
    Node *t = createN(data);
    Queue *q = createQueue();
    if (!root)
    {
        root = t;
        return root;
    }
    Insert(q, root); // root ka address pushed in queue
    while (q->front)
    {
        Node *x = peek(q);
        pop(q);
        if (x->left == NULL)
        {
            x->left = t;
            return root;
        }
        else
        {
            Insert(q, x->left);
        }
        if (x->right == nullptr)
        {
            x->right = t;
            return root;
        }
        else
        {
            Insert(q, x->right);
        }
    }
}

Node* deleteDeepest(Node *root, Node *t)
{
    Node *x;
    Queue *q = createQueue();
    Insert(q, root);
    while (q->front)
    {
        x = peek(q);
        pop(q);
        if (x == t)
        {
            x = nullptr;
            delete (t);
            return root;
        }
        if (x->left != nullptr)
        {
            if (x->left == t)
            {
                x->left = nullptr;
                delete (t);
                return root;
            }
            else
            {
                Insert(q, x->left);
            }
        }
        if (x->right != nullptr)
        {
            if (x->right == t)
            {
                x->right = nullptr;
                delete (t);
                return root;
            }
            else
            {
                Insert(q, x->right);
            }
        }
    }
    return root;
}
Node* Delete(Node *root, int data)
{
    Node *x, *t;
    if (!root)
    {
        return root;
    }
    Queue *q = createQueue();
    Insert(q, root);
    while (q->front)
    {
        t = peek(q);
        pop(q);
        if (t->data == data)
        {
            x = t;
        }
        if (t->left)
        {
            Insert(q, t->left);
        }
        if (t->right)
        {
            Insert(q, t->right);
        }
    }
    int p = t->data;
    root = deleteDeepest(root, t);
    x->data = p;
    return root;
}
void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x); // else insert(&tree,x);
    }
    postorder(root);
    root = Delete(root, 5);
    postorder(root);
}
