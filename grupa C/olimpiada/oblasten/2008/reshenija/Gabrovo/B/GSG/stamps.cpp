#include<iostream>
#include<conio.h>
using namespace std;
int s,n,a[3010];
int st=0;
int x=3010,pos;
int maximal;
void input()
{
     cin>>s>>n;
     for(int inp=0;inp<n;inp++){cin>>a[inp];}
}
void getmax()
{
     int mx=0;
     for(int c=0;c<n;c++)
     {if(a[c]>mx){mx=a[c];pos=c;}}
     maximal=mx;a[pos]=0;
}
void dothemath()
{
     getmax();
     while(s!=0)
     {       
             if(s<maximal){getmax();}
             else{s-=maximal;st++;}
             }
}
                    
                        
int main()
{
    input();
    dothemath();    
    cout<<st<<endl;
    return 0;
}
