#include<iostream>
using namespace std;
int main()
{  int  N,razl=100001,am=0,bm,zap1,zap2;
cin>>N;
for(int i=0;i<N;i++){
am=am+1;       
if(N%am==0){ 
 bm=N/am;
          
if(am>bm){
if(am-bm<razl) {
razl=am-bm;
zap1=bm-1;
zap2=am;}}

else if(bm-am<razl){
razl=bm-am;
zap1=am;
zap2=bm;}}}                                
 cout<<zap1<<' '<<zap2<<endl;     
    return 0;
    }
