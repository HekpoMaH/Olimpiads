#include<iostream>
using namespace std;
int a[100],b[100],n,m,st[24],m2,ost,br1,br2,brd,suma,sumb,sump;
int main()
{
  cin>>n>>m;
  st[0]=1;
  for(int i=1;i<n;i++)st[i]=3*st[i-1];
  m2=m;
  ost=m2%3;
  do
  {

    //cout<<m2<<" "<<ost<<endl;
    if(ost==2)
    {
      a[br1]=st[brd];
      br1++;
      m2++;//cout<<st[brd]<<endl;
    }
    if(ost==1)
    {
      b[br2]=st[brd];
      br2++;m2--;
    }
    m2/=3; ost=m2%3;    //cout<<m2<<" "<<ost<<endl;
    brd++;
  }while(m2>0);
  //cout<<m<<" ";
  sort(a,a+br1);sort(b,b+br2);
  for(int i=0;i<=br1;i++){suma+=a[i];}
  for(int i=0;i<=br2;i++){sumb+=b[i];}
  suma+=m;
  sump=abs(suma-sumb);//cout<<suma<<" "<<sumb<<endl;
  if(suma<sumb){a[br1]=sump;br1++;}
  if(suma>sumb){b[br2]=sump;br2++;}
  cout<<m<<" ";
  for(int i=0;i<br1;i++){cout<<a[i]<<" ";}
  cout<<endl;
  for(int i=0;i<br2;i++){cout<<b[i]<<" ";}
  cout<<endl;
  return 0;
}
