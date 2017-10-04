#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,pair<int,int> >m;
string s;
long long dx,dy,ans,x,y,xx,yy,a,b,bx,by;
int main()
{
    cin>>a>>b;
    cin>>s;
    m['U']=make_pair(0,1);
    m['D']=make_pair(0,-1);
    m['R']=make_pair(1,0);
    m['L']=make_pair(-1,0);
    dx=dy=0;
    for(int i=0;i<s.size();i++)
    {
        dx+=m[s[i]].first;dy+=m[s[i]].second;
    }
    if(a==0&&b==0){cout<<"Yes"<<endl;return 0;}
    x=y=0;
    for(int i=0;i<s.size();i++)
    {
        //cout<<i<<endl;
        x+=m[s[i]].first;y+=m[s[i]].second;
        xx=a-x;
        yy=b-y;
        //cout<<x<<" "<<y<<" ";
        bool bx=0,by=0;
        if(dx==0)
        {
            if(xx!=0)continue;
            bx=1;
        }
        if(dy==0)
        {
            if(yy!=0)continue;
            by=1;
        }
        //cout<<bx<<" "<<by<<endl;
        if(bx==1&&by==1){cout<<"Yes"<<endl;return 0;}
        if(bx||by)
        {
            //if(xx==0||y==0)continue;
            if(bx)
            {
                if(yy/dy>=0&&yy%dy==0){cout<<"Yes"<<endl;return 0;}
            }
            if(by)if(xx/dx>=0&&xx%dx==0){cout<<"Yes"<<endl;return 0;}
            continue;
        }
        if(xx/dx>=0&&xx/dx==yy/dy&&xx%dx==0&&yy%dy==0){cout<<"Yes"<<endl;return 0;}
    }
    cout<<"No"<<endl;
}
