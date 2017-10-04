//Diofantovo uravnenie: namirane na edinstveno re6enie
#include<bits/stdc++.h>
using namespace std;
int nod(int a,int b,int &x,int &y){
   if(a==0){
      x=0,y=1;
      return b;
   }
   int x1,y1;
   int d=nod(b%a,a,x1,y1);
   x=y1-b/a*x1;
   y=x1;
   return d;
}
bool findsol(int a,int b,int c,int &x0,int &y0,int &g){
   g=nod(abs(a),abs(b),x0,y0);
   if(c%g!=0)return false;
   x0*=c/g;
   y0*=c/g;
   if(a<0)x0*=-1;
   if(b<0)y0*=-1;
   return true;
}
int main(){
   int a,b,c;
   cin>>a>>b>>c;
   int x,y,gcd;
   if(findsol(a,b,c,x,y,gcd)==true){
      cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<c<<"\n";
   }
   else cout<<"NO SOLUTION!\n";
}
