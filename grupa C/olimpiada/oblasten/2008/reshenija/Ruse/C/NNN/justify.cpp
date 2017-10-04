#include <iostream>
using namespace std;
int main()
{
    char c1[512][64],c;
    int i,j,k,m,n,a[512][3];
    cin>>n;
    int p=0;
    for(i=1;i<=512;i++)
    {a[i][1]=0;a[i][2]=0;}
    cin.get(c);
    for (;;)
    {
    cin.get(c);
    if (c=='\n') p++;
    if ((c!=' ' && c!='\n') || (c==' ' && c1[p+1][a[p+1][1]]!=' ')) 
       {a[p+1][1]++;c1[p+1][a[p+1][1]]=c;if (c==' ') a[p+1][2]++;}
    if (p==n) break; 
    }
    int f,g,d,o=0;
    for (i=1;i<=n;i++)
    {
    f=(60-a[i][1]+a[i][2])/a[i][2];
    g=(60-a[i][1]+a[i][2])%a[i][2];
    o=0;
    for (j=1;j<=a[i][1];j++)
        {if (c1[i][j]!=' ') cout<<c1[i][j]; else
        {o++;for (d=1;d<=f;d++) cout<<' ';if (o<=g) cout<<' ';}}
    cout<<endl;   
    }
return 0;
}
