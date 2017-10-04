//heap with changing value of an inner element
#include<bits/stdc++.h>
using namespace std;
const int maxn=1009,maxel=1009;
int heap[maxn],inheap[maxel];
int hsz;
int n;
void push(int el,int i){
   heap[++hsz]=el;
   inheap[i]=hsz;
   int idx=hsz;
   while(idx!=1&&heap[idx/2]>heap[idx]){
      swap(heap[idx/2],heap[idx]);
      swap(inheap[idx/2],inheap[idx]);
      idx/=2;
   }
}
void change(int i,int st){
   int idx=inheap[i];
   heap[idx]+=st;
   while(idx!=1&&heap[idx/2]>heap[idx]){
      swap(heap[idx/2],heap[idx]);
      swap(inheap[idx/2],inheap[idx]);
      idx/=2;
   }
   while(idx*2<=hsz){
      int mni=idx;
      if(heap[idx*2]<heap[idx])mni=idx*2;
      if(idx*2+1<=hsz&&heap[idx*2+1]<heap[idx*2])mni=idx*2+1;
      if(idx!=mni){
         swap(heap[mni],heap[idx]);
         swap(inheap[mni],inheap[idx]);
         idx=mni;
      }
      else break;
   }
}
int main(){
   heap[0]=19999;
   cin>>n;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      push(x,i);
   }
   int m;
   cout<<inheap[1]<<"\n";
   for(int j=1;j<=hsz;j++)cout<<heap[j]<<" ";cout<<"\n";
   cin>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      change(x,y);
      for(int j=1;j<=hsz;j++)cout<<heap[j]<<" ";cout<<"\n";
      cout<<heap[1]<<"\n";
   }
}
