#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int S,N,p=0,pom,k=1,Sloc,br=0,Min=0;
    cin>>S>>N;
    int a[N];
    for(int i=0;i<N;i++)
    cin>>a[i];
    for(p;p<N;p++)
{
        for(int i=N-1;i>0;i--)
{
        if(a[i]<a[i-1])
{
        pom=a[i-1];
        a[i-1]=a[i];
        a[i]=pom;
        }
}}      
 for(int i=0;i<N;i++)
                          /*dotuk e nared */
Sloc=S;
while(k<N)
{
   for(int i=k;i<=N;i++)
  { if((Sloc-a[N-i])>0)
   {
    do
    {
      Sloc=Sloc-a[N-i];
      br++;
      }
      while((Sloc-a[N-i])>=0);
      
    }
    else;
}

if(k==1)
{Min=br;}

if(Min>br)
{Min=br;br=0;}

br=0;
Sloc=S;
k++;

}
cout<<Min<<endl;



return 0;
}
