#include<iostream>
using namespace std;
int s,n,a[32][1024][1024],uni[32];
int compa(int n1, int n2)
{
    int i,j,i1,j1;
    bool flag=true;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[n1][i][j]!=a[n2][i][j])
            {
                flag=false;
                break;
            }
    if(flag==true)return true;
    flag=true;
    for(i=0;i<n;i++)
        for(j=0,j1=n-1;j<n,j1>=0;j++,j1--)
            if(a[n1][i][j]!=a[n2][i][j1])
            {
                flag=false;
                break;
            }
    if(flag==true)return true;
    flag=true;
    for(i=0,i1=n-1;i<n,i1>=0;i++,i1--)
        for(j=0,j1=n-1;j<n,j1>=0;j++,j1--)
            if(a[n1][i][j]!=a[n2][i1][j1])
            {
                flag=false;
                break;
            }
    if(flag==true)return true;
    flag=true;
    for(i=0,i1=n-1;i<n,i1>=0;i++,i1--)
        for(j=0;j<n;j++)
            if(a[n1][i][j]!=a[n2][i1][j])
            {
                flag=false;
                break;
            }
    if(flag==true)return true;
    return false;
}

int main()
{
    cin>>s>>n;
    char t[1024];
    int i,j,p,ans=0;
    gets(t);
    for(i=0;i<s;i++)
        for(j=0;j<n;j++)
        {    
            gets(t);
            for(p=0;p<n;p++)
            {
                if(t[p]=='0')a[i][j][p]=0;
                else a[i][j][p]=1;
            }
        }
   for(i=0;i<s;i++)
   {
        if(uni[s]==1)continue;
        else
        {
            for(j=i+1;j<s;j++)
            {
                if(compa(i,j))
                {
                    uni[i]=1;
                    uni[j]=1;
                    break;
                }
            }
            if(j==s)ans++;
        }
    }
    cout<<ans;    
   
   return 0;
} 
