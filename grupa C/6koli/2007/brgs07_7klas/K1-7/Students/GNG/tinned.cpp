#include <iostream>

using namespace std;

int main()
{
    char a[102],b[102];
    cin>>a;
    cin>>b;
    int n=strlen(a);
    int m=strlen(b);
    char a1[102],b1[102];
    if(m>n)
    {for(int i=0;i<m-n;i++)
    {
            a1[i]==0;
    }
    for(int i=m-n;i<n;i++)
    {
            a1[i]=a[i-m-n];
    }
    for(int i=0;i<m;i++)
    {
            b1[i]=b[i];
    }
    }
    if(n>m)
    {for(int i=0;i<n-m;i++)
    {
            b[i]==0;
    }
    for(int i=n-m;i<m;i++)
    {
            b1[i]=a1[i-n-m];
    }
    for(int i=0;i<m;i++)
    {
            a1[i]=a[i];
    }
    }
    if(m==n)
    {for(int i=0;i<n;i++)
    {
            a1[i]=a[i];
    }
    for(int i=0;i<m;i++)
    {
            b1[i]=b[i];
    }
    }
    n=max(n,m);
    
    int k=0,x=0;
    for(int i=n-1;i>=0;i--)
    {
            if(a1[i]-'0'+b1[i]-'0'+k<10){a1[i]=a1[i]+b1[i]+k-'0';k=0;}
            else {a1[i]=(a1[i]+b1[i]-'0'-'0'+k)%10+'0';k=1;}
    }
    int p;
    cin>>p;
    if(k==1)
    {for(int i=n;i>=1;i--)
    {
            a1[i]=a1[i-1];
    }
    a1[0]='1';
    n++;
    }
 
    k=0;
    for(int i=n-1;i>=0;i--)
    {
            if((a1[i]-'0')*p+k<10){
                                  a1[i]=(a1[i]-'0')*p+k+'0';k=0;
                                  }
            else {
                x=((a1[i]-'0')*p+k)/10; a1[i]=((a1[i]-'0')*p+k)%10+'0';k=x;
                 }
    }
    if(k>0)cout<<k;
    for(int i=0;i<n;i++)
    cout<<a1[i];
    cout<<"\n";
    
                 
            
            
    
    
    
  

    
    
    
   
    return 0;
}
