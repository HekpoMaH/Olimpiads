#include<iostream>
using namespace std;
int main() 
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n*m-(n-1);i++)cout<<"*"<<" ";
    cout<<endl;
    int r=m-2;
    for(int i=1;i<=r;i++)
    {
            for(int j=1;j<=n+1;j++){
                                    cout<<"*";
                                    for(int k=1;k<=m+(m-3);k++)cout<<" ";
                                    }
            cout<<endl;
    }
    for(int i=1;i<=n*m-(n-1);i++)cout<<"*"<<" ";
    cout<<endl;           
    system("pause");
    return 0;
}
