/*
TASK:ship
LANG:C++
*/
#include<iostream>
#include<vector>
using namespace std;
vector <int> v[10001];
int n,a[20000],used[15467],minm,sb,bb,sss=0;
void dfs(int k)
{
     int i,m,x;
     used[k]=1;
     cout<<used[1]<<' '<<used[2]<<' '<<used[3]<<endl;
     if(k<minm)minm=k;
     sb+=a[k];
     bb++;
     m=v[k].size();
     //for(i=1;i<=m  ;i++)
     //{
      //             x=v[k][i];
       //                         if(used[x]==0)dfs(x);
     //}
}
void read ()
{
     cin>>n;
     int i,x;
     for(i=1;i<=n;i++)
     {
            cin>>x;
            a[i]=x;          
     }
     for(i=1;i<=n;i++)
     {
                      cin>>x;
                      x++;
                      v[i].push_back(x);
     }
}
void solve ()
{
     int i;
     
     for(i=1;i<=n;i++)    
     {
                          if(used[i]==0)
                          {
                                       
                                        //minm=200001;
                                       // sb=0;
                                        //bb=0;
                                        //dfs(i);
                                       //sb-=minm;
                                        //sb+=(bb-1)*(minm);
                                        sss+=a[i];
                                         
                          }
     }
     cout<<sss<<endl;
}
int main ()
{
    read ();
    solve();
}
