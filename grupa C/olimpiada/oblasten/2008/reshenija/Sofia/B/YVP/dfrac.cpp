#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<int,int> R;

int a,b;
unsigned long long k;
int p;

int NOD(int a, int b)
{
    if(b==0) return a;
    return NOD(b, a%b);
}

int main()
{
    cin>>a>>b;
    cin>>k;
    k--;
    cin>>p;
    a%=b;
    int az = NOD(a,b);
    a/=az;
    b/=az;
    int cnt=0;
    int f=(a*10)%b;
    while(R.find(f)==R.end())
    {
      R[f]=cnt;
      f=(10*f)%b;
      cnt++;
    }
    int st=R[f]+1;
    int len=cnt-R[f];
    if(k<st) {
             int r = a;
             int u;
             for(int i=0; i<k+p; i++)
             {
                     u = r*10/b;
                     if(i>=k) {printf("%c", u);}
                     r=r*10%b;
             }
             printf("\n");
             return 0;
    }
    k-=st;
    k%=len;
    k+=st;
    int r=a;
    for(int i=0; i<k+p; i++)
    {
            int u = r*10/b;
            if(i>=k) {printf("%c", u);}
            r=r*10%b;
    }
    printf("\n");
    return 0;
}
