#include<iostream>
using namespace std;
int main(){
double a,pred;
int brloc=1,brglob=1;
cin>>a;
pred=a;
while(a!=0){
cin>>a;
if(pred<=a)brloc++;
if(brloc>brglob)brglob=brloc;
if(pred>a)brloc=1;
pred=a;}
cout<<brglob<<endl;
return 0;
}
