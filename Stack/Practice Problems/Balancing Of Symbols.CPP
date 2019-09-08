//stack implementation using Linked list
#include <iostream>
#include <string>
using namespace std;

class stack
{
public:
    char data;
    stack *next;
};
void push(stack **root, char data)
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
char pop(stack **root)
{
    if (!*root)
        return '\0';
    stack *temp = *root;
    *root = (*root)->next;
    int x = temp->data;
    delete (temp);
    return x;
}
char peek(stack *root)
{
    if (!root)
        return '\0';
    return root->data;
}
void printStack(stack *root)
{
    if (!isStackEmpty(root))
    {
        cout << "\nTop-> ";
        while (root)
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
    stack *s = nullptr;
    string str;
    cout << "\nEnter an expression :";
    getline(cin, str);
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(&s, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(isStackEmpty(s))
            {
                cout << "\nExpression not balanced. ";
                break;
            }
            else if(pop(&s)!=str[i])
            {
                cout << "\nExpression not balanced. ";
                break;
            }            
        }
    }
    if(isStackEmpty(s))
        cout << "\nExpression is balanced.";
    else
        cout << "\nExpression is not balanced.";
}
