#include<iostream>
#include<fstream>
using namespace std;
int n;
int a[3500][3500],x1,y1,x2,y2,br,mxy,mny=20000,mxx,mnx=20000;
int main()
{
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>x1>>y1>>x2>>y2;
        y1--;x2--;
        if(x1+1750>mxx)mxx=x1+1750;if(x2+1750>mxx)mxx=x2+1750;
        if(x1+1750<mnx)mnx=x1+1750;if(x2+1750<mnx)mnx=x2+1750;
        if(y1+1750>mxy)mxy=y1+1750;if(y2+1750>mxy)mxy=y2+1750;
        if(y1+1750<mny)mny=y1+1750;if(y2+1750<mny)mny=y2+1750;
        for(int j=x1+1750;j<=x2+1750;j++)for(int k=y2+1750;k<=y1+1750;k++){a[j][k]=1;}
    }
    for(int i=mnx;i<=mxx;i++)for(int j=mny;j<=mxy;j++)if(a[i][j]==1)br++;
    fout<<br<<endl;
    return 0;
}
