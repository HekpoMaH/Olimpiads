#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    int br=1;
    cin>>s;
    n=s.size();
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        //cout<<i<<endl;
        if(s[i]!='0')
        {
            if(i>n-i)
            {
                br++;
                n=i;
            }
            else if(i<n-i)break;
            else
            {
                for(j=0;j<i;j++)
                {
                    //cout<<i<<" "<<j<<endl;
                    if(s[j]>s[i+j])
                    {
                        n=i;
                        br++;
                        break;
                    }
                    if(s[j]<s[i+j])break;
                }
                if(i==j)n=i,br++;
            }
        }
    }
    cout<<br<<endl;
}
