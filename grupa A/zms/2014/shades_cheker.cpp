#include<bits/stdc++.h>
using namespace std;
int n,m;
int q;
string s[509];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>s[i];
   }
   cin>>q;
   ifstream fin("shades.out");
   for(int i=1;i<=q;i++){
      cout<<"TEST "<<i<<"\n";
      int stx,sty,ex,ey;
      int balance;
      cin>>stx>>sty>>ex>>ey;
      stx--;sty--;ex--;ey--;
      int len;
      string ss;
      fin>>len;
      if(len==-1)continue;
      else fin>>ss;
      assert(len==ss.size()+1);
      balance=s[stx][sty]=='W' ? +1 : -1;
      cout<<ss<<"\n";
      cout<<balance<<" ";
      cout<<stx<<" "<<sty<<" "<<s[stx][sty]<<"\n";
      for(int j=0;j<ss.size();j++){
         if(ss[j]=='U'){
            stx--;
         }
         else if(ss[j]=='D'){
            stx++;
         }
         else if(ss[j]=='L'){
            sty--;
         }
         else if(ss[j]=='R'){
            sty++;
         }
         balance+=s[stx][sty]=='W' ? +1 : -1;
      cout<<balance<<" ";
      cout<<stx<<" "<<sty<<" "<<s[stx][sty]<<"\n";
      }
      cout<<"\n";
      if(balance!=0)cout<<i<<"\n";
      if(!(stx==ex&&sty==ey))cout<<i<<"\n";
      assert(stx==ex&&sty==ey);
      assert(balance==0);
   }
}
