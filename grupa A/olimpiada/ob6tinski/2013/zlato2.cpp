#include<bits/stdc++.h>
using namespace std;
long long k,t,s,n;
long long mini=1,gold;
vector<int> wbb;// will be built
void chektob(long long td)
{
    if(max(n-(td+t),0LL)*k>=s)wbb.push_back(td+t),gold-=s;
}
int main()
{
    cin>>k>>t>>s>>n;
    for(int i=1;i<=n;i++)
    {
        //cout<<"hod "<<i<<" zlato "<<gold<<" mini "<<mini<<" stroqt se "<<wbb.size()<<endl;
        //if(wbb.size()!=0)cout<<" parvata 6te e gotova v "<<wbb[0]<<endl;
        if(gold>=s)
        {
            chektob(i);
        }
        if(wbb.size()!=0)if(wbb[0]==i)
        {
            mini++;
            swap(wbb[0],wbb[wbb.size()-1]);
            wbb.pop_back();
            sort(wbb.begin(),wbb.end());
        }
        gold+=k*mini;

    }
    cout<<gold<<endl;
}

