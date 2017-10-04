#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    string s;
    while(cin>>n>>k>>s)
    {
        if(k==2)
        {
                int t1=0,t2=0;
                for(int i=0;i<n;i++)
                {
                   if(s[i]-'A'==i%2)t1++;
                   else t2++;
                }
                //cout<<t1<<" "<<t2<<endl;
                if(t1>t2)
                {
                  cout<<t2<<endl;
                  for(int i=0;i<n;i++)
                  cout<<(char)((i%2)+'A');
                }
                else
                {
                  cout<<t1<<endl;
                  for(int i=0;i<n;i++)
                  cout<<(char)('B'-(i%2));
                }
        }
        else
        {
        int t=0;
        for(int i=1;i<n;i++)
        {
             if(s[i]==s[i-1])
             {
                 while(s[i]==s[i-1]||s[i]==s[i+1])
                     s[i]=rand()%k+'A';
                 t++;
             }
        }
        cout<<t<<endl;
        cout<<s<<endl;
        }
    }
}