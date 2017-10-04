#include<iostream>
#include<algorithm>

using namespace std;

long long a[1000000];
bool rem[1000];

int main()
{
    long long x[10];
    long long ans, max1 = 0;
    int n, current, cnt;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> x[i];
        if(max1 < x[i]) max1 = x[i];
    }
    if(n==2)
    {
        ans = x[1]*x[2]-x[1]-x[2];
        cout << ans << endl;
        return 0;
    }
    if(max1 < 1000)
    {
        for(int i=1; i<=n; i++)
            a[x[i]]=1;
        cnt = 0;
        current = 1;
        while(cnt < x[1])
        {
            current++;
            if(a[current])
            {
                cnt++;
                for(int i=1; i<=n; i++)
                    a[current+x[i]] = 1;
            }
            else cnt = 0;
        }
        ans = current - x[1];
        cout << ans << endl;
        return 0;
    }
    long long x12 = x[2]*x[1]-x[2];
    cnt=0;
    if(n==3)
    {
        for(int i2=0; x[2]*i2<=x12; i2++)
            for(int i3=0; x[2]*i2+x[3]*i3<=x12; i3++)
            {
                a[cnt]=x[2]*i2+x[3]*i3;
                cnt++;
            }
    }
    if(n==4)
    {
        for(int i2=0; x[2]*i2<=x12; i2++)
            for(int i3=0; x[2]*i2+x[3]*i3<=x12; i3++)
                for(int i4=0; x[2]*i2+x[3]*i3+x[4]*i4<=x12; i4++)
                {
                    a[cnt]=x[2]*i2+x[3]*i3+x[4]*i4;
                    cnt++;
                }
    }
    if(n==5)
    {
        for(int i2=0; x[2]*i2<=x12; i2++)
            for(int i3=0; x[2]*i2+x[3]*i3<=x12; i3++)
                for(int i4=0; x[2]*i2+x[3]*i3+x[4]*i4<=x12; i4++)
                    for(int i5=0; x[2]*i2+x[3]*i3+x[4]*i4+x[5]*i5<=x12; i5++)
                    {
                        a[cnt]=x[2]*i2+x[3]*i3+x[4]*i4+x[5]*i5;
                        cnt++;
                    }
    }
    sort(a,a+cnt);
    current = 1;
    int numrem = int(x[1] - 1);
    while(numrem>0)
    {
        int rest = int(a[current]%x[1]);
        if(rest && !rem[rest])
        {
            rem[rest]=1;
            numrem--;
        }
        current++;
    }
    current--;
    ans = a[current] - x[1];
    cout << ans << endl;
    return 0;
}
