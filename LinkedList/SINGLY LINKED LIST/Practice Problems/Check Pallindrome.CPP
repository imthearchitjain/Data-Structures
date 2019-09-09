
#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *next;
};


bool isPal(node *head)
{
    if(head==nullptr)
        return false;
    stack<int>s;
    node *p=head;
    while(p)
    {
        s.push(p->data);
        p=p->next;
    }
    node *q=head;
    while(!s.empty())
    {
        if(s.top()!=q->data)
            return false;
        else {
            q=q->next;
            s.pop();
        }
    }return true;
}
void reverse2(node **head)
{
    node *q=*head;
    node *p,*r=nullptr;
    while (q) {
        p=q->next;
        q->next=r;
        r=q;
        q=p;
        
    }*head=r;
}
bool compare(node *head1,node *head2)
{
    if (head1 == nullptr && head2 == nullptr)
        return false;
    
    node *p=head1;
    node *q=head2;
    while(p && q)
    {
        if(p->data!=q->data)
            return false;
        else {
            p=p->next;
            q=q->next;
        }
    }return true;
}
bool pal(node *head)
{
    if(head==nullptr)
        return false;
    node *fast=head;
    node *slow=head;
    node *slow_prev=head;
    bool x=true;
    if(head && head->next){
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow_prev=slow;
        slow=slow->next;
    }}
    
    slow_prev->next=nullptr;
    node *head2=slow;
    reverse2(&head2);
   
    x= compare(head, head2);
    reverse2(&head2);
    slow_prev->next=head2;
    return x;
    
}



int main()
{
    node *head = new node(); //FOR SIMPLICITY TAKING ONLY THREE NODES
    node *second = new node();
    node *third = new node();
    node *fourth = new node();
    node *fifth=new node();
    
    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE
    
    second->data = 0;
    second->next = third; // LINKING SECOND TO THIRD
    third->data = 0;
    third->next = fourth;
    fourth->data = 0;
    fourth->next = fifth; // SET LAST NODE POINTER TO NULL
    fifth->data=1;
    fifth->next=nullptr;
    cout<<pal(head)<<endl;
    cout<<isPal(head)<<endl;
}
