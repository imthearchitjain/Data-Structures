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
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
        count++;
    } while (temp != head);
    cout << "\nNo of nodes in the list :" << count << endl;
}

void insert_end(node **head)
{
    node *p = new node();
    node *q = new node();
    p=*head;
    do
    {
        q=p;
        p=p->next;
    } while (p!=*head);
    int data;
    cout<<"\nEnter the data :";cin>>data;
    node *newnode=new node();
    newnode->data=data;
    newnode->next=p;
    q->next=newnode;


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
    fourth->next = head; // SET LAST NODE POINTER TO HEAD
    printlist(head);
    insert_end(&head);
    printlist(head);
}
