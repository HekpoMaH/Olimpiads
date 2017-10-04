#include<bits/stdc++.h>
using namespace std;
int n;
struct point
{
    int x,y;
};
vector<point> v;
point xx;
int mn=9999999;
bool cmp(point a,point b)
{
    if(a.x<b.x)return true;
    if(a.x>b.x)return false;
    if(a.y<b.y)return true;
    return false;
}
void calc()
{
    int cr=0;
    for(int i=1;i<v.size();i++)
    {
        cr+=abs(v[i].x-v[i-1].x)+abs(v[i].y-v[i-1].y);
    }
    mn=min(mn,cr);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>xx.x>>xx.y;
        v.push_back(xx);
    }
    //sort(v.begin(),v.end());
    do
    {
        calc();
    }while(next_permutation(v.begin(),v.end(),cmp));
    cout<<mn<<endl;
}
