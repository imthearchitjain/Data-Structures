#include <iostream>
using namespace std;


class element
{
public:
    int data;
    int priority;
//    element(int x,int p)
//    {
//        data=x;
//        priority=p;
//    }
};
void swap(element &a,element &b)
{
    element t=a;
    a=b;
    b=t;
    
}
class priorityQueue
{
    
public:
    element *a;
    int size;
    int capacity;
    
    priorityQueue(int c)
    {
        capacity=c;
        size=0;
        a=new element[c];
    }
   
    int parent(int i)
    {
        return (i-1)/2;
    }
    int lchild(int i)
    {
        return 2*i+1;
    }
    int rchild(int i)
    {
        return 2*i+2;
    }
    bool isEmpty()
    {
        return size==0;
    }
    bool isFull()
    {
        return size==capacity;
    }
    void insert(int x,int p)
    {
        element e;
        e.data=x;
        e.priority=p;
        if(isFull())
            return;
        
        a[size]=e;
        size++;
        int i=size-1;
        while(i!=0 && a[i].priority>a[parent(i)].priority)
        {
            swap(a[i],a[parent(i)]);
            i=parent(i);
        }
    }
    
    void heapify(int i)
    {
        int l=lchild(i);
        int r=rchild(i);
        int max=i;
        if(l<size && a[l].priority>a[max].priority)
        {
            max=l;
        }
        if(r<size && a[r].priority>a[max].priority)
        {
            max=r;
        }
        if(max!=i )
        {
            swap(a[i],a[max]);
            heapify(max);
        }
    }
    

    
    
    
    element remove()
    {
        if(size==0)
        {
            element e;
            e.data = INT_MIN;
            e.priority = -1;
            return e;
        }
        if(size==1)
        {
            size--;
            return a[0];
        }
        
        element x=a[0];
        a[0]=a[size-1];
        size--;
        heapify(0);
        return x;

    }
    
    void print()
    {
        for(int i = 0;i < size;i++)
            cout << a[i].data << " ";
        cout << endl;
    }
    
};



int main()
{
    int maxsize;
    cin>>maxsize;
    priorityQueue *pq=new priorityQueue(maxsize);
    
    int size;
    cin>>size;
    int data, priority;
    for (int i=0; i<size; i++) {
        cin>>data;
        cin >> priority;
        pq->insert(data, priority);
    }
    pq->print();
    pq->remove();
    
    pq->print();
    }



