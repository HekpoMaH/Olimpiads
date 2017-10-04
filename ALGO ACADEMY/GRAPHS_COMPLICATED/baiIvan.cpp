#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int n,m;
struct point
{
    int x,y;
};
double a[100][100],ff[100][100],mn=999999;
vector<point> pp;
point p;
int aaa[100];
int main()
{
    cin>>m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {aaa[i]=i;
        cin>>p.x>>p.y;
        pp.push_back(p);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=sqrt((pp[i].x-pp[j].x)*(pp[i].x-pp[j].x)+(pp[i].y-pp[j].y)*(pp[i].y-pp[j].y));
        }
    }
    do
    {
        double sum=0;
        sum+=sqrt(pp[aaa[1]-1].x*pp[aaa[1]-1].x+pp[aaa[1]-1].y*pp[aaa[1]-1].y);
        for(int i=1;i<n;i++)
        {
            sum+=a[aaa[i]-1][aaa[i+1]-1];
        }
        sum+=sqrt(pp[aaa[n]-1].x*pp[aaa[n]-1].x+pp[aaa[n]-1].y*pp[aaa[n]-1].y);
        mn=min(mn,sum);
    }while(next_permutation(aaa+1,aaa+n+1));
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)(mn*m)<<endl;
}
