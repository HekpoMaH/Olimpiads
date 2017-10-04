#include<bits/stdc++.h>
using namespace std;
int p[10009][4];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i][1]>>p[i][2];
    double best=100000000000000;
    //cout<<best<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                if((p[i][1]-p[j][1])*(p[i][1]-p[j][1])+(p[i][2]-p[j][2])*(p[i][2]-p[j][2]))
                {
                    best=(p[i][1]-p[j][1])*(p[i][1]-p[j][1])+(p[i][2]-p[j][2])*(p[i][2]-p[j][2]);
                }
            }
        }
    }
    printf("%.2lf\n",sqrt(best));
}
