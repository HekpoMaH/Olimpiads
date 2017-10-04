/*
Task:metro
Lang:C++
*/
#include<iostream>
using namespace std;
long long a[103][1002];
long long money=-1;
long long f=0;
int n;
int pari(int x,int y,long long m)
{
    if(x<0 || x>100)return 0;
    if(y==n-1){if(money==-1)money=m+a[x][y];else money=min(money,m+a[x][y]);return 0;}
    pari(x-2,y+1,m+a[x][y]);
    pari(x-1,y+1,m+a[x][y]);
    pari(x,y+1,m+a[x][y]);
    pari(x+1,y+1,m+a[x][y]);
    return 0;
            
}           
int main()
{
    cin>>n;
    int t;
    for(int i=0;i<n;i++)
    {
            cin>>t;
            a[t][i]=1;
            int q=1;
            int k=t-1;
            while(k>=0)
            {
                       a[k][i]=q*q;
                       q++;
                       k--;
            }
            q=1;
            k=t+1;
            while(k<=100)
            {
                       a[k][i]=7*q;
                       k++;q++;
            }
    }
   for(int i=1;i<=100;i++)pari(i,0,0);
   cout<<money<<endl;
   return 0;
}
            
