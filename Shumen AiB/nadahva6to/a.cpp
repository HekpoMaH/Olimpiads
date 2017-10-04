#include<bits/stdc++.h>
using namespace std;
int a,b;
int mn1,mn2;
int mx1,mx2;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>a>>b;
   mn1=50*(a-1)+1;mx1=50*a;
   mn2=70*(b-1)+1;mx2=70*b;
   if(mn1>mx2||mn2>mx1){
      cout<<-1<<"\n";
      return 0;
   }
   mn1=(mn1+ 59) / 60, mx1 = (mx1 + 59) / 60;
   mn2 = (mn2 + 59) / 60, mx2 = (mx2 + 59) / 60;
   for(int i=max(mn1,mn2);i<=min(mx1,mx2);i++)
      cout<<i<<" ";
   cout<<"\n";
}
