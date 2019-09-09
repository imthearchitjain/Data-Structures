#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
    
}

class maxheap
{
    int *a;
    int size;
    int capacity;
public:
    maxheap(int c)
    {
        capacity=c;
        size=0;
        a=new int[c];
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
    void insert(int x)
    {
        if(isFull())
        {
            return;
        }
        a[size]=x;
        size++;
        int i=size-1;
        while(i>=0 && a[parent(i)]<a[i])
        {
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
        
    }
    void heapify(int i)
    {
        int l=lchild(i);
        int r=rchild(i);
        int max=i;
        if(l<size && a[l]>a[max])
        {
            max=l;
        }
        if(r<size && a[r]>a[max])
        {
            max=r;
        }
        if(max!=i )
        {
            swap(a[i],a[max]);
            heapify(max);
        }
    }
    

    void decreaseKey(int i,int x)
    {
        if(i>=size)
            return;
   
        a[i]=x;
        heapify(i);
    }
    void increaseKey(int i,int x)
    {
        if(i>=size)
            return;
        a[i]=x;
        while (i>=0 && a[parent(i)]<a[i]) {
            swap(a[i],a[parent(i)]);
            i=parent(i);
        }
        
    }
    
    int  extractMax()
    {
        if(size==0)
        {
            return INT_MIN;
        }
        if(size==1)
        {
            size--;
            return a[0];
        }
        
        int x=a[0];
        a[0]=a[size-1];
        size--;
        heapify(0);
        return x;

    }
    int deleteKey_1(int i)
    {
        int x=a[i];
        a[i]=a[size-1];
        size--;
        heapify(i);
        return x;
    }
    void  deleteKey_2(int i)
    {
        increaseKey(i,INT_MAX);
        extractMax();
        
    }
    void print()
    {
        for (int i=0; i<size; i++) {
            cout<<a[i]<<" ";
        }
    }
    
    
};



int main()
{
    int maxsize;
    cin>>maxsize;
    maxheap *h=new maxheap(maxsize);   // this will access by arrow operator because it is pointer.
    // maxheap h(maxsize);   // this will access by dot operator
    int size;
    cin>>size;
    int data;
    for (int i=0; i<size; i++) {
        cin>>data;
        h->insert(data);
    }
    h->print();
    h->decreaseKey(2, 0);
    cout << endl;
    h->print();
    h->increaseKey(6, 8);
    cout << endl;
    h->print();
    
    
}



