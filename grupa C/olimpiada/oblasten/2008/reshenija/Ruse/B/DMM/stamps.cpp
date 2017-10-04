#include<iostream>
using namespace std;
int main ()
{
    int s,n;
    cin>>s>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    int s1=a[n-1];
    int br=1;
    while(s1<s)
    {s1=s1+1;br++;}
    cout<<br<<endl;
    return 0;
}
