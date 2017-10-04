#include<iostream>
#include<fstream>
using namespace std;
int used[3][14][33];
int m,d,p,t,n,mx;
void go(int mo,int da,int pe,int ti)
{
    int year=2013;
    while(ti!=0)
    {
        ti--;
        //cout<<ti<<endl;
        da--;
        if(da==0)
        {
            mo--;
            if(mo==0)year--,mo=12;
            if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12)da=31;
            else if(mo==4||mo==6||mo==9||mo==11)da=30;
            else if(year==2012&&mo==2)da=29;
            else if(year==2013&&mo==2)da=28;
        }
        used[year-2011][mo][da]+=pe;
        //cout<<year<<" "<<mo<<" "<<da<<" "<<pe<<" "<<used[year-2011][mo][da]<<endl;
    }
}
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>m>>d>>p>>t;
        go(m,d,p,t);
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=12;j++)
        {
            for(int k=1;k<=31;k++)mx=max(mx,used[i][j][k]);
        }
    }
    fout<<mx<<endl;
}
