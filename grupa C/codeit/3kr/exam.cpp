#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int a,n,m,fn,t,mx,brt;
struct student
{
    int fn,t;
};
student x[1025];
bool cmp(student x, student y)
{
    if(x.fn<y.fn)return true;
    return false;
}

int main()
{
    ifstream fin ("exam.03.in");
    ofstream fout ("exam.out");
    fin>>n>>m;
    for(int i=0;i<m+n;i++)
    {
        fin>>x[i].fn>>x[i].t;
    }
    sort(x,x+n+m,cmp);
    brt=x[0].t;
    //for(int i=0;i<m+n;i++)
    //{
        //cout<<x[i].fn<<" "<<x[i].t<<endl;
    //}
    //cout<<x[0].fn<<endl;
    for(int i=1;i<m+n;i++)
    {
        //cout<<brt<<endl;
        if(x[i].fn==x[i-1].fn)brt+=x[i].t;
        if(x[i].fn!=x[i-1].fn||i==m+n-1)
        {
            
            if(brt>=119)fout<<x[i-1].fn<<endl;
            brt=x[i].t;
        }
    }
    return 0;
}
