#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
   return a>0 ? gcd(b%a,a) : b;
}
int phi(int x){
   int res=x;
   for(int i=2;i*i<=x;i++){
      if(x%i==0){
         while(x%i==0)x/=i;
         res-=res/i;
      }
   }
   if(x>1)res-=res/x;
   return res;
}
int fastpow(int x,int st,int m){
   int p=x,res=1;
   while(st!=0){
      if(st&1)
         res*=p,res%=m;
      st>>=1;
      p*=p;
      p%=m;
   }
   return res;
}
int main(){
   int a,b,n;
   cin>>a>>b>>n;
   int nod=gcd(a,n);
   if(b%nod!=0){
      cout<<"NO SOLUTION\n";
      return 0;
   }
   int ap,bp,np;
   ap=a/nod;
   bp=b/nod;
   np=n/nod;
   int fi=phi(np);
   int rev_a=fastpow(ap,fi-1,np);
   int xp=bp*rev_a;
   cout<<"ALL SOLUTIONS ARE:\n";
   for(int i=0;i<nod;i++){
      int x=(xp+i*np)%n;
      cout<<x<<" ";
   }
   cout<<"\n";
}
