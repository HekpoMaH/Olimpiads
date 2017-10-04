#include<bits/stdc++.h>
using namespace std;
const int nmax=10009,itmax=7*nmax;
int n;
int xc[nmax];
int br=0,br2=0;
struct seg{
   int x,ys,ye;
   bool boe;
   //boe-> begin(0) or end(1)
};
struct napeshointervalnoto{
   int brp,pokrd;
};
seg segments[nmax*2];
napeshointervalnoto it[nmax*7];
napeshointervalnoto toup[nmax*7];
int upd(int pos,int l,int r,int xu,int yu,int st){
   cout<<"pos="<<pos<<" l="<<l<<" r="<<r<<" xu="<<xu<<" yu="<<yu<<" st="<<st<<"\n";
   /*if(toup[pos]!=0){

      if(it[pos].brp-st==0){
         if(it[pos].brp>0){
            it[pos].pokrd+=xc[r+1]-xc[l];
            return (xc[r+1]-xc[l]);
         } 
      }
      else 
         if(it[pos].brp==0){
            it[pos].pokrd-=xc[r+1]-xc[l];
            return -(xc[r+1]-xc[l]);
         }
   }*/
   if(xu<=l&&r<=yu){
      it[pos].brp+=st;
      if(l<r){
         toup[pos*2].brp+=st;
         toup[pos*2+1].brp+=st;
      }
      if(it[pos].brp-st==0){
         if(it[pos].brp>0){
            cout<<"It was added to "<<it[pos].pokrd<<" which is ["<<l<<","<<r<<"] the value "<<xc[r+1]-xc[l]<<" and now is ";
            it[pos].pokrd+=xc[r+1]-xc[l];
            cout<<it[pos].pokrd<<"\n";
            return (xc[r+1]-xc[l]);
         } 
      }
      else 
         if(it[pos].brp==0){
            cout<<"iT was added to "<<it[pos].pokrd<<" which is ["<<l<<","<<r<<"] the value "<<-xc[r+1]+xc[l]<<" and now is ";
            it[pos].pokrd-=xc[r+1]-xc[l];
            cout<<it[pos].pokrd<<"\n";
            return -(xc[r+1]-xc[l]);
         }
   }
   if(l==r)return 0;
   int nl,nr,cur=0;
   nl=l;nr=(l+r)/2;
   if(!(nr<xu||nl>yu))cur+=upd(pos*2,nl,nr,xu,yu,st);

   nl=(l+r)/2+1;nr=r;
   if(!(nr<xu||nl>yu))cur+=upd(pos*2+1,nl,nr,xu,yu,st);
   
   if(it[pos].brp==0){
      cout<<"it was added to "<<it[pos].pokrd<<" which is ["<<l<<","<<r<<"] the value "<<cur<<" and now is ";
      it[pos].pokrd+=cur;
      cout<<it[pos].pokrd<<"\n";
      return cur;
   }
   return 0;
}
int get(){
   return it[1].pokrd;
}
void adseg(int x,int ys,int ye,bool boe){
   br++;
   segments[br].x=x;
   segments[br].ys=ys;
   segments[br].ye=ye;
   segments[br].boe=boe;
}
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      int x1,y1,x2,y2;
      cin>>x1>>y1>>x2>>y2;
      adseg(x1,y1,y2,0);
      adseg(x2,y1,y2,1);
      br2++;xc[br2]=y1;
      br2++;xc[br2]=y2;
   }
   sort(xc+1,xc+br2+1);
   br2=unique(xc+1,xc+br2+1)-&xc[1];
   //for(int i=1;i<=br2;i++)cout<<xc[i]<<" ";
   //cout<<"\n";
}
bool cmp(seg f,seg s){
   if(f.x!=s.x)return f.x<s.x;
   if(f.ys!=s.ys)return f.ys<s.ys;
   return f.ye<s.ye;
}
int compress(int dy){
   return lower_bound(xc+1,xc+br2+1,dy)-&xc[0];
}
int decompress(int dc){
   return xc[dc];
}
void sweep(){
   long long area=0;
   assert(br2<=2*n);
   assert(segments[1].boe==0);
   for(int i=1;i<=br2;i++)cout<<xc[i]<<" ";cout<<"\n";
   for(int i=1;i<=br;i++){
      int stoi=0;
      if(segments[i].boe==0){
         stoi=1;
      }
      else{
         stoi=-1;
      }
      cout<<i<<" "<<segments[i].x<<" "<<segments[i-1].x<<" "<<get()<<"\n";
      area+=(long long)(get()*(segments[i].x-segments[i-1].x));
      upd(1,1,br2-1,compress(segments[i].ys),compress(segments[i].ye)-1,stoi);
      cout<<"after updating from el. "<<compress(segments[i].ys)<<" to el. "<<compress(segments[i].ye)-1
         <<" e.g. ("<<segments[i].ys<<","<<segments[i].ye<<") "
         <<"the sum now is "<<get()<<"\n";
   }
   cout<<area<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   sort(segments+1,segments+br+1,cmp);
   sweep();
}
