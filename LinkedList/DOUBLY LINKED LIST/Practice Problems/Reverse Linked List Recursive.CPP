#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
    node *prev;
};

int length(node *head)
{
    int length = 0;
    node *temp = head;
    if (temp == nullptr)
    {
        return 0;
    }
    do
    {
        length++;
        temp = temp->next;
    } while (temp != head && temp != nullptr);
    return length;
}
void printlist(node *head)
{
    node *temp = head;
    if (head == nullptr)
    {
        return;
    }
    cout << "head -> ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head && temp != nullptr);
    if (temp == head)
        cout << "head";
    else
        cout << "NULL";


    cout << endl;
}
void put(node **head, int data)
{
    node *newnode = new node();
    newnode->data = data;
    if (*head == nullptr)
    {
        newnode->next = nullptr;
        newnode->prev = nullptr;
        *head = newnode;
        return;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        newnode->prev = nullptr;
        *head = newnode;
    }
    

}

node* reverse(node *head)
{
    if(!head)
        return nullptr;
    node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    
    if(head->prev==nullptr)
        return head;

    return reverse(head->prev);

}

int main()
{
    int n;
    cout << "\nEnter the no of nodes :";
    cin >> n;
    int data;
    node *head1 = new node();
    head1 = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        put(&head1, data);
    }
    head1 = reverse(head1);
    printlist(head1);
    head1 = reverse(head1);
    printlist(head1);

}