#include<iostream>
using namespace std;
bool find(int l,int m,int r)
{
    if(m<l)return 1;
    if(m>r)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n,s,f,i,ct=1,t,l,r,cp;
    cin>>n>>m>>s>>f;
    cp=s;
    for(i=0;i<m;i++)
    {
        cin>>t>>l>>r;
        if(cp==f)continue;
        while(ct<t && cp!=f)
        {
            if(cp>f){cout<<"L";cp--;}
            else if(cp<f){cout<<"R";cp++;}
            else cout<<"X";
            ct++;
        }
        while(ct==t && cp!=f)
        {
            if(cp>f && find(l,cp,r) && find(l,cp-1,r)){cout<<"L";cp--;}
            else if(cp<f && find(l,cp,r) && find(l,cp+1,r)){cout<<"R";cp++;}
            else cout<<"X";
            ct++;
        }
    }
    while(cp!=f)
        {
            if(cp>f){cout<<"L";cp--;}
            else if(cp<f){cout<<"R";cp++;}
            else cout<<"X";
            ct++;
        }
}
