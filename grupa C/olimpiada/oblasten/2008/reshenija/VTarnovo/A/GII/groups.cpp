#include <iostream>
#include <iomanip>
#define sqr(a)((a)*(a))
using namespace std;

double sum[500][500];  // sum
double s[500][500];    // middle
int n, p;
double a[500];
double d[500];
int gr[500][2]; // gr[i].l / .r  incl !

int main()
{
    int i, j;
    cin >> n >> p;
    for (i=0;i < n;i++)
     cin >> a[i];
    
    for (i=0;i < n;i++)
    {
        double tmps = 0.0;
        for (j=i;j < n;j++)
        {
            tmps += a[j];
            sum[i][j] = tmps;
            s[i][j] = tmps / (j - i + 1);
        }
    } 
    
    gr[0][0] = 0;
    gr[0][1] = n - p;
    double mid = s[0][n-p];
    for (i=0; i <= n-p;i++)
     d[0] += sqr(mid - a[i]);
    for (i=1;i < p;i++)
    {
        gr[i][0] = gr[i][1] = gr[i-1][1] + 1;
        d[i] = 0.0;
        //cout << gr[i][0] << " " << gr[i][1] << endl;
    }
    
    bool flag = 1;
    double d1, d2, d3, d4;
    while (flag)
    {
       flag = 0;
       for (i=0;i < p-1;i++)
       {
           d1 = d2 = d3 = d4 = 9999999.0;
           if (gr[i][1] - gr[i][0] > 0)
           {
              d1 = d2 = 0.0;
              mid = s[gr[i][0]][gr[i][1]-1];
              for (int k=gr[i][0]; k < gr[i][1];k++)
               d1 += sqr(mid - a[k]);
              mid = s[gr[i+1][0]-1][gr[i+1][1]];
              for (int k=gr[i+1][0]-1; k <= gr[i+1][1];k++)
               d2 += sqr(mid - a[k]);
           }
           
           if (gr[i+1][1] - gr[i+1][0] > 0)
           {
              d3 = d4 = 0.0;
              mid = s[gr[i][0]][gr[i][1]+1];
              for (int k=gr[i][0]; k <= gr[i][1]+1;k++)
               d3 += sqr(mid - a[k]);
              mid = s[gr[i+1][0]+1][gr[i+1][1]];
              for (int k=gr[i+1][0]+1; k <= gr[i+1][1];k++)
               d4 += sqr(mid - a[k]);
           }
           
           if (d1+d2 < d[i]+d[i+1] && d1+d2 < d3+d4)
           {
              d[i] = d1; d[i+1] = d2;
              gr[i][1]--; gr[i+1][0]--;
              flag = 1;
           }else if (d3+d4 < d[i]+d[i+1] && d3+d4 < d1+d2)
           {
              d[i] = d3; d[i+1] = d4;
              gr[i][1]++; gr[i+1][0]++;
              flag = 1;
           }  
       }
    }
    
    double mind = 0.0;
    for (i=0;i < p;i++)
     mind += d[i];
    
    cout << mind << endl;
    //system("pause");
    return 0;
}
       
