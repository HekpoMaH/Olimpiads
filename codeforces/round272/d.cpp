#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long lli;
int n,k;
set<int> fre;

int x[100009][9],cr=0;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   cout<<(6*(n-1)+5)*k<<"\n";
   for(int i=0;i<n;i++){
      cout<<(i*6+1)*k<<" "<<(6*i+2)*k<<" "<<(6*i+3)*k<<" "<<(6*i+5)*k<<"\n";
   }
}
