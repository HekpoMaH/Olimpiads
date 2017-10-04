#include<iostream>
using namespace std;
int main(){
long long cifr,chis,kap,rik,broj,brbr,pati,ch2,chisnew,brst,br;
cin>>broj;
for(brbr=0,pati=0;brbr<broj;brbr++){
  cin>>chis;
  for(cifr=0,ch2=chis;ch2!=0;ch2/=10,cifr++){}
  chisnew=chis*chis;
  for(brst=1,br=0;br<cifr;br++){brst*=10;}
  rik=chisnew%brst;
  kap=(chisnew-rik)/brst;
  if(kap+rik==chis){pati++;}
}
cout<<pati<<endl;
return 0;
}
