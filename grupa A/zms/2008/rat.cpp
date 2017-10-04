#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n;
lli b(lli pos){
   if(pos==1||pos==2)return 1;
   if(pos%2==1)return b(pos/2)+b(pos/2+1);
   return b(pos/2);
}
int main(){
   cin>>n;
   n++;
   cout<<b(n)<<" "<<b(n+1)<<"\n";
}
