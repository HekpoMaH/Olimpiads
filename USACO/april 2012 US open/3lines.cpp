#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
long long xs[50000],ys[50000],n;
//vector<long long>yms;
vector<long long>xms;
//pair<long long,long long>camera1,camera2,camera3;
void doxy()
{
    ofstream fout("3lines.out");
    int last=xs[1],br=1;
    for(int i=2;i<=n;i++)
    {
        if(xs[i]!=last)
        {
            xms.push_back(br);
            br=1;
        }
        else br++;
        last=xs[i];
    }
    last=ys[1];br=1;
    for(int i=2;i<=n;i++)
    {
        if(ys[i]!=last)
        {
            xms.push_back(br);
            br=1;
        }
        else br++;
        last=ys[i];
    }
    br=0;
    long long sum=0;
    sort(xms.begin(),xms.end());
    for(int i=xms.size()-1;i>=0;i--)
    {
        sum+=xms[i];
        br++;
        if(br==3)break;
    }
    if(sum>=n)fout<<1<<endl;
    else fout<<0<<endl;
    return;
}
int main()
{
    ifstream fin("3lines.in");
    
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>xs[i]>>ys[i];
    }
    sort(xs+1,xs+n+1);
    sort(ys+1,ys+n+1);
    doxy();
    return 0;
}