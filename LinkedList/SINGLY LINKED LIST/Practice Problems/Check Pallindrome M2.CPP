#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
};
bool comparelists(node *, node *);
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
void push(node **head, int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
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
bool ispalindrome(node *head)
{
    node *sptr = head, *fptr = head;
    node *s_half, *prev_sptr = head;
    node *midnode = nullptr;
    bool res = true;
    if (head != nullptr && head->next != nullptr)
    {
        while (fptr != nullptr && fptr->next != nullptr)
        {
            fptr = fptr->next->next;
            prev_sptr = sptr;
            sptr = sptr->next;
        }

        if (fptr != nullptr)
        {
            midnode = sptr;
            sptr = sptr->next;
        }
        s_half = sptr;
        prev_sptr->next = nullptr;
        reverse(&s_half);
        res = comparelists(head, s_half);
        reverse(&s_half);
        if (midnode != nullptr)
        {
            prev_sptr->next = midnode;
            midnode->next = s_half;
        }
        else
        {
            prev_sptr->next = s_half;
        }
        
    }
    return res;
}
bool comparelists(node *first, node* second)
{
    bool status = true;
    while (first != nullptr)
    {
        if(first->data!=second->data)
        {
            status = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    return status;
}

int main()
{
    int n;
    cout << "\nEnter the no of nodes you want to enter :";
    cin >> n;
    int data;
    node *head = new node();
    head = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        push(&head, data);
    }
    reverse(&head);
    printlist(head);
    bool res = ispalindrome(head);
    cout << "\nPaindrome status : " << res;
}