#include<iostream>
using namespace std;
int main()
{
  float a,a1;
int br=1,maxbr=0;
cin>>a>>a1;
while (a1!=0)
{
if(a<=a1)
{br++;
}
else
{
if(maxbr<br)maxbr=br;
br=1;
}
a=a1;
cin>>a1;
}
cout<<maxbr<<endl;
return 0;
}