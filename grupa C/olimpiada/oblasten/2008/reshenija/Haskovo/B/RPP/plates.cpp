#include <iostream>

using namespace std;

int main()
{
    int m, n;
    //cin>>m>>n;
    m=3;n=2;
    char s[1000][30];
    int i, k=0, l=0, a;
    for (i =0; i<m*n; i++)
    {   cin>>s[k][l]; l++; if (l==n) {l=0; k++;} if (k>=m) goto az; }
int d[1000][30][30];
/*
for (i=0; i<m; i++)
for (k=0; k<n; k++)
for (l=0; l<n; l++)
{
    d[i][k][l] = s[i][k][l];

 cout<<d[i][k][l]<<"  ";
    }*/
    
    
    
cout<<endl;

az:   cout<<"incorrect entry";
    return 0;
}
