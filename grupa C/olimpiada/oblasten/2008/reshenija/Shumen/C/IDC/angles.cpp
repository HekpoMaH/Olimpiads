#include<iostream>
using namespace std;
int n,a[1024][1024],k;
void read()
{
    int i,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        cin>>a[i][j];
    }
}
int tek(int i,int j)
{
    int p,a1,a2,a3,a4,a5=0;
    a1=a[i][j];
    a2=a[i][j];
    a3=a[i][j];
    a4=a[i][j];
    for(p=1;p<=k;p++)
    {
       
        if(i+p<=n&&j+p<=n){a3+=a[i+p][j];a3+=a[i][j+p];}
       
    }
    if(a3>a5)a5=a3;
    
    return  a5;
}
void out()
{
    int i,j,max=0,m,nai,posle;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            m=tek(i,j);
            if(m>max){max=m;nai=i;posle=j;}
        }
    }
    cout<<nai<<' '<<posle<<endl;
 
}
            
int main()
{
   read();
   out();
  
            
return 0;
}
