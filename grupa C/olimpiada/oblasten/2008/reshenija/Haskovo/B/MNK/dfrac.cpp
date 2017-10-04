/* 
task: dfrac
lang: c++
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int vis[10000000];
int cik[100000],e=0;
int main()
{
    int a,b,p,z,t=0;
    long long k;
    cin>>a>>b>>k>>p;
    while(1)
    {
           z=a%b;    
           a=( a%b)*10;
       
           if ( vis[ z ]== 0 )vis[ z ]= 1;
           else
            {
                   t=1;
                   break;
            }
            cik[e]=a/b;   
           e++;
            if(e>k+p)
             {
                               t=2;
                               break;
             }
           if(z==0){t=3;break;}
    }

   if(t==2)
    for(int i=k; i<=p; i++)
    cout<<cik[i];
    if(t==3)
    {
            int j=0;
            if(e>k)
            for(int i=k; i<e; i++)
            {cout<<cik[i];j++;}
            while(j!=p)
            {
                       cout<<"0";
                       j++;
            }
    }
    if(t==1)
    {
            int j=0;
            int i=k%e;
            if(i!=0)i--;
            while(j!=p)
            {
                       cout<<cik[i];
                       if(i+1==e)i=0;
                       else i++;
                       
                       j++;
            }
    }
    cout<<endl;
    return 0; 
}
