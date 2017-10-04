#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli xh,yh,xu,yu;// ui q
lli a,b,c;
lli br;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>xh>>yh>>xu>>yu;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a>>b>>c;
      lli s1=a*xh+b*yh+c;
      lli s2=a*xu+b*yu+c;
      if(s1<0&&s2>0)br++;
      else if(s1>0&&s2<0)br++;
   }
   cout<<br<<"\n";
}
