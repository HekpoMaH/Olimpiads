#include<iostream>
using namespace std;
long long m,n,i,j,minbot,goliamo,malko,nod,nok;
int main(){
cin>>m>>n;
nod=1;
if(m>n)
{
  goliamo=m;
  malko=n;
}
else
{
  malko=m;
  goliamo=n;
}
for(i=2;i<malko;i++)
{
  if(m%i==0&&n%i==0)
  {
      nod=nod*i;
  }
}
nok=(m/nod)*(n/nod)*nod;
for(i=2;i>0;i++)
{
  if((m+n)*i%nok==0)
  {
      minbot=i*2;
      i=-1;
  }
}
cout<<minbot<<endl;
return 0;
}
