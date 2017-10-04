#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<unsigned long long> primes;
unsigned long long n;
unsigned long long erato[100004];unsigned long long cr;
double kik;

int main()
{
    cin>>n;
    ios::sync_with_stdio(false);
    erato[1]=1;
    for(int i=1;i<=100000;i++)
    {
        //if(i<=10000)sqr[i*i]=i;//cout<<i<<" "<<i*i<<endl;
        if(erato[i]==0)
        {
            //cout<<i<<endl;
            primes.push_back(i);
            for(int j=i+i;j<=100000;j+=i)erato[j]=1;//,cout<<j<<endl;
        }
    }
    //cout<<sqr[16]<<endl;
    //for(int i=0;i<primes.size();i++)cout<<primes[i]<<endl;
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i;j<primes.size();j++)
        {
            cr=primes[i]*primes[j]+1;
            if(cr>n*n)break;
            //kik=sqrt(cr);
            //if(cr<0){cout<<"MAMA MU"<<endl;return 0;}
            //cout<<primes[i]<<" "<<primes[j]<<" "<<kik<<endl;
            if(sqrt(cr)==(int)sqrt(cr))cout<<sqrt(cr)<<endl;
        }
    }
}

