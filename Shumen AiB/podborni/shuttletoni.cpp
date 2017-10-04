#include<iostream>
#include<string>
using namespace std;
typedef int normal;
typedef unsigned long long big;
const normal MAXN=2000;
normal r,c,a,b,s;
char matrix[MAXN][MAXN];
big Hrow[MAXN][MAXN],Hmatrix[MAXN][MAXN],HRmatrix[MAXN][MAXN];
big power[MAXN*MAXN];
big p;
void read()
{
    normal i,j;
    cin>>r>>c;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        cin>>matrix[i][j];
}
void initialisePower()
{
    normal i;
    p=101;
    power[1]=p;
    for(i=2;i<=r*c;i++)
    power[i]=power[i-1]*p;
}
big extractReversedHash(normal i,normal l,normal r)
{
    if(l==1)return Hrow[i][r];
    return Hrow[i][r]-Hrow[i][l-1]*power[r-l+1];
}
void initialiseHash()
{
    int i,j;
    // initialise hash for rows
    for(i=1;i<=r;i++)
    {
        Hrow[i][1]=matrix[i][1]-'A'+1;
        for(j=2;j<=c;j++)
        Hrow[i][j]=Hrow[i][j-1]*p+(matrix[i][j]-'A'+1);
    }
    // initialise straight hash for matrix
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        {
            if(i==1)Hmatrix[i][j]=Hrow[i][j];
            else Hmatrix[i][j]=Hmatrix[i-1][j]*power[j]+Hrow[i][j];
        }
    // initialise reversed hash for matrix
    for(i=r;i>=1;i--)
        for(j=c;j>=1;j--)
        {
            if(i==r)HRmatrix[i][j]=extractReversedHash(i,j,c);
            else HRmatrix[i][j]=HRmatrix[i+1][j]+extractReversedHash(i,j,c)*power[(c-j+1)*(r-i)];
        }
    for(i=1;i<=r;i++){
       for(j=1;j<=c;j++){
          cout<<HRmatrix[i][j]<<" ";
       }
       cout<<"\n";
    }
}
big find(normal i1,normal j1,normal i2,normal j2)
{
    if(i1==1&&j1==1)return Hmatrix[i2][j2];
    else return HRmatrix[i1][j1];
}
void solve()
{
    normal i,j;
    a=r;
    b=c;
    s=0;
    // search for b
    for(i=1;i<c;i++)
    if(find(1,1,r,c-i)==find(1,i+1,r,c))
    {
        b=i;
        break;
    }
    // search for a and s
    for(i=1;i<=r;i++)
        for(j=0;j<b;j++)
        if(find(1,1,r-i,c-j)==find(i+1,j+1,r,c))
        {
            a=i;
            s=j;
            return;
        }
}
void print()
{
    //cout<<a<<' '<<b<<' '<<s<<endl;
}
int main()
{
    read();
    initialisePower();
    initialiseHash();
    solve();
    print();
}
