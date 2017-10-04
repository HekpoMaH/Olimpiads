#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
lli s1,s2;
lli x,y;
lli n;
int main(){
   cin>>n;
   while(1){
      if(s2-s1<n){
         y++;
         s2+=y;
      }
      else if(s2-s1>n){
         x++;
         s1+=x;
      }
      else{
         cout<<y<<" "<<x<<"\n";
         exit(0);
      }
   }
}
