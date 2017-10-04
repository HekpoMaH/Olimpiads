#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int used[nmax];
int a,b,medals,cups;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   for(int i=1;i<=3;i++){
      cin>>b;
      cups+=b;
   }
   for(int i=1;i<=3;i++){
      cin>>a;
      medals+=a;
   }
   int shelves=medals/10+min(1,medals%10)+cups/5+min(1,cups%5);
   //cout<<shelves<<" "<<cups<<" "<<medals<<endl;
   cin>>n;
   if(shelves>n)cout<<"NO\n";
   else cout<<"YES\n";
   
}
