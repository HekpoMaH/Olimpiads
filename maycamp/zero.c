#include<iostream>
using namespace std;
long long a[50000];
long int brd,brp,a2,j=-1;
int main()
{
  long long int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    a[i]=i+1;
    a2=a[i];
    while(a2%2==0){a2/=2;brd++;}
    while(a2%5==0){a2/=5;brp++;}
    //cout<<a[i]<<endl;
  }
  long int nuli=min(brd,brp);brd=min(brd,brp);brp=brd;
  //cout<<brp<<endl;
  //a[1]=1;a[4]=1;
  while(brd>0||brp>0)
  {
    j++;
    while(a[j]%2==0&&brd>0){a[j]/=2;brd--;}
    while(a[j]%5==0&&brp>0){a[j]/=5;brp--;}
    //cout<<"brp="<<brp<<endl;
  }
  a2=a[1];
  //cout<<a2<<endl;
  for(int i=1;i<n;i++)
  {
    a2*=a[i];
    a2%=10;
    //cout<<a[i]<<endl;
  }
  cout<<a2<<" "<<nuli<<endl;
  return 0;
}

