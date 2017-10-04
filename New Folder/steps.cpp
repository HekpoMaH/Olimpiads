#include<iostream>
using namespace std;
int main()
{
    int n,h,l;
    char ch;
    cin>>n>>h>>l;
    cin>>ch;
    int r=l-1;
    for(int i=1;i<=n*(h-1)-1;i++)
    {
            if(i==1){for(int j=1;j<=l+1;j++)cout<<ch;cout<<endl;}
            if(i%(h-1)==0){
                           cout<<ch;
                           for(int j=1;j<=r;j++)cout<<" ";
                           for(int j=1;j<=l+1;j++)cout<<ch;
                           r=r+l;
                           cout<<endl;
                           }
            else{
                 cout<<ch;
                 for(int j=1;j<=r;j++)cout<<" ";
                 cout<<ch;
                 cout<<endl;
                 }
            if(i==n*(h-1)-1){for(int j=1;j<=n*l+1;j++)cout<<ch;cout<<endl;}
    }
    system("pause");
    return 0;
}        
