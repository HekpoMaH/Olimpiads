#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
const int nmax=1e5+9;
const int offset=1e5+9;
#define mp make_pair
#define pb push_back
int n;
string a[nmax];
int mnl=65;
int last;
string curpref;
string bina(int num){
   string re="";
   while(num!=0){
      re+=num%2+'0';
      num/=2;
   }
   reverse(re.begin(),re.end());
   return re;
}
set<int> s;
int getf(string given,int posi){
   //cerr<<given<<"->";
   int br=0;
   int fl=0;
   for(int i=0;i<min(posi+1,(int)given.size());i++){
      if(given[i]!=curpref[i]){
         fl=i;
         break;
      }
   }
   //cout<<"FL IS "<<fl<<"\n";
   while((int)given.size()>fl&&fl!=0){
      given.pop_back();
      br++;
   }
   //cout<<"GIVEN IS "<<given<<"\n";
   while(given.size()<curpref.size()){
      given+='0';
      br++;
   }
   while(given.size()>curpref.size()){
      given.pop_back();
      br++;
   }
   //cerr<<given<<","<<curpref<<" "<<br<<"\n";
   //cout.flush();
   //assert(given==curpref);
   return br;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      a[i]=bina(x);
      mnl=min(mnl,(int)a[i].size());
   }
   for(int i=0;i<=mnl;i++){
      s.clear();
      for(int j=1;j<=n;j++){
         int x=0;
         for(int k=0;k<i;k++){
            x=x*2+a[j][k];
         }
         s.insert(x);
      }
      if(s.size()>1)break;
      last=i;
   }
   //cerr<<last<<"\n";
   for(int i=0;i<last;i++)curpref+=a[1][i];
   //cerr<<curpref<<"\n";
   int ans=999999;
   for(int i=0;i<19;i++){
      int curs=0;
      for(int j=1;j<=n;j++){
         curs+=getf(a[j],i);
      }
      ans=min(ans,curs);
      curpref+='0';
      //cerr<<curpref<<" "<<curs<<"\n";
   }
   cout<<ans<<"\n";
}
