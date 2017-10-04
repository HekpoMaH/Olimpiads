#include<iostream>
#include<algorithm>
using namespace std;
int a[4],b[4];
int main()
{
  cin>>a[0]>>a[1]>>a[2];
  cin>>b[0]>>b[1]>>b[2];
  sort(a,a+3);sort(b,b+3);
  //for(int i=0;i<3;i++)cout<<"a[i]="<<a[i]<<" b[i]="<<b[i]<<endl;
  if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]){cout<<3<<endl;return 0;}
  if(a[0]<=b[0]&&a[1]<=b[1]&&a[2]<=b[2]){cout<<1<<endl;return 0;}
  if(a[0]>=b[0]&&a[1]>=b[1]&&a[2]>=b[2]){cout<<2<<endl;return 0;}
  cout<<0<<endl;
  return 0;
}
