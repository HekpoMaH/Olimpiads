#include<iostream>
using namespace std;
long a[1000000],m,i,n,k,br,r,win;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    cin>>a[i];   
    a[k]=0; br=1; i=k;          
       while(br!=n)
       {                    
          if(i+i-1>n) {a[i+i-1-n]=0;br++;i=i+i-1-n;}
          else
          if(i+i-1<=n) {a[i+i-1]=0;br++;i=i+i-1;}
       }
    for(i=1;i<=n;i++)
    if(a[i]!=0){win=i;break;}
    cout<<win<<endl;
    return 0;
}  
