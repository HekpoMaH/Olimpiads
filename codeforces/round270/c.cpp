#include<bits/stdc++.h>
using namespace std;
struct person{
   string h1,h2;
};
const int nmax=1e5+9;
int p[nmax];
person handles[nmax];
int n;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>handles[i].h1>>handles[i].h2;
   }
   for(int i=1;i<=n;i++){
      cin>>p[i];
   }
}
string lh;
//last handle
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   if(handles[p[1]].h1<handles[p[1]].h2)lh=handles[p[1]].h1;
   else lh=handles[p[1]].h2;
   for(int i=2;i<=n;i++){
      bool fl=false;
      if(handles[p[i]].h1<handles[p[i]].h2){
         if(handles[p[i]].h1>lh){
            lh=handles[p[i]].h1;
            fl=true;
            continue;
         }
         if(handles[p[i]].h2>lh){
            lh=handles[p[i]].h2;
            fl=true;
            continue;
         }
      }
      else{
         if(handles[p[i]].h2>lh){
            lh=handles[p[i]].h2;
            fl=true;
            continue;
         }
         if(handles[p[i]].h1>lh){
            lh=handles[p[i]].h1;
            fl=true;
            continue;
         }
      }
      if(fl==false){
         cout<<"NO\n";
         exit(0);
      }
   }
   cout<<"YES\n";
}
