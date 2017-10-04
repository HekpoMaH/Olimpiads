#include<iostream>
int N,M,i,j,l,a[2000],b[1000000],c[1000000];
using namespace std;
int main()
{
    cin>>N>>M;
    for (i=0;i<M;i++){
      cin>>b[i]>>c[i];
    }
    for(i=0;i<M;i++) {
      for(j=0;j<M;j++) {
        if (b[i]==b[j]) a[i]++;
      }
    }
    for(i=0;i<M;i++) {
      if (a[i]>=l) l=a[i];
    }
    cout<<l<<"\n";
return 0;
} 
