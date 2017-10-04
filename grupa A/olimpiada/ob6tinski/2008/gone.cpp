#include<bits/stdc++.h>
using namespace std;
int n,p;
int main(){
   cin>>n>>p;
   int t=1,c=0;
   do{
      t+=(p+1);
      if(t>n)t-=n;
      c++;
   }while(t!=1);
   double len=sqrt(pow((1-cos((p+1)*(2.0*M_PI/n))),2.0)+pow((sin((p+1)*(2.0*M_PI/n))),2.0));
   cout<<setiosflags(ios::fixed)<<setprecision(5)<<len*c<<"\n";
}
