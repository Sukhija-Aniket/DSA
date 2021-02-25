#include<iostream>
using namespace std;

int left_max(int arr[],int n,int i)
{
    int maximum = 0;
    for(int j=0;j<=i;j++)
    {
        maximum = max(maximum,arr[i]);
    }
    return maximum;
}

int right_max(int arr[],int n,int i)
{
    int maximum = 0;
    for(int j=i;i<=n;i++)
    {
        maximum = max(maximum,arr[i]);
    }
    return maximum;
}

int Falling_water(int arr[],int n)
{
    int total = 0;
    for(int i=1;i<n-1;i++)
    {
        int left = left_max(arr,n,i);
        int right = right_max(arr,n,i);
        total = total + min(left,right)-arr[i];
    }
    return total;
}

int max_water_fall(int arr[],int n)
{
    int total = 0;
    int val_left = 0;
    int val_right = 0;
    int right_max = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>right_max)
        {
            right_max = arr[i];
            val_right = i;
        }
    }
    for(int j = val_left+1;j<val_right;j++)
    {
        if(arr[val_left]<=arr[j])
        {
            val_left = j;
        }
        else
        {
            total = total + min(arr[val_left],arr[val_right]) - arr[j];
        }
    }
    val_left = n-1;
    for(int j=n-1;j>val_right;j--)
    {
        if(arr[val_left]<=arr[j])
        {
            val_left = j;
        }
        else
        {
            total = total + min(arr[val_left],arr[val_right])-arr[j];
        }
    }
    return total; 
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = max_water_fall(arr,n);
    cout<<ans<<endl;
    return 0;
}

