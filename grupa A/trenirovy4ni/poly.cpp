//broq na ocvetqvaniqta na vyrhovete na N ygylnig s K cvqta
//Burnside Lemma
#include<bits/stdc++.h>
using namespace std;
const int nmax=29;
int N,K;
int a[nmax];
int st[nmax];
int used[nmax];
int cnt(){
   int br=0;
   memset(used,0,sizeof(used));
   for(int i=1;i<=N;i++){
      if(used[i]==0){
         int curr=i;
         while(used[curr]==0){
            used[curr]=1;
            curr=a[curr];
         }
         br++;
      }
   }
   return br;
}
void shiftLeft(){
   int firstEl=a[1];
   for(int i=1;i<N;i++){
      a[i]=a[i+1];
   }
   a[N]=firstEl;
}
int main(){
   cin>>N>>K;
   st[0]=1;
   for(int i=1;i<=N;i++){
      a[i]=i;
      st[i]=st[i-1]*K;
   }
   int ans=0;
   a[1]=5;a[2]=4;a[3]=3;a[4]=2;a[5]=1;
   for(int i=1;i<=N;i++){
      ans+=st[cnt()];
      reverse(a+1,a+N+1);
      ans+=st[cnt()];
      reverse(a+1,a+N+1);
      shiftLeft();
   }
   ans/=(2*N);
   cout<<ans<<"\n";
}
