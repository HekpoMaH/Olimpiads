#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;


float point[501];
int groups[501];
int n,p;
float dmin = 0xFFFFFFFF;
int proc_group()
{
    
    float d = 0;
         int cgroup = 0;
         for(int i = 0; i <= p; i++)
         {
             float s = 0;
             for(int j = cgroup; j < (cgroup + groups[i] );j++)
             {
                   s += point[j];
                   //cout << point[j] << " ";
             }
             s /=groups[i];
             for(int j = cgroup; j < (cgroup + groups[i]);j++)
                   d += (s-point[j])*(s - point[j]);
             cgroup += groups[i] ;
             //cout << endl;             
         }
         //cout << "Next Group:" << endl; 
         if(d < dmin) dmin = d;
         /*for(int i = 0; i < p; i++)
                 cout << groups[i];
                 
         cout << endl;*/
         return 0;    
}
int sub(int i,int c)
{
    
    if(c == p && i == n)
    {
         proc_group();
         return 0;
    }
    if(i >= n || c >= p)return 0;
    for(int j = 1; j < n  ; j ++ )
    {
            groups[c] = j;

            sub(i + j,c+1);
    }
}
int main()
{
    cin >> n >> p;
    for(int i = 0; i < n;i ++)
            cin >> point[i];
    sub(0,0);
    printf("%.4f",dmin);
    
         
}
