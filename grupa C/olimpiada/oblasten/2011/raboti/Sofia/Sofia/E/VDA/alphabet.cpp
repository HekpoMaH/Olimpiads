#include<iostream>
using namespace std;
int main ()
{
int n,m,i,j;
cin>>n;
for(n=1;1<n<26;i++)
for(m=1;1<m<20;j++)
{
    if(m<20&&n<26)
    cout<<n<<m<<endl;
}
cout<<'.'<<endl;
return 0;
}
