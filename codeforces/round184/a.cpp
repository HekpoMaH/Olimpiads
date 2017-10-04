#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int n;
int a[1000],used[100],ee[1000],br2;
vector<int> s;
bool chk(int x,int pos)
{if(x==0){return true;}
int br=0;
bool re=0;
    while(x!=0)
    {
        br++;
        if(x%10!=0&&br==pos){re=true;}
        if(x%10!=0&&br!=pos)return false;
        x/=10;
    }return re;
}
bool ca(int x)
{
    int br=0;
    do
    {
        br++;//cout<<br<<" "<<used[br]<<endl;
        if(used[br]==1)return false;
        //cout<<br<<" "<<used[br]<<endl;
        x/=10;
    }while(x!=0);
    return true;
}
void adi(int x)
{
    int br=0;
    do
    {
        br++;
        if(x%10!=0)used[br]=1;
        x/=10;
    }while(x!=0);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=5;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if((chk(a[i],j)==true&&ee[i]==0)){s.push_back(a[i]);if(!(j==1&&a[i]==0))used[j]=1;ee[i]=1;break;}
        }
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<ee[i]<<endl;
        if(ee[i]==0&&ca(a[i])==true){s.push_back(a[i]);adi(a[i]);ee[i]=1;}
    }

    //cout<<s.size()<<endl;

    cout<<s.size()<<endl;
    for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
    cout<<endl;
}
