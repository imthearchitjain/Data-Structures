#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node* nth_node(node *head, int n)
{
    node *curr = head;
    int k = 0;
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
    nod = nth_node(head, 2);
    cout << "\nData : " << nod->data;
}