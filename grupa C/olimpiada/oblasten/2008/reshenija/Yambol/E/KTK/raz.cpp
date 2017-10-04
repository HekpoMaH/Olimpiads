#include<iostream>
using namespace std;
int main()
{
long long p=0,N,pr=0,r=0,minr=0;
long long v=0;
cin>>N;
do
{
p++;
v=N/p;
if(v>p)
{r=v-p;}
else
{r=p-v;}
if(minr>r)
minr=r;
}
while(v<1);
if(v>p)
cout<<p<<" "<<v;
else
cout<<v<<" "<<p;
    return 0;
}
