#include<iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;
    node(int x)
    {
        data=x;
        next=nullptr;
        
    }
};
class stack
{   public:
    node *top;
    stack()
    {
        top=nullptr;
        
    }
    void push(int x)
    {
        node *t=new node(x);
        t->next=top;
        top=t;
    }
    int isEmpty()
    {
        return top==nullptr;
    }
    
    void pop()
    {
        if(isEmpty())
        {
            return ;
        }
        node *t=top;
        top=top->next;
        free(t);
    }
    int peek()
    {
        return top->data;
    }
    void print()
    {
        node *t=top;
        while(t)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
    }
    
};

int main()
{
    //    stack *s=new stack();
    //    s->push(1);
    //    s->push(2);
    //    s->pop();
    //    s->print();
    stack s=stack();
    s.push(1);
    s.push(2);
    s.print();
}
