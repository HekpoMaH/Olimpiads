#include<iostream>
using namespace std;
int n,a[130],s1,s2,l,r,s,br,p;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  l=0;r=n-1;br=1;
  while(l<=r)
  {
    if(a[l+1]>a[r-1]){s=a[r];p=1;}
    if(a[l+1]<a[r-1]){s=a[l];p=0;}
    if(a[l+1]==a[r-1])
    {
      if(a[l]>a[r]){s=a[l];p=0;}
      else{s=a[r];p=1;}
    }
    if(br%2==1)s1+=s;
    else s2+=s;
    if(p==0)l++;
    else r--;
    br++;
  }
  cout<<s1<<" "<<s2<<endl;
  return 0;
}
