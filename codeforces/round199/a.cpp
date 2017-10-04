#include<iostream>
using namespace std;
int br[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        br[a]++;
    }
    if(br[5]!=0 || br[7]!=0)
    {
        cout<<-1;
        return 0;
    }
    if(br[2]<br[4] || br[1]<br[4])
    {
        cout<<-1;
        return 0;
    }
    br[2]-=br[4];
    br[1]-=br[4];
    if(br[6]!=br[2]+br[3] || br[6]!=br[1])
    {
        cout<<-1;
        return 0;
    }
    for(i=0;i<br[4];i++)
    cout<<"1 2 4\n";
    for(i=0;i<br[2];i++)
    cout<<"1 2 6\n";
    for(i=0;i<br[3];i++)
    cout<<"1 3 6\n";
}
