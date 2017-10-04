#include<iostream>
using namespace std;
double a,b,c,d;
long long i,br,fl[10001],br1;
int main () {
   long long max;
   max=1;
   b=0;
   d=0;
while(1) {
 cin>>a;
 br1++;
 if(!a==0) {
 d=c;
 c=b;
 b=a;


  if(c<=b) {
   br++;
  }

  else{
   if(d>c) {
    br++;
   }
   if(max<br) {
    max=br;
    br=0;
   }
 }
 }
 else{
   break;
 }
}
   if(max<br && br1-1!=br) {
    max=br+1;
    br=1;
   }
   if(br1-1==br) {
    max=br;
   }

cout<<max<<endl;
return 0;
}