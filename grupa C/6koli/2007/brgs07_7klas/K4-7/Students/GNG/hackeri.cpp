#include <iostream>
#include <string>

using namespace std;

int main()
{
    char a[17000];
    cin>>a;
    int n=strlen(a);
    if(n==1) cout<<a[0]<<a[0];
    else
    {
        int br=0,x,y,br1=0;
        int k;
        for(int i=n-1;i>=0;i--)
        {                     br=0;
                
                for(int j=i;j<(i+n-1)/2;j++)
                {
                        if(a[j]==a[n-1-j+i])br++;
                       
                        
                }
                if(((i+n-1)/2)%2!=0){if(a[(i+n-1)/2]==a[n-(i+n-1)/2])br++;}
                if(br==(i+n-1)/2-i){k=i;}
                        
       }
       
        for(int i=0;i<n;i++)
        cout<<a[i];
        if(k!=0||a[0]!=a[n-1])
        for(int i=k;i>=0;i--)
        cout<<a[i];
        
        else
        {     for(int i=n-1;i>=0;i--)
        {
                br=0;
                
                for(int j=i;j<=(i+n-1)/2;j++)
                {
                        if(a[j]==a[n-1-j+i])br++;
                       
                        
                }
                
                
                
                if(br!=(i+n-1)/2-i){k=i;break;}
                        
       }
       
        if(k!=0){
        for(int i=k-1;i>=0;i--)
        cout<<a[i];
        }
        else cout<<a[0];
        }
        }
        
        cout<<"\n";



 return 0;
}
