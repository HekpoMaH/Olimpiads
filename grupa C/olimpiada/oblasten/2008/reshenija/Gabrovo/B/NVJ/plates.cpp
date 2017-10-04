#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;

int n,m;

struct cmp
{
    bool operator() (vector<string> a, vector<string> b)
    {
        bool q=true;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
             q=false;
             break;
            }
        }

        if(q)
         return 0;
         //cout<<"0";
        q=true;
        for(int i=0, j=n-1;i<n;i++,j--)
        {
            string stmp="";
            for(int k=0;k<n;k++)
             stmp+=b[k][j];
            if(a[i]!=stmp)
            {
                q=false;
                break;
            }
        }
        if(q)
         return 0;
         //cout<<"1";
        q=true;
        for(int i=0, j=n-1;i<n;i++,j--)
        {
            string stmp="";
            for(int k=n-1;k>=0;k--)
             stmp+=b[j][k];
            if(a[i]!=stmp)
            {
                q=false;
                break;
            }
        }
        if(q)
         return 0;
         //cout<<"2";
        q=true;
        for(int i=0, j=0;i<n;i++,j++)
        {
            string stmp="";
            for(int k=n-1;k>=0;k--)
             stmp+=b[k][j];
            if(a[i]!=stmp)
            {
                q=false;
                break;
            }
        }
    //    cout<<"3"<<q;
        return !q;
    }
};


int main()
{

    //vector<int> tmp(m);
    set<vector <string> , cmp> pl;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        vector<string> curr;
        for(int j=0;j<n;j++)
        {
            string tmp;
            cin>>tmp;
            curr.push_back(tmp);
        }
        //cout<<i<<"   ";
        pl.insert(curr);
        //cout<<endl;
    }
    cout<<pl.size()<<endl;

    return 0;
}
