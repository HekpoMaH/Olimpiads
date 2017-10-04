#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int X=5500,a[3000],s,S,n,br;
void read()
{
     int i;
     cin>>s>>n;
     for(i=1;i<=n;i++)
     {
          cin>>a[i];
     }
}
int T(int i,int pos)
{
     int j;
     br=br+s/i;
     s=s%i;
     if(!s) return 0;
     for(j=pos-1;j>0;j--)
     {
          if(a[j]<s) 
          {
               if(T(a[j],j)==0) 
               {
                    if(br<X) X=br;
               }
          } 
     }
}
int main()
{
     int i;
     read();
     sort(a,a+n);
     S=s;
     for(i=n;i>0;i--)
     {
          s=S;
          br=0;
          T(a[i],i);
     }
     cout<<X<<endl;          
return 0;
}
