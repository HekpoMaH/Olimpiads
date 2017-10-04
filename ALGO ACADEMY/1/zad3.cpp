#include<iostream>
using namespace std;
double f,s;
struct prav
{
    double mnx,mny,mxx,mxy;
};
prav p[105];
double x,y;
double br,t1x,t1y,t2x,t2y;
int main()
{
    cin>>f>>s;
    for(int i=1;i<=f;i++)
    {
        cin>>t1x>>t1y>>t2x>>t2y;
        p[i].mnx=min(t1x,t2x);
        p[i].mny=min(t1y,t2y);
        p[i].mxx=max(t1x,t2x);
        p[i].mxy=max(t1y,t2y);
    }
    for(int i=1;i<=s;i++)
    {
        //cout<<i<<endl;
        cin>>x>>y;
        for(int j=1;j<=f;j++)
        {
            //cout<<p[j].mnx<<" "<<p[j].mny<<" "<<p[j].mxx<<" "<<p[j].mxy<<endl;
            if(x>p[j].mnx&&x<p[j].mxx&&y>p[j].mny&&y<p[j].mxy){br++;break;}
        }
    }
    cout<<br<<endl;
    return 0;
}
/*1 3
39 15 -78 95*/