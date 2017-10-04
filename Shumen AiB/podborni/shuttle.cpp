#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
const lli base[9]={101,47,53,97};
const lli mod[9]={(int)1e7};
const int nmax=2009;
lli hashgore[nmax][nmax];
lli hashdolu[nmax][nmax];
lli basep[nmax*nmax];
char s[nmax][nmax];
string srev[nmax];
lli rows,cols;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>rows>>cols;
   for(lli i=1;i<=rows;i++){
      for(lli j=1;j<=cols;j++){
         cin>>s[i][j];
      }
   }
   basep[0]=1;
   for(lli i=1;i<=nmax*nmax-10;i++){
      basep[i]=(basep[i-1]*base[0]);
   }
   //for(lli i=1;i<=rows;i++){
   //   for(lli j=1;j<=cols;j++){
   //      if(s[i][j]!='B')cout<<i<<" "<<j<<" "<<s[i][j]<<"\n";
   //   }
   //}
   for(lli i=1;i<=rows;i++){
      lli hashtoh=0;
      for(lli j=1;j<=cols;j++){
         hashtoh*=base[0];
         hashtoh+=s[i][j]-'A'+1;
         //cout<<hashtoh<<" ";
         hashgore[i][j]=((hashgore[i-1][j]*basep[j])+hashtoh);
      }
      //cout<<"\n";
   }
   for(lli i=rows;i>=1;i--){
      lli dahash[nmax];
      memset(dahash,0,nmax);
      for(lli j=1;j<=cols;j++){
         dahash[j]=dahash[j-1];
         dahash[j]*=base[0];
         dahash[j]+=s[i][j]-'A'+1;
      }
      for(lli j=cols;j>=1;j--){
         lli ebahti=dahash[cols]-dahash[j-1]*basep[cols-j+1];
         hashdolu[i][j]=(hashdolu[i+1][j]+ebahti*basep[(cols-j+1)*(rows-i)]);
         //cout<<ebahti<<" ";
      }
      //cout<<"\n";
   }

   //for(lli i=1;i<=rows;i++){
   //   for(lli j=1;j<=cols;j++){
   //      cout<<hashdolu[i][j]<<" ";
   //   }
   //   cout<<"\n";
   //}
   lli anscol,ansrow=-1,anss;
   for(lli i=1;i<=cols;i++){
      if(hashgore[rows][cols-i]==hashdolu[1][i+1]){
         anscol=i;
         break;
      }
   }
   for(lli i=1;i<=rows;i++){
      for(lli j=0;j<anscol;j++){
         //cout<<i<<" "<<j<<"\n";
         //cout<<"cheking two tabs ->\nfirst tab "<<1<<" "<<1<<" "<<rows-i<<" "<<cols-j<<"\n";
         //cout<<"second tab "<<i+1<<" "<<j+1<<" "<<rows<<" "<<cols<<"\n";
         if(hashgore[rows-i][cols-j]==hashdolu[i+1][j+1]){
            ansrow=i;
            anss=j;
            break;
         }
      }
      if(ansrow!=-1)break;
   }
   cout<<ansrow<<" "<<anscol<<" "<<anss<<"\n";
}
//1+31*1+31*31+31*31*31
//2 3 0
