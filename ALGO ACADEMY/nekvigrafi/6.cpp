#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<int> after[11];
set<long long> ans;
set<int> sts;
int used[11];
long long asnum(string ss){
   long long re=0;
   for(int i=0;i<(int)ss.size();i++){
      re=re*10LL+(long long)(ss[i]-'0');
   }
   return re;
}
void go(string num){
   ans.insert(asnum(num));
   int lnum=num[num.size()-1]-'0';
   used[lnum]=1;
   for(int i=0;i<(int)after[lnum].size();i++){
      if(used[after[lnum][i]]==0){
         go(num+(char)(after[lnum][i]+'0'));
         used[after[lnum][i]]=0;
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      string s;
      cin>>s;
      for(int j=0;j<(int)s.size()-1;j++){
         after[s[j]-'0'].pb(s[j+1]-'0');
         sts.insert(s[j]-'0');
      }
   }
   for(int i=0;i<=9;i++){
      cout<<i<<"-> ";
      for(int j=0;j<after[i].size();j++)cout<<after[i][j]<<" ";
      cout<<"\n";
   }
   for(set<int>::iterator it=sts.begin();it!=sts.end();it++){
      string starter;
      starter+=*it+'0';
      go(starter);
      used[*it]=0;
   }
   for(set<long long>::iterator it=ans.begin();it!=ans.end();it++){
      cout<<*it<<"\n";
   }
}
