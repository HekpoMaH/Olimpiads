#include<iostream>
#include<string>
using namespace std;
int main()
{
    int l,m,k,i,y;
    char a[25];
    
    m=0;
    k=0;
    
    cin>>l;
    
    for (i=1;i<=l;i++)
    {
        y=1;
        while (a[y]!='\n')
        {
              cin>>a[y];
              y++;
        }
        
        for (int j=1;j<=y;j++)
        {
            if (a[j]=='C') k++;
            if (a[j]=='A') k++;
            if (a[j]=='T') k++;
            
            if (a[j]=='G') m++;
            if (a[j]=='P') m++;
            if (a[j]=='I') m++;
        }
        if (k>m)          cout<<"CAT"<<endl;
        if (k==m)         cout<<"GPI"<<endl;
        if (k<m)          cout<<"CAT-GPI"<<endl;
        if (k==0 && m==0) cout<<"UFO"<<endl;
        
    }
    
    system("pause");
    return 0;
}             
