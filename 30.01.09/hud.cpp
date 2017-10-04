#include<iostream>
using namespace std;
int main()
{
    int kod,n;
    char ch;
    cin>>kod>>n>>ch;
    if(kod==0)
              {//house
              int n1=n+2;
               for(int i=1;i<=(n1*2-1)/2;i++)cout<<" ";
              cout<<ch<<endl;
              for(int i=2;i<=n1-1;i++)
              {
                      for(int k=1;k<=n1-i;k++)cout<<" ";
                      cout<<ch;
                      for(int k=1;k<=i*2-3;k++)cout<<" ";
                      cout<<ch;
                      cout<<endl;
              }
              for(int j=1;j<=n1;j++)cout<<ch<<" ";
              cout<<endl;
              //sqear
              int r=n-2;
              for(int i=1;i<=r;i++)
              {
                      cout<<"  "<<ch;
                      for(int g=1;g<=2*n-3;g++)cout<<" ";
                      cout<<ch<<endl;
                      
              }
              cout<<"  ";
              for(int i=1;i<=n;i++)cout<<ch<<" ";
              cout<<endl;
              }
    if(kod==1)
              {
              //elha  
              for(int i=1;i<=(n*2-1)/2;i++)cout<<" ";
              cout<<ch<<endl;
              for(int i=2;i<=n-1;i++)
              {
                      for(int k=1;k<=n-i;k++)cout<<" ";
                      cout<<ch;
                      for(int k=1;k<=i*2-3;k++)cout<<" ";
                      cout<<ch;
                      cout<<endl;
              }
              for(int j=1;j<=n;j++)cout<<ch<<" ";
              cout<<endl;
              int r=n/2;
              for(int l=1;l<=r;l++)
              {
                      for(int i=1;i<=(n*2-1)/2;i++)cout<<" ";
                      cout<<ch<<endl;
              }
              }
    system("pause");
    return 0;
}        
