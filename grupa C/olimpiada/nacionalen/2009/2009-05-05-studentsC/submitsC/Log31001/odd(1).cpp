/*
TASK:odd
LANG:C++
*/
#include<iostream>
#include<string>
using namespace std;
int tt;
void read ()
{
    unsigned long long  s=0,sm,i;  
     for(i=1;i<=tt;i++)
     {
                       scanf("%d",&sm);
                       if(s==0)s=sm;
                       else s=s^sm;
                       
                       
     }
     printf("%d\n",s);
}
int main ()
{
    scanf("%d",&tt);
    read();
    
}
