#include<iostream>
using namespace std;
void solve(){
   int m;
   string s;
   string hr[250];int br=1;
   cin>>m;
   cin>>s;
   for(int i=0;i<s.size();i++){
      if(s[i]>='0'&&s[i]<='9'){
         hr[br]+=s[i];
         if(hr[br].size()==4){
            br++;
         }
      }
   }
   for(int i=1;i<=br;i++){
      if(hr[i].size()!=4)continue;
      int ch,mi;
      ch=hr[i][0]-'0';ch*=10;ch+=hr[i][1]-'0';
      mi=hr[i][2]-'0';mi*=10;mi+=hr[i][3]-'0';
      if(ch>23){
         continue;
      }
      if(mi>59){
         continue;
      }
      mi+=m;
      ch+=mi/60;
      ch%=24;
      mi=mi%60;
      if(ch<10)cout<<0;
      cout<<ch<<":";
      if(mi<10)cout<<0;cout<<mi<<"\n";
      return;
   }
   cout<<"NO\n";
}
int main(){
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
