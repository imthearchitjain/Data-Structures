#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void printlist(node *head)
{
    int count = 0;
    if (head == nullptr)
    {
        cout << "\nList is empty.";
        return;
    }
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
        count++;
    }
    cout << "\nNo of nodes in the list :" << count << endl;
}

void reverse(node **head)
{
    node *p = new node();
    node *q = new node();
    q = (*head);
    node *temp = new node();
    while (q->next != nullptr)
    {
        temp = q;
        p = temp->next;
        temp->next = (q->next)->next;
        p->next = *head;
        *head = p;
    }
    
}
void reverse1(node **head)
{
    if(*head==nullptr || (*head)->next==nullptr)
        return ;
    node *q=*head;
    node*p=(*head)->next;
    node *r=nullptr;
    while(q)
    {
        q->next=r;
        r=q;
        q=p;
        if(p!=nullptr)
        {
            p=p->next;
        }
    }*head=r;
    
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


int main()
{
    node *head = new node(); //FOR SIMPLICITY TAKING ONLY THREE NODES
    node *second = new node();
    node *third = new node();
    node *fourth = new node();
    
    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE
    
    second->data = 2;
    second->next = third; // LINKING SECOND TO THIRD
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = nullptr; // SET LAST NODE POINTER TO NULL
    printlist(head);
    reverse2(&head);
    printlist(head);
}
