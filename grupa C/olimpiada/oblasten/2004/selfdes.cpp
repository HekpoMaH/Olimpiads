#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string n,nn;
int k;
void transform(string &s)
{
    int br=1,n=s.size();
    string snew="",sbr;
    for(int i=0;i<n;i++)
    {
        if(i==n-1||s[i]!=s[i+1])
        {
            sbr="";
            while(br!=0){sbr+=br%10+'0';br/=10;}
            reverse(sbr.begin(),sbr.end());
            snew+=sbr;
            snew+=s[i];br=1;
        }
        else br++;
    }
    s=snew;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<k;i++)transform(n);
    cout<<n<<endl;
    return 0;
}
