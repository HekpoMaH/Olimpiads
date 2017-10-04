#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long lli;
int n,m;
int main(){
   cin>>n>>m;
   int steps=n/2;
   if(n%2==1)steps++;
   while(steps%m!=0)steps++;
   if(steps<=n)cout<<steps<<"\n";
   else cout<<-1<<"\n";
}
