#include<iostream>
using namespace std;
int main()
{
    int v,n,k,i;
    char a;
    cin>>v;
    cin>>k;
    cin>>n;
    for(i=1;i<=n;i++)
{
    cin>>a;
    if(a=='+') v=v+k;
    if(a=='-') v=v-k;
}
cout<<v<<endl;
return 0;
}
       
