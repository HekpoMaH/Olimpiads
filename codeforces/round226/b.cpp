#include<bits/stdc++.h>
using namespace std;
char ch;
string s;
int p[5009];
int main()
{
    cin>>s;long long br=0,br2=-1;
    //p[0]=p[1]=p[2];
    for(int i=3;i<s.size();i++)
    {

        if(s[i-3]=='b'&&s[i-2]=='e'&&s[i-1]=='a'&&s[i]=='r')
        {
            br2=i-3;
        }
        br+=br2+1;
        cout<<s[i]<<" "<<br<<" "<<br2<<endl;
    }
    cout<<br<<endl;

}
