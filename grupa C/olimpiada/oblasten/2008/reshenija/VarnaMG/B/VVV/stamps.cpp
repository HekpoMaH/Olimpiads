#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;
    int a[n], i, j, tmp, curr, min=s, k, r, y, z;
    for(i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    int b[n][2];
    for(i=0; i<n; i++) for(j=0; j<2; j++) b[i][j]=0;
    for(i=0; i<n; i++)
    {
        tmp=s;
        for(j=0; j<s+1; j++)
        {
            b[i][0]++;
            if(tmp-a[i]>=a[i]) 
                tmp-=a[i];
            else
            {
                b[i][1]=tmp-a[i];
                break;
            }
        }   
    }
    for(i=n-1; i>0; i--)
    {
        for(k=2; k<n; k++)
        {   
            curr = b[i][0];
            r=b[i][1];
            for(j=n-k; j>=0; j--)
            {
                while(a[j]<=b[i][1])
                {
                    curr++;
                    b[i][1]-=a[j];
                }
            }
            if(curr < min) min=curr;
            b[i][1]=r;
        }
    }
    cout << min << endl;
    system("pause");
    return 0;
}
