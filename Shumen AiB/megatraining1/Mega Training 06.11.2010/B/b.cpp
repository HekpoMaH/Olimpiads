#include<bits/stdc++.h>
using namespace std;
int n,m;int t,rb;
map<string,int> mp;
string tsk,at;
int num,br,sumazaproverka;
int a[109][109],tab[109][109],flow[109][109],pred[109],used[109],br2,mxbr,flowzazad[109];
bool fl;
string getncom(int &ind)
{
    string ans="";
    for(ind;ind<at.size();ind++)
    {
        //cout<<"ind="<<ind<<endl;
        if(at[ind]!=' ')ans+=at[ind];
        else if(at[ind]==' ')
        {
            ind++;
            return ans;
        }
        else if(ind==at.size()-1)
        {
            ind++;
            return ans;
        }

    }
}
void bfs()
{
    queue<int> q;
    while(!q.empty())q.pop();
    memset(used,0,sizeof(used));
    q.push(0);
    used[0]=1;
    int fr;
    pred[0]=-1;
    while(!q.empty())
    {
        fr=q.front();
        //cout<<"fr="<<fr<<endl;
        q.pop();
        for(int i=1;i<=n+m+1;i++)
        {
            //cout<<i<<" "<<used[i]<<" "<<tab[fr][i]<<endl;
            if(used[i]==0&&tab[fr][i]>0)
            {
                //cout<<a[fr][i]<<endl;
                used[i]=1;
                q.push(i);
                pred[i]=fr;
            }
        }

        if(used[n+m+1]==1){fl=true;return;}
    }
    //cout<<"used="<<used[n]<<endl;

}
bool dothatflow()
{
    int i;
    int mxflow=0;
    fl=true;
    while(fl)
    {
        fl=false;
        //memset(used,0,sizeof(used));
        bfs();
        //cout<<"fl="<<fl<<endl;
        if(fl==false)break;
        int mnf=999999;
        for(i=n+m+1;pred[i]!=-1;i=pred[i])
        {
            mnf=min(mnf,tab[pred[i]][i]);
        }
        for(i=n+m+1;pred[i]!=-1;i=pred[i])
        {
            flow[pred[i]][i]+=mnf;
            flow[i][pred[i]]-=mnf;
            tab[pred[i]][i]-=mnf;
            tab[i][pred[i]]+=mnf;
            //cout<<"vlizatuka"<<endl;
        }
        mxflow+=mnf;
    }
    //cout<<"mxflow="<<mxflow<<endl;
    if(mxflow>=sumazaproverka)return true;
    return false;
}
void solve()
{
    mxbr=0;
    string ssss;
    getline(cin,ssss);
    //cout<<"sss"<<ssss<<endl;
    sscanf(ssss.c_str(),"%d %d",&n,&m);
    cout<<n<<" "<<m<<endl;
    //cout<<n<<" "<<m<<endl;
    char tkc[1009];
    for(int i=1;i<=n;i++)
    {
        //string ssss;
        getline(cin,ssss);
        sscanf(ssss.c_str(),"%s %d",&tkc,&num);
        tsk="";
        for(int j=0;j<strlen(tkc);j++)
        {
            tsk+=tkc[j];
        }
        //cout<<i<<" "<<tsk<<" "<<num<<endl;
        mp[tsk]=i;
        flowzazad[i]=num;
        //sumazaproverka+=num;
    }
    int idx;
    string com;
    char aat[1009];
    for(int i=1;i<=m;i++)
    {
        //cout<<i<<" ";

        at="";
        getline(cin,at);
        for(int j=0;j<strlen(aat);j++)
        {
            at+=aat[j];
        }
        //cout<<at<<endl;
        idx=0;
        while(idx<=at.size()-1)
        {
            com=getncom(idx);
            //cout<<com<<endl;
            tab[i+n][m+n+1]=1;
            a[i+n][mp[com]]=1;
        }

    }
    cout<<"Case #"<<rb-t<<": ";
    //cout<<"TAB"<<tab[8][10]<<endl;
    //exit(0);
    //cout<<"DDDD"<<a[9][4]<<endl;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=1;j<=n;j++)tab[0][j]=0;

        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                tab[k][j+n]=0;
            }
        }
        sumazaproverka=0;for(int j=1;j<=m;j++)tab[j+n][m+n+1]=1;
        for(int j=1;j<=n;j++)
        {
            if(i&(1<<(j-1)))
            {
                sumazaproverka+=flowzazad[j];
                tab[0][j]=flowzazad[j];
                //cout<<tab[0][j]<<" endl"<<endl;
                for(int k=1;k<=m;k++)
                {
                    if(a[n+k][j]==1)tab[j][k+n]=1;
                    //if(i==3&&j==1&&k==3)cout<<"TL+"<<a[n+k][j]<<" "<<tab[j][k+n+1]<<endl;
                }
            }
        }
        if(dothatflow()==true)
        {
            br2=0;
            for(int j=1;j<=n;j++)
            {
                if(i&(1<<(j-1)))
                {
                    br2++;
                }
            }
            //cout<<i<<endl;
            mxbr=max(br2,mxbr);
        }

    }
    cout<<mxbr<<endl;

}
int main()
{
    string ssss;
    getline(cin,ssss);
    sscanf(ssss.c_str(),"%d",&t);
    rb=t;
    while(t--)solve();
}
