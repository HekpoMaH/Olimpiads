#include <stdio.h>
#define MAXPR 6000
#define mymod(a, b) ((a)<0?((a)%(b))+(b):(a)%(b))
#include <math.h>
#include <map>
using namespace std;

int pr[MAXPR], nextpr;

int isprime(int a);
int prime(int a);
int count(int st, int num, int all);

map <pair<int, int>, int> mp;

int prime(int a)
{
    int i;
    int nextpr=0;
    for(i=2; i<=a; i++)
        if(isprime(i))
            pr[nextpr++] = i;
            
    a++;
    while(!isprime(a))
        a++;
    pr[nextpr]=a;
    
    return nextpr;
}

int isprime(int a)
{
    int i;
    for(i=2; i<=sqrt(a); i++)
        if(a%i == 0)
            return 0;
    return 1;
}

main()
{
    int n, all, i;
    scanf("%d", &n);
    all = prime(n);
    printf("%d\n", mymod(count(0, n, all) - isprime(n), pr[all]));
    return 0;
}

int count(int st, int num, int all)
{
    int ret, i, cyc;
    
    if(num==0 && st>0)
        return 1;
    
    if(num<=0 || st>=all)
        return 0;
    
    if(mp.find(make_pair(st, num)) != mp.end())
        return mp[make_pair(st, num)];
    
    ret = 0;
    cyc = num / pr[st];
    for(i=0; i<=cyc; i++)
        ret = mymod(ret + count(st+1, num - i*pr[st], all), pr[all]);
    return mp[make_pair(st, num)] = ret;
}
