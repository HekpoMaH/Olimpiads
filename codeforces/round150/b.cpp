#include<iostream>
#include<set>
using namespace std;
long long n,k;
bool used[1000000006];
int sum=1,sum2=1;
int main()
{
    cin>>n;
    long long n1=n,br0=0;while(n1!=0)n1/=10,br0++;
    int broi=0;

    for(int x=0;x<(1<<br0);x++)
    {
        for(int i1=1;i1<=9;i1++)
        {
            for(int i2=0;i2<=9;i2++)
            {

                long long num=i1;
                for(int eb=1;eb<br0;eb++)
                {
                    if(x&(1<<eb))num*=10,num+=i1;
                    if(!(x&(1<<eb))) num*=10;num+=i2;
                }
                cout<<num<<endl;
                if(num<=n&&used[num]==false)used[num]=true,broi++;
            }
        }
    }
    cout<<broi<<endl;
    return 0;
}
