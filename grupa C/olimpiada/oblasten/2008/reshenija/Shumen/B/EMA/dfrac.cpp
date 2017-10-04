#include<iostream>
using namespace std;
int used[10];
int main()
{
    int a,b,n;
    long long int p;
    cin>>a>>b>>p>>n;
    long long int s=n+p;
    string t;int br=1,l=0,br2;
    while(s>=0)
    {
            a*=10;
            //cout<<a<<endl;
            int k=a/b;
            if(used[k]==0)
            {
                        used[k]=br;
                        t=t+char(k+'0');
                        a=a-b*(a/b);
                        s--;
                        br++;
            }
            else
            if(used[k]!=0&&l==1)
            {
                long long int j;
                //cout<<">>"<<s<<' '<<br2<<' '<<br<<endl;
                while(s>=0)
                {
                 for(j=br2;j<br;j++)
                  t=t+t[j];
                 s-=br-br2;
                }
                break;
            }
            else
            if(used[k]!=0&&l==0)
            {
                        l=1;
                        br2=used[k];
                        t=t+char(k+'0');
                        a=a-b*(a/b);
                        s--;
            }
            else l=0;

    }
    long long i,e=n+p-1;
    for(i=p-1;i<e;i++)
     cout<<t[i];
    cout<<endl;
return 0;
}
