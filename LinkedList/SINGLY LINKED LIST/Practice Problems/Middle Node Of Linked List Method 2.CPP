#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
int length(node *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}
node* middle(node *head)
{
    node *sptr = head;
    node *fptr = head;
    while (fptr->next != nullptr)
    {
        sptr = sptr->next;
        fptr = sptr->next;
    }
    return sptr;
}
void printlist(node *head)
{
    
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();
    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE

    second->data = 2;
    second->next = third; // LINKING SECOND TO THIRD
    third->data = 3;
    third->next = nullptr;
    printlist(head);
    node *nod = new node();
    int len = length(head);
    nod = middle(head);// NTH NODE FROM END IS SAME AS LEN-N+1 NODE FROM BEGINNINNG
    cout << "\nData : " << nod->data;
}