#include<iostream>
#include<string>
using namespace std;
string a;
int n,k,h,t,z,x,v,b[400],c[400],br,br2=-1;
int main()
{
  getline(cin,a,'@');
  n=a.size();
  //cout<<a<<endl;
  for(int i=0;i<=n;i++)
  {
    if(a[i]>='0'&&a[i]<='9'){br2++;c[br2]=a[i]-'0';}
    if(!(a[i]>='0'&&a[i]<='9')||(i==n))
    {

      if(br>br2)t=br;
      else t=br2;
      k=br;
      br=t;
      while(t>=0)
      {
        if(k>=0)z=b[k];
        else z=0;
        if(br2>=0)x=c[br2];
        else x=0;
        //cout<<x;
        v+=z+x;
        b[t]=v%10;
        v/=10;
        br2--;k--;t--;
      }
      br2=-1;
    }
  }
  for(int i=0;i<=br;i++)cout<<b[i];
  cout<<endl;
  return 0;
}
