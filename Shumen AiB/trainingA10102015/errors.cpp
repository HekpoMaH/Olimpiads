#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxLen=30;
const int nmax=220009;
string wordDic[nmax];
string word[nmax];
int n,m;
map<string,pair<vector<int>,vector<int> > > poss;
set<int> possidx[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>word[i];
   }
   for(int i=1;i<=m;i++){
      cin>>wordDic[i];
   }
   for(int i=1;i<=m;i++){
      poss[wordDic[i]].fi.pb(i);
      for(int j=0;j<wordDic[i].size();j++){
         if(j==wordDic[i].size()-1||wordDic[i][j]!=wordDic[i][j+1]){
            string curr=wordDic[i];
            curr.erase(j,1);
            //cout<<curr<<"\n";
            poss[curr].fi.pb(i);
         }
      }
   }
   for(int i=1;i<=n;i++){
      poss[word[i]].se.pb(i);
      for(int j=0;j<word[i].size();j++){
         string curr=word[i];
         curr.erase(j,1);
         //cout<<curr<<"\n";
         poss[curr].se.pb(i);
      }
   }
   map<string,pair<vector<int>,vector<int> > >::iterator it;
   for(it=poss.begin();it!=poss.end();it++){
      //cout<<it->first<<" "<<(it->second).first.size()<<" "<<(it->second).second.size()<<"\n";
      for(int i=0;i<(it->second).fi.size();i++){
         for(int j=0;j<(it->second).se.size();j++){
            possidx[(it->second).fi[i]].insert((it->second).se[j]);
         }
      }
   }
   for(int i=1;i<=m;i++){
      cout<<wordDic[i]<<" "<<possidx[i].size();
      if(possidx[i].size()==1){
         cout<<" "<<word[*possidx[i].begin()];
      }
      cout<<"\n";
   }
}
