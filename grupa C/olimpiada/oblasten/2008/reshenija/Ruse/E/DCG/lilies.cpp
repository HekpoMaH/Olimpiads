#include<iostream>
using namespace std;
int main()
{
    int a,n,i,max,min,sredno,otg;
    cin>>n;
    for(i=1;i<=n;i++)
    {
                     cin>>a;
       if(max<a) max=a;
       if((a<max) && (a>min)) sredno=a;
       if((a<max)&& (a<sredno)&& (min<a)) min=a;
         if(n==2) otg=max+1;
         if(n==4) otg=max+sredno+min+1;
         if(n==5) otg=max+min+sredno+a+1;
    }
    otg=max+sredno+1;
   cout<<otg<<endl;
return 0;
}
        
    
