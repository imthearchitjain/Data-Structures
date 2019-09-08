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
node * copy_reverse_list(const node *head)
{
    node *nhead = new node();

    nhead->data = head->data;
    nhead->next = nullptr;
    head = head->next;
    while (head != nullptr)
    {
        node *temp = new node();
        temp->data = head->data;
        temp->next = nhead;
        nhead = temp;
        head = head->next;
    }
    return nhead;
}
bool palindrome_list(node *head1, node *head2)
{
    bool status = true;
    while(head1!=nullptr)
    {
        if (head1->data != head2->data)
        {
            status = false;
            break;
        }
        head1=haed1->next;
        head2=head2->next;
    }
    return status;
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
    node *head1 = copy_reverse_list(head);
    cout << "\nPalindrome status : " << palindrome_list(head, head1);
}
