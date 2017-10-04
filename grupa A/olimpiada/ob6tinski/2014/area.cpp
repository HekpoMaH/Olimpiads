#include<bits/stdc++.h>
using namespace std;
double a,b;
int main(){
   cin>>a>>b;
   if(3.0*a<=b){
      cout<<"0.00"<<"\n";
      exit(0);
   }
   double p=3.0*a+b;
   p/=2.0;
   cout<<setiosflags(ios::fixed)<<setprecision(2)<<
      (p-a)*sqrt((p-a)*(p-b))<<"\n";
}
