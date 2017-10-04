#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
typedef long long lli;
#define pb push_back
#define mp make_pair
int k;
string sideofbus="+------------------------+";
int main(){
   int a[4][100];
   memset(a,0,sizeof(a));
   cin>>k;
   cout<<sideofbus<<"\n";
   int br=0,pos[100];
   memset(pos,0,sizeof(pos));
   for(int i=1;i<=k;i++){
      if(i==3)continue;
      pos[br]++;
      a[br][pos[br]]=1;
      br=(br+1)%3;
   }
   int cur=1;
   cout<<"|";
   for(int i=1;i<=11;i++){
      if(a[0][i]==1)cout<<"O";
      else cout<<"#";
      cout<<".";
   }
   cout<<"|D|)\n";
   cout<<"|";
   for(int i=1;i<=11;i++){
      if(a[1][i]==1)cout<<"O";
      else cout<<"#";
      cout<<".";
   }
   cout<<"|.|\n";
   if(k>=3)cout<<"|O";
   else cout<<"|#";
   cout<<".......................|\n";

   cout<<"|";
   for(int i=1;i<=11;i++){
      if(a[2][i]==1)cout<<"O";
      else cout<<"#";
      cout<<".";
   }
   cout<<"|.|)\n";
   cout<<sideofbus<<"\n";
}
