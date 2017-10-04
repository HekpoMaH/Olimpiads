#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1046];
struct ots
{
       int x1,x2,y1,y2;
};
ots a[1024];
int n;
void read ()
{
     int pos=1;
     int x,y;
     while(cin>>x)
     {
                  cin>>y;
                  a[pos].x1=x;
                  a[pos].y1=y;
                  cin>>x>>y;
                  a[pos].x2=x;
                  a[pos].y2=y;
                  pos++;
     }
     n=pos-1;
}
int dtr ( int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1*y2+y1*x3+x2*y3-x3*y2-y3*x1-x2*y1;
}
int used[1028],bru=0;
void dfs (int k)
{
     int i,sz;
     used[k]=1;
     bru++;
     sz=v[k].size();
     for(i=0;i<sz;i++)
     {
                      if(used[v[k][i]]==0)dfs(v[k][i]);
     }
}
int bett ( int aa,int bb , int cc )
{
    int ma , na;
    if(aa>cc){ma=aa;na=cc;}
    else{ma=cc;na=aa;}
    if(bb>=na&&bb<=ma)return 4;
    return -1;
}
void solve ()
{
     int i,j,o1,o2,o3,o4,o5,o6,o7,o8;
     for(i=1;i<=n;i++)
       for(j=i+1;j<=n;j++)
         if(i!=j)
         {
                 o1=dtr(a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[j].x1,a[j].y1);
                 o2=dtr(a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[j].x2,a[j].y2);
                 o3=dtr(a[j].x1,a[j].y1,a[j].x2,a[j].y2,a[i].x1,a[i].y1);
                 o4=dtr(a[j].x1,a[j].y1,a[j].x2,a[j].y2,a[i].x2,a[i].y2);
                 o5=dtr(a[i].x1,a[i].y1,a[j].x1,a[j].y1,a[i].x2,a[i].y2);
                 o6=dtr(a[i].x1,a[i].y1,a[j].x2,a[j].y2,a[i].x2,a[i].y2);
                 o7=dtr(a[j].x1,a[j].y1,a[i].x1,a[i].y1,a[j].x2,a[j].y2);
                 o8=dtr(a[j].x1,a[j].y1,a[i].x2,a[i].y2,a[j].x2,a[j].y2);
                 if(o8==0||o7==7||o6==0||o5==0)
                 {
                                             //  cout<<a[i].x1<<' '<<a[j].x1<<' '<<a[i].x2<<endl;
                                   if(o5==0&&((bett(a[i].x1,a[j].x1,a[i].x2)==4)&&(bett(a[i].y1,a[j].y1,a[i].y2)==4)))
                                   {
                                               v[i].push_back(j);
                                               v[j].push_back(i);
                                              // cout<<"o5"<<endl;
                                              // cout<<i<<' '<<j<<endl;
                                            //   cout<<a[i].x1<<' '<<a[j].x1<<' '<<a[i].x1<<endl;
                                             //  cout<<(bett(a[i].x1,a[j].x1,a[i].x2))<<' '<<a[i].x1<<' '<<a[j].x1<<' '<<a[i].x2<<endl;
                                              // cout<<o5<<' '<<o6<<' '<<o7<<' '<<o8<<endl;
                                   }
                                   else
                                   if(o6==0&&((bett(a[i].x1,a[j].x2,a[i].x2)==4)&&(bett(a[i].y1,a[j].y2,a[i].y2)==4)))
                                   {
                                               v[i].push_back(j);
                                               v[j].push_back(i);
                                              // cout<<i<<' '<<j<<endl;
                                              // cout<<o5<<' '<<o6<<' '<<o7<<' '<<o8<<endl;
                                   }
                                   else
                                   if(o7==0&&((bett(a[j].x1,a[i].x1,a[j].x2)==4)&&(bett(a[j].y1,a[i].y1,a[j].y2)==4)))
                                   {
                                         v[i].push_back(j);
                                         v[j].push_back(i);
                                         //cout<<i<<' '<<j<<endl;
                                        // cout<<o5<<' '<<o6<<' '<<o7<<' '<<o8<<endl;
                                   }
                                   else
                                   if(o8==0&&((bett(a[j].x1,a[i].x2,a[j].x2)==4)&&(bett(a[j].y1,a[i].y2,a[j].y2)==4)))
                                   {
                                               v[i].push_back(j);
                                               v[j].push_back(i);
                                             //  cout<<i<<' '<<j<<endl;
                                              // cout<<o5<<' '<<o6<<' '<<o7<<' '<<o8<<endl;
                                   }
                 }
                 else
                 {
                     if(((o1>0&&o2<0)||(o1<0&&o2>0))&&(((o3>0&&o4<0)||(o3<0&&o4>0))))
                     {
                                v[i].push_back(j);
                                v[j].push_back(i);
                                   //cout<<i<<' '<<j<<" S"<<endl;                                                     
                     }
                 }
         }
         dfs(n);
         cout<<n-bru<<endl;
}
int main ()
{
    read ();
    solve ();
    return 0;
}
/*
x1 y1 1 x1 y1
x2 y2 1 x2 y2
x3 y3 1 x3 y3
x1*y2+y1*x3+x2*y3-x3*y2-y3*x1-x2*y1*/
