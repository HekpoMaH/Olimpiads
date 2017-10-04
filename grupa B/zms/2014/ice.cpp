#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
char s[5001][5001];
short int sum[5001][5001];
struct qel
{
    short int x,y,vr;
    qel(){};
    qel(short int _x,short int _y,short int _vr)
    {
        x=_x;y=_y;vr=_vr;
    }
};
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    int br=0,l=1;
    queue<qel>q;
    memset(sum,0,sizeof(sum));
    for(int i=2;i<n;i++)
        for(int j=1;j<n-1;j++)
        {
            if(s[i-1][j]-'0'+s[i+1][j]-'0'+s[i][j-1]-'0'+s[i][j+1]-'0'<=2&&s[i][j]=='1')
            {
                q.push(qel(i,j,1));

            }
            sum[i][j]=s[i-1][j]-'0'+s[i+1][j]-'0'+s[i][j-1]-'0'+s[i][j+1]-'0';
        }
    int ans=0;
    br=1;
    int i1,j;
    while(!q.empty())
    {
        //l=0;toc.clear();
        if(q.front().vr==br)
        {
            int i=q.front().x,j=q.front().y;
            s[i][j]='0';q.pop();
            if(s[i-1][j]=='1'&&sum[i-1][j]>2)
            {
                sum[i-1][j]--;
                if(sum[i-1][j]==2)q.push(qel(i-1,j,br+1));
            }
            if(s[i][j-1]=='1'&&sum[i][j-1]>2)
            {
                sum[i][j-1]--;
                if(sum[i][j-1]==2)q.push(qel(i,j-1,br+1));
            }
            if(s[i+1][j]=='1'&&sum[i+1][j]>2)
            {
                sum[i+1][j]--;
                if(sum[i+1][j]==2)q.push(qel(i+1,j,br+1));
            }
            if(s[i][j+1]=='1'&&sum[i][j+1]>2)
            {
                sum[i][j+1]--;
                if(sum[i][j+1]==2)q.push(qel(i,j+1,br+1));
            }
        }
        else br++;
    }
    cout<<br<<"\n";
}
