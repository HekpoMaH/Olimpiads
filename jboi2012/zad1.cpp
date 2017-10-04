#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,sum,m[50005],brm,sr,l=1,erased;
vector<int> a;
void solve()
{
    sr=sum/(n-erased);
    int lef=0,righ=a.size()-1,mid;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        
        //cout<<lef<<" "<<righ<<" "<<mid<<" "<<a[mid]<<" "<<sr<<" "<<a.size()<<" "<<l<<endl;
        if(l==1)
        {//cout<<"WTF"<<" "<<sr<<endl;
            if((a[mid]<=sr&&mid==a.size()-1)||(mid<a.size()-1&&a[mid]<=sr&&a[mid+1]>sr))
            {
                m[++brm]=a[mid];//cout<<mid<<" "<<sr<<endl;
                if(mid==0)a.erase(a.begin());
                else a.erase(a.begin()+mid);//cout<<"sr="<<sr<<endl;
                return;
            }
            else if(a[mid]>sr)
            {
                righ=mid-1;
            }
            else lef=mid+1;
        }
        else
        {
            if((a[mid]>=sr&&mid==0)||(mid>0&&a[mid]>=sr&&a[mid-1]<sr))
            {
                m[++brm]=a[mid];//cout<<mid<<" "<<sr<<endl;
                if(mid==0)a.erase(a.begin());
                else a.erase(a.begin()+mid);//cout<<"sr="<<sr<<endl;
                return;
            }
            else if(a[mid]<sr)
            {
                lef=mid+1;
            }
            else righ=mid-1;
        }
    }
    
}
int main()
{
    cin>>brm;
    for(int i=1;i<=brm;i++)
    {
        cin>>m[i];
    }
    //sort(a.begin(),a.end());
    //l=1;
    /*while(brm<n)
    {
        //cout<<l<<endl;return 0;
        solve();
        erased++;
        //cout<<sum<<endl;
        sum-=m[brm];
        //cout<<"m->";
        //cout<<endl;
        //for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
        //cout<<endl;
        l^=1;
    }*/
    //m[++brm]=a[0];
    l=1;int fl=1,mx=0,br=0;
    //cout<<"brm="<<brm<<endl;
    for(int i=2;i<brm;i++)
    {
        if(l==1&&m[i]>m[i+1]&&m[i]>m[i-1])
        {
            br++;
            //cout<<"i1="<<i<<endl;
        }
        else if(l==0&&m[i]<m[i+1]&&m[i]<m[i-1])
        {
            br++;
        }
        else
        {
            mx=max(br,mx);
            br=0;
            //cout<<"i3="<<i<<endl;
        }
        l^=1;
    }
    if(fl)mx=max(mx,br);
    cout<<mx<<endl;
    return 0;
}
/*
5
170 172 169 173 150
6
160 165 170 175 180 185
*/