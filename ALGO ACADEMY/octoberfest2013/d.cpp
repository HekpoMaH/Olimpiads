#include<bits/stdc++.h>
using namespace std;
string x;
vector<int> groups;
void getgr()
{
    int br=1;
    for(int i=x.size()-1;i>=0;i--)
    {
        //br++;
        cout<<i<<" "<<br<<endl;
        if(br==3)
        {
            groups.push_back((x[i]-'0')*100+(x[i+1]-'0')*10+x[i+2]-'0');
            br=1;
        }
        else if(i==0)
        {
            if(br==1)groups.push_back(x[i]-'0');
            if(br==2)groups.push_back((x[i]-'0')*10+x[i+1]-'0');
        }
        else br++;
    }
    reverse(groups.begin(),groups.end());
    for(int i=0;i<groups.size();i++)
    {
        cout<<groups[i]<<" ";
    }cout<<endl;
}
int main()
{
    cin>>x;
    getgr();
}
