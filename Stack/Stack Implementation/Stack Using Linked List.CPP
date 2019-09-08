//stack implementation using Linked list
#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    stack *next;
};
void push(stack **root, int data)
{
    stack *newnode = new stack();
    newnode->data = data;
    newnode->next = *root;
    *root = newnode;
}
bool isStackEmpty(stack *root)
{
    return root == nullptr;
}
int pop(stack **root)
{
    if (!*root)
        return INT16_MIN;
    stack *temp = *root;
    *root = (*root)->next;
    int x = temp->data;
    delete (temp);
    return x;
}
int peek(stack *root)
{
    if (!root)
        return INT16_MIN;
    return root->data;
}
void printStack(stack *root)
{
    if(!isStackEmpty(root))
    {
        cout << "\nTop-> ";
        while(root)
        {
            cout << root->data << " ";
            root = root->next;
        }
    }
    else
    {
        cout << "\nStack Empty....\n";
    }
}

int main()
{
    stack *s=nullptr;
    int n;
    cout << "\nEnter the no of elements to be pushed : ";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter data :";
        cin >> data;
        push(&s, data);
    }
    printStack(s);
    cout << "\nPopped Element is : " << pop(&s);
    printStack(s);
}
