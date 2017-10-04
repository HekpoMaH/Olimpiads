#include<iostream>
using namespace std;
int main(){
double tek,pred;
long long tekm=1,m=0;
cin>>pred;
while(cin>>tek){
if(pred<=tek&&tek){
  ++tekm;
}else{
  if(tekm>m){
   m=tekm;
  }
 tekm=1;
}
pred=tek;
if(tek==0){break;}
}
cout<<m<<endl;
return 0;
}