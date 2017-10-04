#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
    cin>>n;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    int l=0,c,br=0;
    int j=0;
    for(i=1;i<=n;i++)
    {          
            j=abs(a[i]);
            while(j!=0)
            {
                         c=j%10;
                         if(abs(a[i])%c>0){l=1;}
                         j=j/10;
            }
            if(l==0){
                     if(i<n)cout<<a[i]<<" ";
                     else cout<<a[i]<<endl;
                     br=1;
                     } 
            l=0;
    }
    if(br==0)cout<<"No"<<endl;
    system("pause");
    return 0;
}
