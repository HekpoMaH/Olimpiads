#include<iostream>
#include<fstream>
using namespace std;
struct dot
{
    double x,y;
};
long long br;
int n;
dot a[12],m[12];
int used[12],fl;
void solve(int pos)
{
    if(pos>=n)
    {
        fl=1;
        if(m[1].x!=0&&m[1].y!=0)fl=0;
        for(int i=1;i<n;i++)if(m[i].x!=m[i+1].x&&m[i].y!=m[i+1].y){fl=0;break;}
        if(m[n].x!=0&&m[n].y!=0)fl=0;
        if(fl==1)br++;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(used[i]==0)
            {
                used[i]=1;
                m[pos+1]=a[i];
                solve(pos+1);
                used[i]=0;
            }
        }
    }
}
int main()
{
    ifstream fin ("connect.in");
    ofstream fout("connect.out");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i].x>>a[i].y;
    }
    solve(0);
    fout<<br<<endl;
    return 0;
}