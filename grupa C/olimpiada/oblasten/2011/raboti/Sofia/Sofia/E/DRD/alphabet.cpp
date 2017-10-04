#include<iostream>
using namespace std;
int main(){
long long bukvi,opiti,opit,dane,lose,pech;
char znak;
cin>>bukvi>>opiti;
for(opit=0,lose=1,dane=1,pech=0;opit<opiti;){
  cin>>znak;
  if(dane==1&&(znak==bukvi-1+'A'||znak==bukvi-1+'a')){lose=0;pech=opit+1;}
  if(znak=='.'){opit++;}else{dane=0;}
  if(znak=='.'&&pech==0){dane=1;}
}
if(lose==1){cout<<"lose"<<endl;}
else{cout<<"win "<<pech<<endl;}
return 0;
}
