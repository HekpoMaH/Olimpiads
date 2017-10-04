#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int i,j,k;
    for(i=1;i<=n*m-n+1;i++){cout<<"*";}
    cout<<"\n";
    for(i=1;i<=m-2;i++)
    {
                       for(j=1;j<=n;j++)
                       {
                                        cout<<"*";
                                        for(k=1;k<=m-2;k++){cout<<" ";}
                       }
                       cout<<"*\n";
    }
    for(i=1;i<=n*m-n+1;i++){cout<<"*";}
    cout<<"\n";
    system("pause");
    return 0;
} 
