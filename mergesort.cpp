#include<iostream>
using namespace std;

void Mergesort(int arr[],int l, int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i] = arr[m+1+i];
    }

    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
    return;
}

void merge(int arr[],int l,int r)
{
    if(l>=r)
    return;
    int m = (l+r)/2;
    merge(arr,l,m);
    merge(arr,m+1,r); 
    Mergesort(arr,l,m,r);
}

void printArray(int A[],int size)
{
    for(int i=0;i<size;i++)
    cout<<A[i]<<" ";
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge(arr,0,n-1);
    printArray(arr,n);
    return 0;
}