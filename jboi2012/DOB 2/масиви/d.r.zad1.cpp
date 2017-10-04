#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int i,n,d;
    cin>>n;
    for(i=0;i<=n-1;i++)
    {
         cin>>a[i];
    }
    int l=0,br=0;
    i=0;
    
    do
    {
          br=0;
        d=2;
        do
           {
            
                if(a[i]%d==0)
                {
                             br=br+1;
                }
                d++;
                }while(d<a[i]);
                if(br==0)
               {
                          l=l+1;
               }
                
        
        i++;
    }
    while(l==0&&i<=n-1);
    if(l==0){cout<<"NO"<<endl;}
    else cout<<a[i-1]<<endl;    
    system("pause");
    return 0;
}
