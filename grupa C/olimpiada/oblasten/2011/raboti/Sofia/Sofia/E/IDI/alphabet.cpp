#include<iostream>
using namespace std;
char filmi,pom,bukva;
long long nomerbukva,brreda,i,j[20];
bool ima;
int main(){
ima=false;
cin>>nomerbukva>>brreda;
for(i=0;i<20;i++)
{
   j[i]=0;
}
for(i=0;i<brreda;i++)
{
    cin>>filmi;
    if(filmi=='a'+nomerbukva-1||filmi=='A'+nomerbukva-1)
    {
        ima=true;
        j[i]=i+1;
    }

  while(filmi!='.')
  {
    cin>>filmi;
  }
}
if(ima==false)
{
  cout<<"lose";
}
else
{
  cout<<"win"<<" ";
  for(i=0;i<20;i++)
  {
    if(j[i]!=0)
    {
      cout<<j[i];
    }
  }
}
cout<<endl;
return 0;
}
