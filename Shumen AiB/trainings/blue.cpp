//informatics.mccme.ru - 112769
//moskovska otrikta olimpiada 2015
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
const int nmax=1e5+9;
const lli base=19;
string s;
lli used[nmax],l,n;
lli hsh[nmax],pw[nmax];
bool bad[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>l;
   cin>>s;
   memset(hsh,31,sizeof(hsh));
   n=s.size();
   hsh[0]=0;pw[0]=1;
   for(int i=0;i<n;i++){
      hsh[i+1]=hsh[i]*base+s[i]-'a';
      pw[i+1]=pw[i]*base;
   }
   for(int lenA=1;lenA<=l;++lenA){
      if(bad[lenA])continue;
      int start=lenA;
      lli ha=hsh[lenA];
      while(hsh[start+lenA]-hsh[start]*pw[lenA]==ha){
         start+=lenA;
         bad[start]=1;
      }
      if(start==n){
         cout<<1<<"\n";
         cout<<s.substr(0,lenA)<<"\n";
         exit(0);
      }
   }
   for(int lenA=1;lenA<=l;lenA++){
      if(bad[lenA])continue;
      int start=lenA;
      lli ha=hsh[lenA];
      while(hsh[start+lenA]-hsh[start]*pw[lenA]==ha&&start+lenA<=n){
         start+=lenA;
      }
      for(int lenB=1;lenB<=l;lenB++){
         int pos=start+lenB;
         lli hb=hsh[start+lenB]-hsh[start]*pw[lenB];
         while(used[pos]!=lenA){
            used[pos]=lenA;
            if(pos+lenA<=n&&hsh[pos+lenA]-hsh[pos]*pw[lenA]==ha){
               pos+=lenA;
               continue;
            }
            if(pos+lenB<=n&&hsh[pos+lenB]-hsh[pos]*pw[lenB]==hb){
               pos+=lenB;
               continue;
            }
            break;
         }
         if(pos==n){
            cout<<2<<"\n";
            cout<<s.substr(0,lenA)<<"\n";
            cout<<s.substr(start,lenB)<<"\n";
            exit(0);
         }
      }
   }
   cout<<3<<"\n";
   cout<<"a\n";
   cout<<"b\n";
   cout<<"c\n";
}
