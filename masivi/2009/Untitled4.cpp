#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n<m)
    {
           int in=abs(n-(m-n)),h=m;
           for(int i=1;i<=m-(n-1);i++)
           {
                   for(int j=1;j<=in;j++)cout<<" ";
                   for(int j=1;j<=h;j++)cout<<"1 ";
                   in++;
                   h--;
                   cout<<endl;
           }
           int g=1;
           in-=2;
           for(int i=1;i<=n;i++)
           {
                   for(int j=1;j<=in;j++)cout<<" ";
                   for(int j=1;j<=g;j++)cout<<"0 ";
                   for(int j=1;j<=h;j++)cout<<"1 ";
                   for(int j=1;j<=g;j++)cout<<"0 ";
                   cout<<endl;
                   in--;
                   h--;
                   g++;
           }
    }
    if(n>=m)
    {
            
            int in2=2*(n-1)+1;
            int in=n-1;
            int z=1;
            for(int i=1;i<=n-m-1;i++)
            {
                    for(int j=1;j<=in;j++)cout<<" ";
                    for(int j=1;j<=z;j++)cout<<"0 ";
                    for(int j=1;j<=in2-1;j++)cout<<" ";
                    for(int j=1;j<=z;j++)cout<<"0 ";
                    in--;
                    in2-=2;
                    z++;
                    cout<<endl;
            }
            int h=m;
            for(int i=1;i<=m+1;i++)
            {
                 
                    for(int j=1;j<=in;j++)cout<<" ";
                    for(int j=1;j<=z;j++)cout<<"0 ";
                    for(int j=1;j<=h;j++)cout<<"1 ";
                    for(int j=1;j<=z;j++)cout<<"0 ";
                    in--;
                    z++;
                    h--;
                    cout<<endl;
                    }
                 }
    system("pause");
    return 0;
}
