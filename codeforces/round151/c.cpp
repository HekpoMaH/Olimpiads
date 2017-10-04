#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;
int n,k;
int a[100],br,used[100];
set<int> s;
vector<int> v;
void rec(int pos,int sum)
{
    if(br==k)return;
    if(s.find(sum)==s.end()&&sum!=0)
    {
        //cout<<"sum="<<sum<<endl;
        s.insert(sum);
        br++;
        printf("%d ",v.size());
        for(int i=0;i<v.size();i++)printf("%d ",v[i]);
        printf("\n");
    }
    for(int i=pos;i<=n;i++)
    {
        if(used[i]==0)
        {
            v.push_back(a[i]);
            used[i]=1;
            rec(i,sum+a[i]);
            used[i]=0;
            v.pop_back();
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(br<k)printf("1 %d\n",a[i]),br++,s.insert(a[i]);
    }
    //cout<<"ss="<<s.size()<<endl;
    rec(1,0);
}
