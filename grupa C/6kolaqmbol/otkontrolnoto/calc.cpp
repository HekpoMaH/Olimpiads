#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
long long n,h[100005],a,b,c,s;
bool cmp(long long a,long long b)
{
  if(a>b)return true;
  return false;
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>h[i];
  }
  make_heap(h,h+n,cmp);
  long long n2=n;
  while(n2>=0)
  {
    pop_heap(h,h+n2,cmp);//cout<<a<<endl;
    a=h[n2-1];
    n2--;
    if(n2==-1)break;
    //cout<<n2<<endl;
    pop_heap(h,h+n2,cmp);
    b=h[n2-1];
    n2--;if(n2==-1)break;
    //cout<<n2<<endl;
    c=a+b;//cout<<a<<" "<<b<<endl;
    s+=c;
    h[n2]=c;
    //cout<<s<<endl;
    push_heap(h,h+n2+1,cmp);
    n2++;
  }
  cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)s/20<<endl;
  return 0;
}
