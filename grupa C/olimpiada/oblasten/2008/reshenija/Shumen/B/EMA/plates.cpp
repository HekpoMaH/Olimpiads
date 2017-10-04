#include<iostream>
#include<vector>
using namespace std;



struct pl
{
       int f[32];
       int b[32];
};

vector<pl>lp;
int br,m,n,a[32],b[32];
bool used[1024];

bool equ(int e,int v)
{
     int i;int l1=0,l2=0,l3=0,l4=0;
     for(i=0;i<m;i++)
     {
           a[i]=lp[e].f[i];
           b[i]=lp[v].f[i];
     }
     for(i=0;i<n;i++)
      if(a[i]!=b[i]){l1=1;break;}
     for(i=0;i<m;i++)
     {
           a[i]=lp[e].f[i];
           b[i]=lp[v].b[i];
     }
     for(i=0;i<n;i++)
      if(a[i]!=b[i]){l2=1;break;}
     for(i=0;i<m;i++)
     {
           a[i]=lp[e].b[i];
           b[i]=lp[v].b[i];
     }
     for(i=0;i<n;i++)
      if(a[i]!=b[i]){l3=1;break;}
     for(i=0;i<m;i++)
     {
           a[i]=lp[e].b[i];
           b[i]=lp[v].f[i];
     }
     for(i=0;i<n;i++)
      if(a[i]!=b[i]){l4=1;break;}
     if(l1==0||l2==0||l3==0||l4==0)return 1;
     return 0;
}

int main()
{
    int i,j,k;
    string s;
          cin>>m>>n;
          for(i=0;i<m;i++)
          {
           for(j=0;j<n;j++)
           {
                           cin>>s;
                           int t=1,sum=0,sum2=0;
                           for(k=0;k<n;k++)
                           {
                              if(s[k]=='1')sum+=t;
                              if(s[n-k-1]=='1')sum2+=t;
                              t*=2;
                           }
                           a[j]=sum;
                           b[j]=sum2;
           }
           pl fe;
           for(k=0;k<n;k++)
           {
                           fe.f[k]=a[k];
                           fe.b[k]=b[k];
           }
           lp.push_back(fe);
          }
          for(i=0;i<m;i++)
           for(j=0;j<m;j++)
            {
                           if(i!=j&&used[i]!=1&&used[j]!=1)
                                 used[i]=equ(i,j);
            }
          for(i=0;i<m;i++)
           if(used[i]==0)br++;
          cout<<br<<endl;  
          return 0;
}
