#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=1e6+9;
#define make_pair(a,b) mp(a,b)
int n,a,b;
lli fib1=0,fib2=1;
string s;
int seq1[nmax];
int seq2[nmax];
int sz[3];
void readseq(int seq[],int num){
   cin>>s;
   sz[num]=s.size();
   for(int i=0;i<s.size();i++){
      seq[i+1]=s[i]-'0';
   }
}
void upseq(int seq[],int num){
   reverse(seq+1,seq+sz[num]+1);
   int cur;
   for(int i=3*sz[num];i>=3;i--){
      if(seq[i-2]>0&&seq[i-1]>0){
         seq[i]++;
         seq[i-1]--;
         seq[i-2]--;
         cur=i;
         while(seq[cur]>0&&seq[cur+1]>0){
            seq[cur]--;
            seq[cur+1]--;
            seq[cur+2]++;
            cur+=2;
         }
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   readseq(seq1,1);
   readseq(seq2,2);
   upseq(seq1,1);
   upseq(seq2,2);
   for(int i=max(sz[1],sz[2])*3;i>=1;i--){
      if(seq1[i]>seq2[i]){
         cout<<">\n";
         return 0;
      }
      if(seq1[i]<seq2[i]){
         cout<<"<\n";
         return 0;
      }
   }
   cout<<"=\n";
}
