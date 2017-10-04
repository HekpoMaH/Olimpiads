#include<iostream>
#include<algorithm>
using namespace std;
int a[51][51],b[51][51],na,nb,ma,mb;
string h;
int main()
{
    cin>>na>>ma;
    for(int i=1;i<=na;i++)
    {
        cin>>h;
        for(int j=1;j<=ma;j++)
        {
            a[i][j]=h[j-1]-'0';
        }
    }
    cin>>nb>>mb;
    for(int i=1;i<=nb;i++)
    {
        cin>>h;
        for(int j=1;j<=mb;j++)
        {
            b[i][j]=h[j-1]-'0';
        }
    }
    long long ms=0,xx,yy,s;
    for(int x=-50;x<=50;x++)//aa
    {
        for(int y=-50;y<=50;y++)
        {
            s=0;
            for(int i=1;i<=na;i++)
            {
                for(int j=1;j<=ma;j++)
                {
                    if(!(i+x>nb||j+y>mb||i+x<=0||j+y<=0)){s+=a[i][j]*b[i+x][j+y];}
                    //s+=a[i][j]*b[i+x][j+y];
                }
            }
            //if(x==50&&y==15)cout<<s<<endl;
            if(s>ms)ms=s,xx=x,yy=y;
        }
    }
    cout<<xx<<" "<<yy<<endl;
    return 0;
}