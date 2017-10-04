#include<iostream>
#include<set>
#define ii pair<int,int>
#define i4 pair<ii, ii>

using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    set<i4> x;
    set<i4> y;
    for(i=0;i<n;i++)
    {
     ii ll,ur;
     cin>>ll.first>>ll.second>>ur.first>>ur.second;
     for(j=ll.second;j<ur.second;j++)
     {
       y.insert(i4(ii(ll.first,j),ii(ll.first,j+1)));
       y.insert(i4(ii(ur.first,j),ii(ur.first,j+1)));
     }
     for(j=ll.first;j<ur.first;j++)
     {
       x.insert(i4(ii(j,ll.second),ii(j+1,ll.second)));
       x.insert(i4(ii(j,ur.second),ii(j+1,ur.second)));
     }
    }
    cout<<x.size()+y.size()<<endl;
    return 0;
}
