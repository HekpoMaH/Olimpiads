#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int a[nmax];
int n;
void quicks(int lef,int righ,int a[]){
   //cout<<"lef="<<lef<<" righ="<<righ<<"\n";
   //cout.flush();
   if(lef>=righ){
      return;
   }
   int i=lef,j=righ;
   int pivot=a[(lef+righ)/2];
   while(i<=j){
      //cout<<"i="<<i<<" j="<<j<<" "<<a[i]<<" "<<a[j]<<"\n";
      //cout.flush();
      while(a[i]<pivot)i++;
      while(a[j]>pivot)j--;
      if(i<=j)swap(a[i],a[j]),i++,j--;
   }
   quicks(lef,j,a);
   quicks(i,righ,a);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   srand(time(NULL));
   cin>>n;
   for(int i=1;i<=n;i++){
      a[i]=rand()%1000;
   }
   for(int i=1;i<=n;i++){
      cout<<a[i]<<" ";
   }
   cout<<"\n";
   cout.flush();
   quicks(1,n,a);
   for(int i=1;i<=n;i++){
      cout<<a[i]<<" ";
   }
   cout<<"\n";
}
