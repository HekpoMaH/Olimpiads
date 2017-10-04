#include<iostream>
using namespace std;
int main()
{
    double n,vote,x,y,f;
    cin>>x>>y>>n;
    f=n;
    vote=x*n;
    while(!(int)vote/n<y+1)
    {
        if((int)(vote+n)/(n*2)>=y+1)
        {
            vote+=n;
            n=n*2;
        }
        else
        {
            vote+=1;
            n+=1;
        }
        if(vote/n<y+1)
        break;
    }
    cout<<n-f<<'\n';
    return 0;
}

            
