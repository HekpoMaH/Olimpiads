#include<bits/stdc++.h>
using namespace std;
double a,d;
int n;
int dir[5][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    scanf("%lf%lf",&a,&d);
    scanf("%d",&n);
    double cx=0,cy=0;int cntr=0;;
    for(int i=1;i<=n;i++)
    {
        cx+=dir[cntr][0]*d;cy+=dir[cntr][1];
        while(cx>a||cx<0)
        {

            cout<<cx<<" "<<cy<<endl;
            cx-=dir[cntr][0]*a;
            cntr++;cntr%=4;
            cy+=dir[cntr][1]*a;
        }
        printf("%.8lf %.8lf\n",cx,cy);
    }
}
