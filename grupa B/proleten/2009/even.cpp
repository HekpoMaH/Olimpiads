#include<iostream>
using namespace std;
int main()
{
    long long digcount,diglim;
    cin>>digcount>>diglim;
    long long digits[16];
    long long biggereven[16];
    long long biggerodd[16];
    long long possib[16];
    cin>>digits[0];
    possib[0]=1;
    for(int i=1;i<digcount;i++)
    {
        cin>>digits[i];
        biggereven[i-1]=(diglim-digits[i])/2+(diglim%2==0&&digits[i]%2==1);
        biggerodd[i-1]=(diglim-digits[i])/2+(diglim%2==1&&digits[i]%2==0);
        if(digits[i]==0)
        {
            biggerodd[i-1]--;
        }
        possib[i]=possib[i-1]*(biggerodd[i-1]+biggereven[i-1]);
    }
    long long ressum=0;
    long long oddcount=digits[digcount-1];
    long long multipl=1;
    for(int j=digcount-2;j>=0;j--)
    {
        if(oddcount%2==0)ressum+=biggereven[j]*possib[j]*multipl;
        multipl=multipl*biggerodd[j];
        if(digits[j]%2==1)oddcount++;
    }
    if(oddcount%2==0)ressum+=multipl;
    cout<<ressum<<endl;
}
