#include<iostream>
using namespace std;
int main ()
{int N,i,a,sb=0,min=21;
cin>>N;
if(N<=7)
{for(i=1;i<=N;i++)
{cin>>a;
if(min>a)
min=a;
sb=sb+a;
}}
sb=sb-(min-1);
cout<<sb<<endl;

return 0;
}
