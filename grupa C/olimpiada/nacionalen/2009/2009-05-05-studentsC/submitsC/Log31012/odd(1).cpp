/*
task:odd
lang:C++
*/
#include<iostream>
#include<vector>
using namespace std;
unsigned long long n,t;    
unsigned long long c[1000001];
int main()
{
    cin>>n;
    for(unsigned long long i=0;i<n;i++){
    scanf("%d",&c[i]);
                         }    
    sort(c,c+n);
    unsigned long long m=0;
    for(long long i=0;i<n-1;i=i+2)
    {
             if(c[i]!=c[i+1]){m=c[i];break;}
    }
    if(m==0)m=c[n-1];
    cout<<m<<endl;
    return 0;
}
