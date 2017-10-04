#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> filters;
unordered_map<string,int>::iterator it;
#define pb push_back
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,k,subtask;
   cin>>n>>subtask;
   string s;
   for(int i=1;i<=n;i++){
      cin>>s;
      filters[s]++;
   }
   cin>>k;
   vector<string> hosts;
   vector<string> paths;
   for(int i=1;i<=k;i++){
      cin>>s;
      string host;
      string path;
      int index=s.find_first_of('/');
      if(index>=0){
         host=s.substr(0,index);
         path=s.substr(index);
         //cout<<host<<" "<<path<<"\n";
      }
      else{
         host=s;
         path="";
      }
      hosts.clear();
      hosts.pb(host);
      host="*."+host;
      index=host.find_first_of('.');
      while(index>=0){
         hosts.pb("*"+host.substr(index));
         index=host.find_first_of('.',index+1);
      }
      paths.clear();
      paths.pb(path);
      path=path+"/*";
      index=path.find_last_of('/');
      while(index>=0){
         paths.pb(path.substr(0,index+1)+"*");
         if(!index)break;
         index=path.find_last_of('/',index-1);
      }
      //for(int j=0;j<hosts.size();j++){
      //   cout<<hosts[j]<<" ";
      //}
      //cout<<"\n";
      //for(int j=0;j<paths.size();j++){
      //   cout<<paths[j]<<" ";
      //}
      int ans=0;
      for(int j=0;j<hosts.size();j++){
         for(int k=0;k<paths.size();k++){
            it=filters.find(hosts[j]+paths[k]);
            if(it!=filters.end()){
               ans+=it->second;
            }
         }
      }
      //cout<<"\n";
      cout<<ans<<"\n";
      //cout<<"\n";
      //cout<<"\n";
   }
}
