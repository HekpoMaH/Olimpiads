#include<iostream>
using namespace std;
int main()
{
  long long N,palind[10001],brpal1=0,brpal2=0,x,i,j,palindrom=1,ot,doo,del[2][5000],a=0,b=0;
  cin>>N;
  ot=1;
  for(x=1;x<=N;x++) {
    cin>>palind[x];
  }
  for(i=N;i>=ot;i--) {
     for(j=ot;j<=((i-ot+1)/2)+ot;j++) {
        if(palind[j]!=palind[i+ot-j]) {
           palindrom=0;
           break;
        }
     }
     if(palindrom==1) {
       brpal1++;
       del[1][b]=i;
       b++;
       ot=i+1;
       i=N;

     }
     palindrom=1;
  }
  if(ot==N) {
    brpal1++;
  }
  doo=N;
  for(i=1;i<=doo;i++) {
     for(j=doo;j>=((doo-i+1)/2)+i;j--) {
        if(palind[j]!=palind[i+doo-j]) {
           palindrom=0;
           break;
        }
     }
     if(palindrom==1) {
       del[2][a]=i+1;
       a++;
       brpal2++;
       doo=i-1;
       i=0;
     }
     palindrom=1;
  }
  if(brpal1>brpal2) {
    cout<<brpal2<<endl;
    if(brpal2>1) {
    for(i=1;i<a-1;i++) {
      cout<<del[2][i]<<" ";
    }
    cout<<del[2][a-1]<<endl;
    }
  }
  else {
    cout<<brpal1<<endl;
    if(brpal1>1) {
    for(i=0;i<b-1;i++) {
      cout<<del[1][i]<<" ";
    }
    cout<<del[1][b-1]<<endl;
    }
  }
  return 0;
}