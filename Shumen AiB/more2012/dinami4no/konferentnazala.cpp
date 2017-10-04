#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ss
{
    int x,y,c;
};
vector<ss> ots;
vector<ss> ans;
int n,xx,yy,m;
bool cmp(ss a,ss b)
{
    if(a.y<b.y)return true;
    if(a.y>b.y)return false;
    if(a.x<b.x)return true;
    return false;
}
ss nss;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>xx>>yy;
        if(xx>yy)swap(xx,yy);
        nss.x=xx;nss.y=yy;nss.c=1;
        ots.push_back(nss);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>xx>>yy;
        if(xx>yy)swap(xx,yy);
        nss.x=xx;nss.y=yy;nss.c=2;
        ots.push_back(nss);
    }
    sort(ots.begin(),ots.end(),cmp);
    /*for(int i=0;i<ots.size();i++)
    {
        cout<<ots[i].first<<" "<<ots[i].second<<endl;
    }*/
    ans.push_back(ots[0]);
    int fl,fl2,dc=-1;
    for(int i=1;i<ots.size();i++)
    {
        fl=1;fl2=0;
        for(int j=ans.size()-1;j>=0;j--)
        {
            if(ots[i].x<=ans[j].y){fl=0;break;}
            if(ans[j].c!=dc)fl2=1;
        }
        if(fl==1&&fl2==1)ans.push_back(ots[i]), dc=ots[i].c;
    }
    int sum1=0,sum2=0;
    //cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)if(ans[i].c==1)sum1+=ans[i].y-ans[i].x+1;else sum2+=ans[i].y-ans[i].x+1;
    cout<<sum1<<" "<<sum2<<endl;
    return 0;
}