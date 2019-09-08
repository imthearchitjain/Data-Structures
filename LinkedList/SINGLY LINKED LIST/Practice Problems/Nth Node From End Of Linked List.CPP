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
node* nth_node(node *head, int n)
{
    node *curr = head;
    int k = 1;
    while (curr != nullptr && k < n)
    {
        k++;
        curr = curr->next;
    }
    return curr;
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
    nod = nth_node(head, len-3+1);// NTH NODE FROM END IS SAME AS LEN-N+1 NODE FROM BEGINNINNG
    cout << "\nData : " << nod->data;
}