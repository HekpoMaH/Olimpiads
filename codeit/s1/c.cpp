#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[1009][1009],used[1009],ans[1009],q1,q2,exm;
int s,x;
vector<int> v[159];
vector<int> rv[1059];
int main()
{
    freopen ( "movie.in" , "r" , stdin ) ;
    freopen ( "movie.out" , "w" , stdout ) ;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    //cout<<"Eeeeeeee"<<endl;
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        //cout<<i<<" "<<s<<endl;
        for(int j=1;j<=s;j++)
        {
            cin>>x;v[i].push_back(x);
            rv[x].push_back(i);
        }
    }
    memset(a,63,sizeof(a));
    exm=a[0][0];
    for(int i=1;i<=m;i++)a[i][i]=0;
    //cout<<"endread"<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            memset(used,0,sizeof(used));
            for(int k=0;k<v[i].size();k++)used[v[i][k]]++;
            for(int k=0;k<v[j].size();k++){used[v[j][k]]++;if(used[v[j][k]]>=2)a[i][j]=a[j][i]=1;}
        }
    }
    for(int k=1;k<=m;k++)
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][k]+a[k][j]<a[i][j])a[i][j]=a[i][k]+a[k][j];
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
        cout<<endl;
    }*/
    //cout<<"E"<<endl;
    long long ansft;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>q1>>q2;
        if(q1==q2){cout<<0<<"\n";continue;}
        ansft=exm;
        for(int j=0;j<rv[q1].size();j++)
        {
            for(int k=0;k<rv[q2].size();k++)
            {
                //cout<<rv[q1][j]<<" "<<rv[q2][k]<<endl;
                //cout<<a[rv[q1][j]][rv[q2][k]]<<"<-> "<<exm<<endl;
                if(a[rv[q1][j]][rv[q2][k]]!=exm){ansft=min(ansft,a[rv[q1][j]][rv[q2][k]]);}
            }
        }
        if(ansft==exm){cout<<-1<<"\n";continue;}
        if(q1!=q2)ansft++;

        if(ansft!=exm) cout<<ansft<<"\n";
    }
}
