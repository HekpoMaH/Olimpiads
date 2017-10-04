#include<iostream>
#include<string>
using namespace std;
string a;
long long k,sum,n;
double sr;
int main()
{
  cin>>a;
  cin>>n;
  k=a.size();
  for(int i=0;i<k;i++)sum+=a[i]-'0';
  //cout<<sum<<endl;
  do
  {

    if(a.size()<n)
    {
      sr=(double)sum/k;//cout<<sum<<" "<<k<<endl;cout<<"sr="<<sr<<" "<<(double)((int)sr+0.5)<<endl;
      if(sr<(double)((int)sr+0.5)){sr=(int)sr;}
      else {sr=(int)((int)sr+1);}
      a+=(char)(sr+'0');
      k=a.size();
      sum+=(int)sr;
    }if(a.size()>=n)cout<<a[n-1]<<endl;
    //cout<<k<<endl;
  }while(a.size()<n);
  return 0;
}
