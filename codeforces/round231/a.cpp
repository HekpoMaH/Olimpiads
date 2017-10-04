#include<bits/stdc++.h>
using namespace std;
int br1,br2,br3;
int main()
{
    string s;
    cin>>s;
    int i=0;
    while(s[i]!='+')
    {
        if(s[i]!='+')br1++;
        i++;
    }
    i++;
    while(s[i]!='=')br2++,i++;
    i++;
    while(i<s.size())br3++,i++;
    //cout<<br1<<" "<<br2<<" "<<br3<<endl;
    if(br1+br2==br3&&br1!=0&&br3!=0)cout<<s<<endl;
    else if(br1-1+br2==br3+1&&br1-1!=0)
    {
        for(int j=1;j<s.size();j++)cout<<s[j];
        cout<<s[0];
    }
    else if(br1+1+br2==br3-1&&br3-1!=0)
    {
        cout<<'|';
        for(int j=0;j<s.size()-1;j++)cout<<s[j];
        //cout<<s[0];
    }
    else if(br1+br2-1==br3+1&&br2-1!=0)
    {
        for(int i=1;i<=br1;i++)cout<<"|";cout<<"+";for(int i=1;i<br2;i++)cout<<"|";cout<<"=";
        for(int i=1;i<=br3+1;i++)cout<<"|";cout<<endl;
    }
    else if(br1+br2+1==br3-1&&br3-3!=0)
    {
        for(int i=1;i<=br1;i++)cout<<"|";cout<<"+";for(int i=1;i<=br2+1;i++)cout<<"|";cout<<"=";
        for(int i=1;i<br3;i++)cout<<"|";cout<<endl;
    }
    else cout<<"Impossible"<<endl;
}
