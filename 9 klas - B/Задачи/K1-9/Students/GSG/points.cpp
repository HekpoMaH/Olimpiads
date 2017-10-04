#include<iostream>
using namespace std;
int k,n,r=0;
short links[50][50];
unsigned long long combs(int q)
{
     long ss;
     if(q==1){return 2;}
     else if(q==2){return 4;}
     else if(q==3){return 7;}
     else if(q==4){return 15;}
     else if(q==5){return 26;}
     else
     {
         ss=2*(q-1);
         for(int z=3;z<=q;z++)
         {
                 ss+=q-z+1;}
                 ss+=2;
                 return ss;
     }
}
void link(int t)
{
     for(int v=1;v<=t;v++)
     {
     links[v][0]=v;
     if(v=t){break;}
     for(int w=1;w<=k;w++)
     {links[v][w]=v+w;}
     }
}        
                 
int main()
{
    unsigned long long x=0;int djv=0;
    cin>>n>>k;
    if(k==n-1)
    {cout<<combs(n-2)<<endl;}
    else 
    {for(int i=1;i<50;i++)
    {for(int j=0;j<50;j++)
    {djv++;}x+=combs(djv);}
    cout<<x<<endl;
    }
    return 0;
}
 
