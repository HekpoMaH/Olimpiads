#include<bits/stdc++.h>
using namespace std;
string s;
int br[100];
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        br[s[i]-'a']++;
    }
    char a[20];
    a[1]='n';a[2]='i';a[3]='n',a[4]='e',a[5]='t',a[6]='e';a[7]='e',a[8]='n';
    int ans=0;
    for(int i=1;i<=8;i++)
    {
        if(br[a[i]-'a']==0)
        {
            cout<<ans<<endl;
            exit(0);
        }
        else br[a[i]-'a']--;
    }
    ans++;
    while(1)
    {
        for(int i=2;i<=8;i++)
        {
            //cout<<br[a[i]-'a']<<" "<<a[i]<<endl;
            if(br[a[i]-'a']==0)
            {
                cout<<ans<<endl;
                exit(0);
            }
            else br[a[i]-'a']--;
        }
        //cout<<"one more"<<endl;
        ans++;
    }
}
