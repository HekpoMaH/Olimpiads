#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n,N,ans=INF;
int X[20],Y[20];
int D[20][20],DS[20];
int BITS(int w){
  int ans=0;
  while(w>0){
   if(w&1)++ans;
   w>>=1;
            }
  return ans;
}
vector<int> T;
void TRY(){
  int i,j,L=T.size();
  do{
   int cur=DS[T[0]];
   for(i=1;i<L;++i)
    cur+=D[T[i-1]][T[i]];
   if(ans>cur)ans=cur;
  }while(next_permutation(T.begin(),T.end()));
}
int main(){
  int i,j,k,l;
  cin>>n;N=2*n;
  for(i=0;i<N;++i)
   cin>>X[i]>>Y[i];
  for(i=0;i<N;++i)DS[i]=max(abs(X[i]),abs(Y[i]));
  for(i=0;i<N;++i)
   for(j=i;j<N;++j)
    D[j][i]=D[i][j]=max(abs(X[i]-X[j]),abs(Y[i]-Y[j]));
  int UP=(1<<N);
  for(l=0;l<UP;++l)
   if(BITS(l)==n){
    T.clear();
    for(i=0;i<N;++i)
     if(l&(1<<i))T.push_back(i);
    TRY();
                 }
  cout<<ans<<'\n';
  return 0;
}
