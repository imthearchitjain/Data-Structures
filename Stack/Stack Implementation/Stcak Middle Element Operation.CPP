#include <iostream>
using namespace std;
class DLLnode
{
    public:
    int data;
    DLLnode *next, *prev;
};

class myStack
{
    public:
    DLLnode *top;
    DLLnode *mid;
    int count;
};

myStack *createStack()
{
    myStack *s = new myStack();
    s->count = 0;
    return s;
}
void push(myStack *s, int data)
{
    DLLnode *newnode = new DLLnode();
    newnode->data = data;
    // since element is added to front so prev will always be null
    newnode->prev = nullptr;

    newnode->next = s->top;

    s->count += 1;

    if (s->count == 1)
        s->mid = newnode;
    else
    {
        s->top->prev = newnode;
        if (s->count % 2 == 1)
            s->mid = s->mid->prev;
    }
    s->top = newnode;
}

int pop(myStack *s)
{
    if (s->count == 0)
    {
        cout << "\nStack underflow..";
        return INT16_MIN;
    }
    else
    {
        DLLnode *temp = s->top;
        int data = temp->data;
        s->top = s->top->next;
        s->count -= 1;

        if (s->top != nullptr)
            s->top->prev = nullptr;

        if (s->count % 2 == 0)
            s->mid = s->mid->next;

        free(temp);
        return data;
    }
    
}
int midElement(myStack *s)
{
    if (s->count == 0)
    {
        cout << "\nStack is empty..";
        return INT16_MIN;
    }
    return s->mid->data;
}
int main()
{
    myStack *s = createStack();
    int n, data;
    cout << "\nEnter the no of elements in the stack : ";
    cin >> n;
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        push(s, data);
    }
    cout << "\nThe middle element of the stack : " << midElement(s);
    cout << "\nPopped Element is : " << pop(s);
    cout << "\nMiddle element after pop : " << midElement(s);
}
