#include<iostream>
using namespace std;
int main(){
long long gvod,mvod,kratno,kratemp,botilki,g1,m1;
cin>>gvod>>mvod;
for(g1=gvod,m1=mvod;g1!=m1;){
  if(g1>m1){g1-=m1;}
  else{m1-=g1;}
}
kratno=(gvod*mvod)/m1;kratemp=kratno;botilki=0;
while(botilki==0){
  if(kratno%(gvod+mvod)==0){botilki=(kratno/(gvod+mvod))*2;}
  else{kratno+=kratemp;}
}
cout<<botilki<<endl;
return 0;
}
