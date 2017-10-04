#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n;
int a[1009][1009],col[1009],row[1009],used[1009][1009];
char ch;
int l1=1,l2=1;
vector<pair<int,int> >ans;
vector<int> rnp;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ch;
            if(ch=='E')a[i][j]=1;
            else row[i]=col[j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(row[i]==0)l1=0;
        if(col[i]==0)l2=0;
    }
    //cout<<row[1]<<endl;
    if(l1==0&&l2==0)
    {
        cout<<-1<<endl;return 0;
    }
    if(l1==1){for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)if(a[i][j]==0){cout<<i<<" "<<j<<endl;break;}

    }return 0;}
    if(l2==1)
    {//cout<<"W"<<endl;
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)if(a[i][j]==0){cout<<i<<" "<<j<<endl;break;}

        }
    }
}

