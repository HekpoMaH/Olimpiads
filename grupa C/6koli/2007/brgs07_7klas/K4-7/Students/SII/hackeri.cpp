#include<iostream>
#include<string>
#include<ctime>
using namespace std;
string s1,s2,s3,s4[16384],s5;
int main()
{
    cin>>s1;
    int n=s1.size(),i,m,j=0;
    for(i=1;i<=n;i++)
    {
                    s2=s1.substr(0,i);
                    s3=s1+s2;
                    s4[j]=s3;
                    if(clock()/CLOCKS_PER_SEC>1){cout<<s1<<s1<<endl;return 0;}
                    j++;
    }
    for(i=0;i<j;i++)
    {
                    reverse(s4[i].begin()+n,s4[i].end());
    }
    for(i=0;i<j;i++)
    {
                    s5=s4[i];
                    reverse(s4[i].begin(),s4[i].end());
                    if(s5==s4[i]){cout<<s5<<endl;break;}
    }
}
