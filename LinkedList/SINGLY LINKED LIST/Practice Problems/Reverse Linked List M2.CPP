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
void printlist(node *head)
{
    
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void reverse(node **head)
{
    node *prev = nullptr;
    node *curr = *head;
    node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;

}

int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();
    node *fifth = new node();

    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE

    second->data = 2;
    second->next = third; // LINKING SECOND TO THIRD
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = nullptr;
    reverse(&head);
    printlist(head);
    
}