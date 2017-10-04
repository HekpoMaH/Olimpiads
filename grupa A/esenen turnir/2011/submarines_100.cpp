#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
const int inf=1e9;
typedef int lli; 
int n,m;
int d[nmax];
lli s[nmax];
lli bit[nmax];
void up(int pos,int x){
   while(pos<=n){
      bit[pos]+=x;
      pos+=pos&(-pos);
   }
   return;
}
lli get(int pos){
   lli re=0;
   while(pos!=0){
      re+=bit[pos];
      pos-=pos&(-pos);
   }
   return re;
}
lli Ssum(int lef,int righ){
   return get(righ)-get(lef-1);
}
void inits(){
   stack<int> st;
   int br=0;
   st.push(inf);
   for(int i=1;i<=n;i++){
      br=0;
      while(st.top()<d[i]){
         st.pop();
         br++;
      }
      st.push(d[i]);
      s[i]=br;
   }
}
int idxpos[nmax];
int mpos[4*nmax];
struct node{
   int ll,rr,id;
   node(){}
   node(int L,int R,int X){
      ll=L;
      rr=R;
      id=X;
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void getidxs(){
      if(ll==rr){
         idxpos[ll]=id;
         mpos[id]=ll;
         return;
      }
      left().getidxs();
      right().getidxs();
      if(d[mpos[left().id]]<d[mpos[right().id]]){
         mpos[id]=mpos[right().id];
      }
      else
         mpos[id]=mpos[left().id];
   }
   void upn(int pos){
      int idx=idxpos[pos];
      idx/=2;
      while(idx!=0){
         if(d[mpos[idx*2]]<d[mpos[idx*2+1]]){
            mpos[idx]=mpos[idx*2+1];
         }
         else{
            mpos[idx]=mpos[idx*2];
         }
         idx/=2;
      }
   }
   void swpos(int pos){
      upn(pos);
      upn(pos+1);
   }
   int gmax(int L,int R){
      if(ll>R||L>rr)return 0;
      if(L<=ll&&rr<=R){
         return mpos[id];
      }
      int mxp1=left().gmax(L,R);
      int mxp2=right().gmax(L,R);
      if(d[mxp1]<d[mxp2]){
         return mxp2;
      }
      else
         return mxp1;
   }
};
int idxpos2[nmax];
int mpos2[4*nmax];
struct node2{
   int ll,rr,id;
   node2(){}
   node2(int L,int R,int X){
      ll=L;
      rr=R;
      id=X;
   }
   node2 left(){
      return node2(ll,(ll+rr)/2,id*2);
   }
   node2 right(){
      return node2((ll+rr)/2+1,rr,id*2+1);
   }
   void getidxs(){
      if(ll==rr){
         idxpos2[ll]=id;
         mpos2[id]=ll;
         return;
      }
      left().getidxs();
      right().getidxs();
      if(s[mpos2[left().id]]<s[mpos2[right().id]]){
         mpos2[id]=mpos2[right().id];
      }
      else
         mpos2[id]=mpos2[left().id];
   }
   void upn(int pos){
      int idx=idxpos2[pos];
      idx/=2;
      while(idx!=0){
         if(s[mpos2[idx*2]]<s[mpos2[idx*2+1]]){
            mpos2[idx]=mpos2[idx*2+1];
         }
         else{
            mpos2[idx]=mpos2[idx*2];
         }
         idx/=2;
      }
   }
   int gmax(int L,int R){
      if(ll>R||L>rr)return 0;
      if(L<=ll&&rr<=R){
         return mpos2[id];
      }
      int mxp1=left().gmax(L,R);
      int mxp2=right().gmax(L,R);
      if(s[mxp1]<s[mxp2]){
         return mxp2;
      }
      else
         return mxp1;
   }
};
node root(1,n,1);
node2 root2(1,n,1);
bool chek1(int aa,int pos){
   return d[aa]<d[root.gmax(aa,pos)];
}
int ansq1(int i){
   int l=i,r=n+1,mid;
   while(l+1<r){
      mid=(l+r)/2;
      if(chek1(i,mid)==true){
         r=mid;
      }
      else
         l=mid;
   }
   return r;
}
bool chek2(int aa,int pos){
   return d[aa]<d[root.gmax(pos,aa)];
}
int ansq2(int i){
   int l=0,r=i,mid;
   while(l+1<r){
      mid=(l+r)/2;
      if(chek2(i,mid)==true){
         l=mid;
      }
      else
         r=mid;
   }
   return l;
}
void solve(int posic){
   int i=posic;
   if(d[posic]>d[posic+1]){
      int kotdqsno=ansq1(posic+1);
      if(kotdqsno<=n){
         s[kotdqsno]--;
         up(kotdqsno,-1);
         root2.upn(kotdqsno);
      }
      swap(d[posic],d[posic+1]);
      root.swpos(posic);
      int prev2,prev;
      int kotlqvo=ansq2(posic);
      prev=s[i];
      prev2=s[i+1];
      s[i]=i-kotlqvo-1-Ssum(kotlqvo+1,i-1);
      s[i+1]=prev-s[i]+1;
      up(i,s[i]-prev);
      root2.upn(i);
      up(i+1,s[i+1]-prev2);
      root2.upn(i+1);
   }
   else{
      swap(d[posic],d[posic+1]);
      root.swpos(posic);
      int prev,prev2;
      prev=s[i];
      prev2=s[i+1];
      up(i+1,-s[i+1]);
      s[i+1]=0;
      root2.upn(i+1);
      cout.flush();
      s[i]=prev+prev2-1;
      up(i,s[i]-prev);
      root2.upn(i);
      int kotdqsno=ansq1(i+1);
      if(kotdqsno<=n){
         s[kotdqsno]++;
         up(kotdqsno,1);
         root2.upn(kotdqsno);
      }
   }

}
int main(){
   d[0]=0;
   ios_base::sync_with_stdio(false);
   cin.tie();
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>d[i];
   }
   root.rr=n;
   root2.rr=n;
   inits();
   for(int i=1;i<=n;i++){
      up(i,s[i]);
   }
   cout.flush();
   root.getidxs();
   root2.getidxs();
   for(int i=1;i<=m;i++){
      int x;
      cin>>x;
      if(x==0){
         cout<<s[mpos2[1]]<<"\n";
      }
      else{
         solve(x);
      }
   }
}
/*nai golqmoto k, che k<i, d(k)>d(i)
 *min k, takova che k>i i d(k)>d(i)
 */
