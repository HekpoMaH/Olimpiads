#include<iostream>
#include<cstdio>
using namespace std;
long long nb[99999],n;
void gen()
{
    int br=0;
    for(int f=1;f<=9;f++)
    {
        for(int s=0;s<=9;s++)
        {
            for(int t=0;t<=9;t++)
            {
                if(s==f+t)
                {
                    for(int fo=0;fo<=9;fo++)
                    {
                        for(int fi=0;fi<=9;fi++)
                        {
                            if(fo==t+fi)
                            {
                                br++;
                                nb[10000*f+1000*s+t*100+fo*10+fi]=br;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=10000;i<=n;i++)nb[i]=0;
    gen();
    cout<<nb[n]<<endl;
    return 0;
}
