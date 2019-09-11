//binary Tree Array Implementation
#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int&b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
bool compare(Node *a, int b)
{
    return a->data == b;
}
class BinaryTree{
    vector<Node*> arr;
    int size;

public:
    BinaryTree()
    {
        size = 0;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void insert(int x)
    {
        Node *new_node = new Node(x);
        arr.push_back(new_node);
        for (int i = 0; i < arr.size() / 2; i++)
        {
            if(left(i) < arr.size())
                arr[i]->left = arr[left(i)];
            if(right(i) < arr.size())
                arr[i]->right = arr[right(i)];
        }
        size++;
    }
    bool empty()
    {
        return size == 0;
    }
    int height(int i = 0)
    {
        if(left(i) > arr.size())
            return 0;
        int l = height(left(i));
        int r = height(right(i));
        if(l > r)
            return l + 1;
        else
            return r + 1;
    }
    void deleteNode(int x)
    {
        
        int pos = -1;
        for (int i = 0; i < arr.size(); i++)
            if(arr[i]->data == x)
            {    
                pos = i;
                break;
            }
        if(pos != -1)
        {
            while (left(pos) < arr.size())
            {
                pos = left(pos);
            }
            arr[pos] = nullptr;
            size--;
        }
    }
    void print(int i = 0)
    {
        for (int i = 0; i < arr.size(); i++)
            if(arr[i] != nullptr)
                cout << arr[i]->data << " ";
        cout << endl;
    }
};

int main()
{
    BinaryTree *tree = new BinaryTree();
    int n, data;
    cout << "Enter the no of elements in the tree :";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        tree->insert(data);
    }
    tree->print();
    cout << "Enter data to be deleted : ";
    cin >> data;
    tree->deleteNode(data);
    tree->print();
}