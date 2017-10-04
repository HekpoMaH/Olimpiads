#include<bits/stdc++.h>
using namespace std;
const int nmax=200009;
long long n,w,h;
struct centar{
    long long xc,yc,inidx;
};
vector<centar >v;
double x,y;
long long xx,yy,igreci[nmax];
long long it[nmax*4],idx[nmax];
long long ans[nmax];
void rec(long long pos,long long lef,long long righ){
    if(lef==righ){
        idx[lef]=pos;
        //it[pos]=igreci[lef];
        return;
    }
    rec(pos*2,lef,(lef+righ)/2);
    rec(pos*2+1,(lef+righ)/2+1,righ);
    //it[pos]=max(it[pos*2],it[pos*2+1]);
}
void updin(long long pos,long long lef,long long righ,long long ql,long long qr,long long num){
    //cout<<pos<<" "<<ql<<" "<<lef<<" "<<righ<<" "<<righ<<endl;
    if(ql>righ||qr<lef)return;
    if(ql<=lef&&righ<=qr){it[pos]=num;return;}
    updin(pos*2,lef,(lef+righ)/2,ql,qr,num);
    updin(pos*2+1,(lef+righ)/2+1,righ,ql,qr,num);
}
long long qry(long long pos){
    long long o=0;
    pos=idx[pos];
    while(pos!=0)
    {
        o=max(o,it[pos]);
        pos/=2;
    }
    return o;
}
bool cmp(centar x4,centar y4){
    if(x4.xc<y4.xc)return true;
    if(x4.xc>y4.xc)return false;
    if(x4.yc>y4.yc)return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>w>>h>>n;
    centar wtf;
    long long np=n;
    for(long long i=1;i<=n;i++){
        cin>>x>>y;
        xx=round(x*2.0);
        yy=round(y*2.0);igreci[i]=yy;
        wtf.xc=xx;
        wtf.yc=yy;
        wtf.inidx=i;
        v.push_back(wtf);
        //cout<<xx<<" "<<yy<<endl;
    }
    //for(long long i=1;i<=n;i++)cout<<igreci[i]<<" ";cout<<endl;
    igreci[n+1]=0;igreci[n+2]=h*2;
    sort(igreci+1,igreci+n+3);
    unique(igreci+1,igreci+n+3);
    n=unique(igreci+1,igreci+n+3)-&igreci[0]-1;
    //cout<<n<<endl;
    igreci[0]=-10000;
    //for(long long i=1;i<=n;i++)cout<<igreci[i]<<" ";cout<<endl;
    rec(1,1,n);
    sort(v.begin(),v.end(),cmp);
    long long r,qr,lidx,ridx;
    //cout<<*upper_bound(igreci+1,igreci+n+1,2)<<endl;exit(0);
    for(long long i=0;i<v.size();i++){
        qr=qry(lower_bound(igreci+1,igreci+n+1,v[i].yc)-&igreci[0]);
        r=v[i].xc-qr;
        //cout<<"x="<<v[i].xc<<" y="<<v[i].yc<<" r="<<r<<" qr="<<qr<<" lo="<<*lower_bound(igreci+1,igreci+n+1,v[i].yc-r)<<" up="<<*(upper_bound(igreci+1,igreci+n+1,v[i].yc+r)-1)<<endl;
        ans[v[i].inidx]=r;
        lidx=lower_bound(igreci+1,igreci+n+1,v[i].yc-r)-&igreci[0];
        ridx=upper_bound(igreci+1,igreci+n+1,v[i].yc+r)-&igreci[0]-1;
        if(ridx==0)ridx=1;
        //cout<<igreci[lidx]<<" - "<<igreci[ridx]<<endl;
        updin(1,1,n,lidx,ridx,v[i].xc+r);
    }
    for(long long i=1;i<=np;i++){
        cout<<ans[i]<<"\n";
    }
}
