#include<iostream>
using namespace std;
struct to4ka
{
    int x,y;
    char name;
};
int orient(int ax,int ay,int bx,int by,int cx,int cy)
{
    return (ay-by)*cx+(bx-ax)*cy+ax*by-bx*ay;
}
//char ans[30][3];
to4ka t[30];
int l,n,br;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t[i].name>>t[i].x>>t[i].y;
    }
    for(int a=0;a<n;a++)
    {
        for(int b=a+1;b<n;b++)
        {
            for(int c=b+1;c<n;c++)
            {
                if(orient(t[a].x,t[a].y,t[b].x,t[b].y,t[c].x,t[c].y)!=0)
                {
                    //cout<<orient(t[a].x,t[a].y,t[b].x,t[b].y,t[c].x,t[c].y)<<endl;
                    cout<<t[a].name<<" "<<t[b].name<<" "<<t[c].name<<endl;l=1;
                }
            }
        }
    }
    if(l==0)cout<<"No triangles."<<endl;
    return 0;
}