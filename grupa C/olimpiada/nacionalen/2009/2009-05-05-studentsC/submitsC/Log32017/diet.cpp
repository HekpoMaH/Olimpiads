/*
TASK: diet
LANG: C++
*/
#include<iostream>
using namespace std;
long long br,s,n,m,k,x;
int main()
 {
 cin>>n>>m>>k;
 s=(n*10+m*20+k*30)/60;
 if(n>s) {if(k<s) {x=n-s;n=s;n+=x%3;x/=3;k+=x;}
          if(m<s) {x=n-s;n=s;n+=x%2;x/=2;m+=x;}}
 if(k>s) {if(m<s) {k+=s-m;br+=s-m;n+=s-m;m=s;}
          if(n<s) {x=s-n;if(x%3==1) br--;if(x%3!=0) x+=2;x/=3;br+=2*x;k-=x;n=s;}}
 if(m>s) {if(k<s) {m=m+k-s;n=n+k-s;k=s;}
          if(n<s) {x=s-n;if(x%2!=0) x++;x/=2;br+=x;m-=x;x=s;}}
 cout<<s<<" "<<br<<endl;
 //system("PAUSE");
 return 0;
 }
