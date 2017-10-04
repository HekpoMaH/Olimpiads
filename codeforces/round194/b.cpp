#include<bits/stdc++.h>
using namespace std;
int a[9][3],br1,br2;
set<pair<int,int> >pts;
set<int> x,y;
int main()
{
    int n=8;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
        pts.insert(make_pair(a[i][1],a[i][2]));
        x.insert(a[i][1]);y.insert(a[i][2]);
    }
    if(x.size()!=3||y.size()!=3){cout<<"ugly"<<endl;return 0;}
    for(set<int>::iterator it=x.begin();it!=x.end();it++)
    {
        br1++;br2=0;
        for(set<int>::iterator it2=y.begin();it2!=y.end();it2++)
        {
            br2++;
            if(!(br1==2&&br2==2))
            {
                if(pts.find(make_pair(*it,*it2))==pts.end()){cout<<"ugly"<<endl;return 0;}
            }
        }
    }cout<<"respectable"<<endl;
}

