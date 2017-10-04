#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,minn=1000000;
int p[12][2];
bool a[12];
vector <int> v;
void read()
{
     cin>>n;
     for(int i=0;i<n*2;i++)
     cin>>p[i][0]>>p[i][1];
}
void smqt()
{
     int sum=0;
     int lx=0,ly=0,tx,ty;
     for(int i=0;i<n;i++)
     {
             
             
                   tx=abs(lx-p[v[i]][0]);
                   ty=abs(ly-p[v[i]][1]);
                   sum+=max(tx,ty);
                   lx=p[v[i]][0];
                   ly=p[v[i]][1];
             
     }
     if(sum<minn)minn=sum;
   //  if(sum==6)
    // for(int i=0;i<n;i++)
     //cout<<v[i]<<endl;
}  
void solve()
{
     for(int i=n;i<n+n;i++)
     a[i]=1;
     v.clear();
               for(int i=0;i<n+n;i++)
               if(a[i])
               v.push_back(i);
               smqt();
               while(next_permutation(v.begin(),v.end()))
               smqt();
     while(next_permutation(a,a+n+n))
     {      
               v.clear();
               for(int i=0;i<n+n;i++)
               if(a[i])
               v.push_back(i);
               smqt();
               while(next_permutation(v.begin(),v.end()))
               smqt();
     }
     cout<<minn<<endl;
}
int main()
{
    read();
    solve();
    return 0;
}
