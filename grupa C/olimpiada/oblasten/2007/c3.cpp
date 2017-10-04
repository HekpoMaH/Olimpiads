#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

void div(string a,string &ans)
{
    int ost=0;
    int n=a.size();
    ans="";
    for(int i=0;i<n;i++)
    {
        if(a[i]=='1'&&i==0)
        {
            ost=1;
            continue;
        }
        else
        {
            ans+=(ost*10+a[i]-'0')/2+'0';
            ost=(ost*10+a[i]-'0')%2;
        }
    }
    if(ans=="")ans+='0';
}
void sum(string a,string b,string &ans)
{
    int ss=0;
    string strs;
    if(a.size()<=b.size())
    {
        ss=a.size();
        strs=a;
    }
    if(ss==0)
    {
        ss=b.size();
        strs=b;
    }
    int sb=0;
    string strb;
    if(a.size()>b.size())
    {
        sb=a.size();
        strb=a;
    }
    if(sb==0)
    {
        sb=b.size();
        strb=b;
    }
    //cout<<"strs="<<strs<<endl;
    //cout<<"strb="<<strb<<endl;
    int ps,vs,ts;
    int na=0;
    int index=sb-1,index2=ss-1;
    while(index>=0)
    {
        ts=0;
        ps=strb[index]-'0';
        ts+=ps;
        if(index2>=0){vs=strs[index2]-'0';ts+=vs;}
        index--;index2--;
        ts+=na;
        na=ts/10;
        ts%=10;
        //cout<<ps<<" "<<vs<<" "<<ts<<" "<<na<<endl;
        ans+=ts+'0';
    }
    if(na!=0){ans+=na+'0';}
    reverse(ans.begin(),ans.end());
}
void mult(string a,string b,string &ans)
{
    int res[250];
    memset(res,0,sizeof(res));
    int mst=(a.size()-1)+(b.size()-1);
    for(int i=0;i<(int)a.size();i++)
    {
        for(int j=0;j<(int)b.size();j++)
        {
            res[i+j]+=(a[i]-'0')*(b[j]-'0');
        }
    }
    for(int i=mst;i>=1;i--)
    {
        res[i-1]+=res[i]/10;
        res[i]%=10;
    }
    //cout<<res[0]<<endl;
    int fg=res[0]/10;
    res[0]%=10;
    //cout<<"mst="<<mst<<endl;
    //cout<<"result=";
    //cout<<fg<<"|";
    //for(int i=0;i<=mst;i++)cout<<res[i];
    //cout<<endl;
    if(fg!=0)ans+=fg+'0';
    for(int i=0;i<=mst;i++)ans+=res[i]+'0';
}
bool smaller(string a,string b)
{
    if(a.size()<b.size())return true;
    if(a.size()>b.size())return false;
    int x=a.size();
    for(int i=0;i<x;i++)
    {
        if(a[i]<b[i])return true;
        if(a[i]>b[i])return false;
    }
    return false;
}
string a,b;
void bsearch(string left,string right,string &ans)
{
    string x,edno,mid,zp1,zp2;
    while(1)
    {
        ///1)
        
        edno="";
        sum(left,right,edno);
        mid="";
        zp1="";
        zp2="";
        zp1=left;
        //sum(left,"1",zp1);
        zp2=right;
        if(smaller(zp1,zp2)==false){break;}
        div(edno,mid);
        x="";
        mult(mid,a,x);//x=mid*a;
        //cout<<"mid="<<mid<<endl<<"x="<<x<<endl;
        
        //return;
        if(smaller(x,b))
        {
            //cout<<x<<" "<<b<<" "<<smaller(x,b)<<endl;
            left="";ans=mid;
            sum(mid,"1",left);
        }
        else
        {
            right=mid;
        }//if(mid=="3")return;
        //sum(left,"1",left);
        //cout<<"left="<<left<<endl<<"right="<<right<<endl;
    }
    //ans=mid;
}

int main()
{
    cin>>a>>b;
    //div(a,b);
    //cout<<smaller(a,b)<<endl;return 0;
    //return 0;
    //n=a.size();
    
    string ans;//sum(a,"1",ans);cout<<ans<<endl;return 0;
    //cout<<smaller(a,b)<<endl;
    //sum(a,b,ans);
    string bb,ee;bb+='1';
    ee+='1';
    for(int i=1;i<=100;i++)ee+='0';
    //cout<<ee<<endl;
    //div(a,ans);
    //cout<<ans<<endl;
    bsearch(bb,ee,ans);
    cout<<ans<<endl;
    return 0;
}
