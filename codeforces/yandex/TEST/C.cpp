#include<fstream>
#include<string>
#include<iostream>
using namespace std;
string a;
int dp[11][4],fo1,fo2,fo3,fo4,l;
int iwan(int dig,int pos)
{
    int haha=pos;
    for(int i=pos;i<8;i++)
    {
        if(dig==1&&a[i]=='1')return i+1;
        if(dig==2&&a[i]=='2')return i+1;
        if(dig==3&&a[i]=='3')return i+1;
        if(dig==4&&a[i]=='4')return i+1;
    }
    return 99999;
}
int main()
{
    ifstream fin("number.in");
    ofstream fout("number.out");
fin>>a;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                for(int d=1;d<=3;d++)
                {

                    //if(i==j||i==k||i==d||j==k||j==d||k==d)contin;
                    int tr=0;
                    tr=iwan(i,tr);if(tr==99999)continue;tr=iwan(j,tr);if(tr==99999)continue;tr=iwan(k,tr);if(tr==99999)continue;tr=iwan(d,tr);
                    if(tr==99999)continue;
                    fout<<i<<j<<k<<d<<endl;
                    //cout<<i<<j<<k<<d<<endl;
                    return 0;
                }
            }
        }
    }
    //cout<<dp[a.size()][4]<<endl;
}
