#include<bits/stdc++.h>
using namespace std;
int n;
struct rec
{
    int mix,miy,mx,my;
};
rec r[109];
int xses[209],yses[209],br,br2;
bool chek(int x1,int x2,int y1,int y2)
{
    for(int i=1;i<=n;i++)
    {
        if(r[i].mix<=x1&&r[i].mx>=x2&&r[i].miy<=y1&&y2<=r[i].my)return true;
    }
    return false;
}
int main()
{
    int a,b,c,d;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d;
        r[i].mix=min(a,c);
        r[i].mx=max(a,c);
        r[i].miy=min(b,d);
        r[i].my=max(b,d);
        xses[++br]=a;xses[++br]=c;
        yses[++br2]=b,yses[++br2]=d;
    }
    sort(xses+1,xses+br+1);
    br=unique(xses+1,xses+br+1)-&xses[0]-1;
    sort(yses+1,yses+br2+1);
    br2=unique(yses+1,yses+br2+1)-&yses[0]-1;

    int are=0;
    for(int i=2;i<=br;i++)
    {
        for(int j=2;j<=br2;j++)
        {
            if(chek(xses[i-1],xses[i],yses[j-1],yses[j])==true)
            {
                are+=((xses[i]-xses[i-1])*(yses[j]-yses[j-1]));
                //cout<<"adding rect "<<xses[i-1]<<" "<<yses[j-1]<<" "<<xses[i]<<" "<<yses[j]<<" area is "<<are<<endl;
            }
        }
    }
    cout<<are<<endl;
}
