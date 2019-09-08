#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
};
void printlist(node *head)
{
    int count=0;
    if(head==nullptr)
    {
        cout<<"\nList is empty.";
        return;
    }
    node *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
        count++;
    }
    cout<<"\nNo of nodes in the list :"<<count<<endl;
}

void remove(node** head, int pos) // REMEMBER TO PASS THE HEAD AS DOUBLE POINTER 
{
    node* q=new node();
    q=*head;
    int k=1;
    node* p=new node();
    while(q->next!=nullptr && k<pos)
    {
        k++;
        p=q;
        q=q->next;
    }
    p->next=q->next;
    delete q;
}
int main()
{
    node* head=new node();      //FOR SIMPLICITY TAKING ONLY THREE NODES 
    node* second=new node();
    node* third =new node();

    head->data=1;       // ENTERING DATA TO NODES 
    head->next=second;  // LINKING HEAD NODE TO SECOND NODE
    second->data=2;     
    second->next=third; // LINKING SECOND TO THIRD
    third->data=3;
    third->next=nullptr;// SET LAST NODE POINTER TO NULL
    printlist(head);

    remove(&head,2);   // HEAD WILL BE PASSED BY ADDRESS IN INSERTING THE NODE TO LINKED LIST

    printlist(head);

}