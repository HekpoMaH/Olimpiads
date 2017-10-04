#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int x[6],y[6],a[6],b[6];
int n;
struct point{
   int x,y;
   int obr,idx;
   point(){}
   point(int _x,int _y,int _obr,int _idx){
      x=_x;
      y=_y;
      obr=_obr;
      idx=_idx;
   }
};
void rot(int &x4,int &y4,int aa,int bb){
   x4-=aa;
   y4-=bb;
   int nx=-y4,ny=x4;
   x4=nx;
   y4=ny;
   x4+=aa;
   y4+=bb;
}
void solve(){
   vector<point> p;
   int xx,yy;
   for(int i=1;i<=4;i++){
      xx=x[i];yy=y[i];
      p.pb(point(x[i],y[i],0,i));
      for(int j=1;j<=3;j++){
         rot(xx,yy,a[i],b[i]);
         p.pb(point(xx,yy,j,i));
      }
   }
   int ans=1e9;
   map<int,int> mp;
   map<int,int>::iterator it;
   mp.clear();
   //cout<<"points:";
   //for(int i=0;i<p.size();i++)cout<<"("<<p[i].x<<","<<p[i].y<<","<<p[i].idx<<") ";
   //cout<<"\n";
   for(int i1=0;i1<p.size();i1++){
      for(int i2=i1+1;i2<p.size();i2++){
         for(int i3=i2+1;i3<p.size();i3++){
            for(int i4=i3+1;i4<p.size();i4++){
               if((p[i1].idx==p[i2].idx))continue;
               if((p[i1].idx==p[i3].idx))continue;
               if((p[i1].idx==p[i4].idx))continue;
               if((p[i2].idx==p[i3].idx))continue;
               if((p[i2].idx==p[i4].idx))continue;
               if((p[i3].idx==p[i4].idx))continue;
               mp.clear();
               xx=p[i1].x-p[i2].x,yy=p[i1].y-p[i2].y;
               mp[xx*xx+yy*yy]++;
               //cout<<xx*xx+yy*yy<<" ";
               xx=p[i1].x-p[i3].x,yy=p[i1].y-p[i3].y;
               mp[xx*xx+yy*yy]++;
               //cout<<xx*xx+yy*yy<<" ";
               xx=p[i1].x-p[i4].x,yy=p[i1].y-p[i4].y;
               mp[xx*xx+yy*yy]++;
               //cout<<xx*xx+yy*yy<<" ";
               xx=p[i2].x-p[i3].x,yy=p[i2].y-p[i3].y;
               mp[xx*xx+yy*yy]++;
               //cout<<xx*xx+yy*yy<<" ";
               xx=p[i2].x-p[i4].x,yy=p[i2].y-p[i4].y;
               mp[xx*xx+yy*yy]++;
               //cout<<xx*xx+yy*yy<<" ";
               xx=p[i3].x-p[i4].x,yy=p[i3].y-p[i4].y;
               mp[xx*xx+yy*yy]++;
               //cout<<xx*xx+yy*yy<<" ";
               //cout<<"i1="<<i1<<" "<<"i2="<<i2<<" i3="<<i3<<" i4="<<i4<<"\n";
               bool fl=true;
               for(it=mp.begin();it!=mp.end();it++){
                  if(it->second==2||it->second==4){
                     continue;
                  }
                  fl=false;
                  //cout<<it->first<<" "<<it->second<<"\n";
                  break;
               }
               //cout<<"fl="<<fl<<"\n";
               if(fl){
                  //cout<<p[i1].x<<" "<<p[i1].y<<" "<<p[i1].obr<<"\n";
                  //cout<<p[i2].x<<" "<<p[i2].y<<" "<<p[i2].obr<<"\n";
                  //cout<<p[i3].x<<" "<<p[i3].y<<" "<<p[i3].obr<<"\n";
                  //cout<<p[i4].x<<" "<<p[i4].y<<" "<<p[i4].obr<<"\n";
                  ans=min(ans,p[i1].obr+p[i2].obr+p[i3].obr+p[i4].obr);
               }
            }
         }
      }
   }
   if(ans==(int)1e9)cout<<"-1\n";
   else cout<<ans<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=4;j++)cin>>x[j]>>y[j]>>a[j]>>b[j];
      solve();
   }
}
