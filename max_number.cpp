#include<iostream>
#include<vector>
using namespace std;


int main() {
    int n;
    cin>>n;
    bool arr[n+1];
    long long int num=1;
    vector<int>prime_numbers;
    for(int i=0;i<n;i++)
    {
        arr[i] = true;
    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==true)
        {
            prime_numbers.push_back(arr[i]);
            for(int j=i*i;j<=n;j++)
            {
                arr[j] = false;
            }
        }
    }
    int size = prime_numbers.size();
    int a;
    for(int i=0;i<prime_numbers.size();i++)
    {
        a  = prime_numbers[i];
        while(a<n)
        {
            a= a* prime_numbers[i];
        }
        a = a/prime_numbers[i];
        num = num * a;
    }
    cout<<num<<endl;
}