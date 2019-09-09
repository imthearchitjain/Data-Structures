#include <iostream>

using namespace std;

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
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int a[],int n,int i)
{
    int l=lchild(i);
    int r=rchild(i);
    int max=i;
    if(l<n && a[l]>a[max])
        max=l;
    if(r<n && a[r]>a[max])
        max=r;
    if(max!=i)
    {
        swap(&a[i],&a[max]);
        heapify(a,n,max);
    }
}

void build(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a, n, i);
    }
}
int extractMax(int a[],int &n)
{
    int x=a[0];
    a[0]=a[n-1];
    n--;
    
    heapify(a,n,0);
    
    return x;
}

int main()
{
    int arr[]={1,9,6,7,4,2,5};
    int k;
    cin>>k;
    int n=7;
    build(arr, 7);
    for (int i=1; i<=k; i++) {
        cout<<extractMax(arr, n)<<" ";
    }
}

