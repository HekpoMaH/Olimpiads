#include<bits/stdc++.h>
using namespace std;
int n,m;
int col[100009];
int dances[100009][4],br,fl[4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fl[1]=fl[2]=fl[3]=0;
        cin>>dances[i][1]>>dances[i][2]>>dances[i][3];
        if(col[dances[i][1]]==1)col[dances[i][2]]=2,col[dances[i][3]]=3;
        else if(col[dances[i][1]]==2)col[dances[i][2]]=1,col[dances[i][3]]=3;
        else if(col[dances[i][1]]==3)col[dances[i][2]]=1,col[dances[i][3]]=2;
        else if(col[dances[i][2]]==1)col[dances[i][1]]=2,col[dances[i][3]]=3;
        else if(col[dances[i][2]]==2)col[dances[i][1]]=1,col[dances[i][3]]=3;
        else if(col[dances[i][2]]==3)col[dances[i][1]]=1,col[dances[i][3]]=2;
        else if(col[dances[i][3]]==1)col[dances[i][1]]=2,col[dances[i][2]]=3;
        else if(col[dances[i][3]]==2)col[dances[i][1]]=1,col[dances[i][2]]=3;
        else if(col[dances[i][3]]==3)col[dances[i][1]]=1,col[dances[i][2]]=2;
        else col[dances[i][1]]=1,col[dances[i][2]]=2,col[dances[i][3]]=3;
    }
    for(int i=1;i<=n;i++)cout<<col[i]<<" ";
    cout<<"\n";
}
/*
6 3
1 2 3
2 4 6
1 4 5
*/
