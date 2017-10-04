#include<bits/stdc++.h>
using namespace std;
struct trie{
   int fl;
   int nxt[26];
   int bestr,bestl;
   string dw;
};
//bestr-> kolko stavat
//bestl-> best len
const int nmax=2*(1e5)+9;
string s[nmax];
int curr=1;
trie tr[nmax];
int n,m;
void mytol(char &in){
if(in<='Z' && in>='A')
    in=in-('Z'-'z');
}

void add(string a,string b){
   int nor=0;

   int len=b.size();

   for(int i=0;i<len;i++){
      mytol(b[i]);
      if(b[i]=='r'){
         nor++;
      }
   }
   int trc=1;
   int br=0;
   for(int i=0;i<a.size();i++){
      mytol(a[i]);
      if(tr[trc].nxt[a[i]-'a']==0){
         tr[trc].nxt[a[i]-'a']=++curr;
         tr[curr].bestr=tr[curr].bestl=nmax*2;
         //cout<<"node "<<curr<<" was made with bestr = "<<bestr<<"\n";
      }
      trc=tr[trc].nxt[a[i]-'a'];
      if(a[i]=='r'){
         br++;
      }
   }
   tr[trc].fl=1;
   //cout<<"nor="<<nor<<" "<<tr[trc].bestr<<"\n";
   if(nor<tr[trc].bestr){
      //cout<<"EEE\n";
      tr[trc].bestr=nor;
      tr[trc].bestl=len;
      tr[trc].dw=b;
   }
   else if(nor==tr[trc].bestr){
      tr[trc].bestl=len;
      tr[trc].dw=b;
   }
}
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>s[i];
   }
   cin>>m;
   for(int j=1;j<=m;j++){
      string a,b;
      cin>>a>>b;
      add(a,b);
   }
   
}
void parse(int in,int cur){
   for(int i=0;i<26;i++){
      if(tr[cur].nxt[i]!=0){
         for(int j=1;j<=in;j++)cout<<" ";
         if(tr[tr[cur].nxt[i]].fl)cout<<"*";
         cout<<(char)('a'+i)<<"( "<<tr[cur].nxt[i]-1<<" , "
            <<tr[tr[cur].nxt[i]].bestr<<" )"<<"\n";
         parse(in+1,tr[cur].nxt[i]);
      }
   }
}
void solve(){
   int len=0,brr=0;
   for(int i=1;i<=n;i++){
      int crh=0;
      int pl=1;
      int trc=1;
      int adda=0,addb=0;
      string curw="";
      for(int j=0;j<s[i].size();j++){
         mytol(s[i][j]);
         if(tr[trc].nxt[s[i][j]-'a']==0){
            pl=0;
         }
         if(tr[trc].nxt[s[i][j]-'a']!=0)trc=tr[trc].nxt[s[i][j]-'a'];
         if(s[i][j]=='r')crh++;
      }
      cout<<i<<" "<<pl<<" "<<s[i]<<" "<<s[i].size()<<"\n";
      if(pl==0||tr[trc].fl==0){
         brr+=crh;
         len+=s[i].size();
         adda=crh;addb=len;
         continue;
      }
      cout<<crh<<" "<<tr[trc].bestr<<" "<<tr[trc].bestl<<" "<<s[i].size();
      if(tr[trc].fl==1&&tr[trc].bestr<crh){
         //cout<<"E1\n";
         brr+=tr[trc].bestr;
         len+=tr[trc].bestl;
         adda=tr[trc].bestr;
         addb=tr[trc].bestl;
      }
      else if(tr[trc].fl==1&&tr[trc].bestr==crh&&tr[trc].bestl<s[i].size()){
         //cout<<"E2\n";
         brr+=tr[trc].bestr;
         len+=tr[trc].bestl;
         adda=tr[trc].bestr;
         addb=tr[trc].bestl;
      }
      else if(s[i]!=tr[trc].dw){
         //cout<<"E3\n";
         brr+=crh;
         len+=s[i].size();
      }cout<<" adda="<<adda<<" addb="<<addb<<"\n";
      if(adda!=0||addb!=0){
         //cout<<"HErE\n";aaaa
         brr-=adda;
         len-=addb;
         s[i]=tr[trc].dw;
         i=1;
      }
      
   }
   cout<<brr<<" "<<len<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   //parse(0,1);
   solve();
}

