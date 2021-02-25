#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char*);

int main() {
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        cout<<getMaxOccuringChar(str)<<endl;
    }
}

char getMaxOccuringChar(char* str)
{
    // Your code here
    int freq = 0;
    int max_freq = 0;
    char ch;
    for(int j=97;j<=122;j++)
    {
        int i=0;
        while(str[i]!='\0')
        {
            if(str[i]==char(j))
            freq++;
            i++;
        }
        if(freq>max_freq)
        {
            max_freq = freq;
            ch = char(j);
        }
        freq = 0;
    }
    return ch;
}