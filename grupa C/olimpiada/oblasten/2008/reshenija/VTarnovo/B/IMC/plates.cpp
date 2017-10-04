#include<iostream>

using namespace std;

int main()
{
    int a[1000][30],i,j,b[1000][30],br,c[1000][30];
    
    cin>>m>>n;
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    
    for(i=0;i<1000;i++)
        for(j=0;j<30;j++)
             b[i][j]=0;

    for(i=0;i<1000;i++)
        for(j=0;j<30;j++)
             b[i][j]=0;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            {
             c[i][j]=c[i][j]*10+a[i][j]%10
                      
    
    system("pause");
    
    return 0;
}
