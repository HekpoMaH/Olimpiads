#include<iostream>
#include<stdlib.h>
using namespace std;
int a[5000], n, sum1;
int main()
{
    
    cin>>sum1>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    int r, br=0, brmin=sum1;
    r=sum1;int i, rec, in;
    for(int j=0;j<n;j++)
    {
        i=n-j-1;
        r=sum1;
        while(r!=0)
        {
            if(r>=a[i])
            {
                r=r-a[i];
                br++;
            }
            else i--;  
        }
        if(br<brmin) brmin=br;
        br=0;
    }
    cout<<brmin<<"\n";
    return 0; 
}
