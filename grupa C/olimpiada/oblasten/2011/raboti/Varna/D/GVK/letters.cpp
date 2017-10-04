#include<iostream>
using namespace std;
int main(){
int N,i,j,br=0,br1=0;
char a;
cin>>N;
cin>>a;
string b[N][4],c;

for(i=0;i<N;i++)
for(j=0;j<4;j++)
cin>>b[i][j];

for(i=0;i<N;i++){
c=b[i][0];
if(c[0]==a||c[0]==(char)(a-32)||c[0]==(char)(a+32))br++;}
cout<<br<<" ";
br=0;

for(i=0;i<N;i++){
c=b[i][1];
for(j=0;j<c.size();j++)
if(c[j]==a||c[j]==(char)(a+32)||c[j]==(char)(a-32)){br++;break;}}
cout<<br<<" ";
br=0;

for(i=0;i<N;i++){
c=b[i][2];
for(j=0;j<c.size();j++)
if(c[j]==a||c[j]==(char)(a+32)||c[j]==(char)(a-32))br1++;
if(br1>=2)br++;
br1=0;}
cout<<br<<" ";
br=0;

for(i=0;i<N;i++){
c=b[i][3];
if(c[c.size()-1]==a||c[c.size()-1]==(char)(a-32)||c[c.size()-1]==(char)(a+32))br++;}
cout<<br<<endl;

return 0;
}
