#include<iostream>
#include<string>
using namespace std;
string a;
long long c,p,mx,n,k,st,c2,st2;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    p=a[a.size()-2]-'0';
    //cout<<a[a.size()-4]<<endl;
    k=a.size()-3;c=0;
    for(int d=0;d<k;d++)
    {
      st=1;//cout<<a[d]-'0'<<endl;
      for(int j=0;j<k-d-1;j++)
      {
        st*=p;//cout<<st<<endl;
      }
      c=c+(a[d]-'0')*st;//cout<<"c="<<c<<"cif"<<a[d]-'0'<<" "<<st<<endl;
    }
    if(c>mx)mx=c;
  }
  cout<<mx<<endl;
  return 0;
}
