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
    if (head->next == nullptr)
        return 1;
    return 1 + length(head->next);
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
    cout << "\nLinked list length is :"<<length(head);
}