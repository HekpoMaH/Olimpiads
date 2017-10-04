#include<bits/stdc++.h>
using namespace std;
string s;
struct prt
{
    char let;
    int sz;
};
prt p[200009];
int pbr,br;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        br++;
        if((i>=1&&s[i]!=s[i-1]))
        {
            pbr++;
            p[pbr].let=s[i-1];
            p[pbr].sz=br-1;
            //else p[pbr].sz=br;
            br=1;
        }
    }
    pbr++;
    p[pbr].let=s[s.size()-1];
    p[pbr].sz=br;
    int idx=1;
    //oooggiii oogii
    //oogggii oogii
    //oooogg  oog||ogg
    //oggggi
    while(idx<=pbr)
    {
        //cout<<idx<<endl;
        if(p[idx].sz>=2&&p[idx+1].sz>=2&&p[idx+2].sz>=2)
        {
            p[idx].sz=2;
            p[idx+1].sz=1;
            p[idx+2].sz=2;
        }
        if(p[idx].sz>=2&&p[idx+1].sz>=2)
        {
            p[idx].sz=2;
            p[idx+1].sz=1;
            //p[idx+2].sz=2;
        }
        if(p[idx].sz>=2)
        {
            p[idx].sz=2;
            //p[idx+1].sz=1;
            //p[idx+2].sz=2;
        }
        idx++;
    }
    /*idx=1;
    while(idx<=pbr)
    {
        while(p[idx].sz>=3)p[idx].sz--;
        if(p[idx].sz==2&&p[idx+1].sz==2)p[idx+1].sz=1;
        idx++;
    }*/
    for(int i=1;i<=pbr;i++)
    {
        for(int j=1;j<=p[i].sz;j++)
        {
            cout<<p[i].let;
        }
    }
    cout<<endl;
}
