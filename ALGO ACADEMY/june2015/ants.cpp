#include<bits/stdc++.h>
using namespace std;
int n;
double x,mx,y,my;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x>>y;
      mx+=x;
      my+=y;
   }
   cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)(mx/(double)n)<<" "<<(double)(my/(double)n)<<"\n";
}
