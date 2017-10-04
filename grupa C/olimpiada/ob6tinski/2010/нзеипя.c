#include<iostream>
using namespace std;
int n=5;
int k=3;
int a[]={1,2,3,4,5};
int used[10];
int m[10];
void perm(int s)
{
  if(s>=n)
  {
    for(int i=0;i<n;i++)
    {
      cout<<m[i]<<" ";
    }
    cout<<endl;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      if(used[i]==0)
      {
        m[s]=a[i];
        cout<<"a["<<i<<"]="<<a[i]<<" m["<<s<<"]="<<m[s]<<endl;
        used[i]=1;
        cout<<"used["<<i<<"]="<<used[i]<<endl;
        perm(s+1);
        used[i]=0;
      }
    }
  }
}
int main()
{
  perm(0);
  return 0;
}
