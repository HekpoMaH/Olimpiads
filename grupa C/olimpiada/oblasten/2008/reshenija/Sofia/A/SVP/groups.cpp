#include <stdio.h>
#include <math.h>

struct group
{
    int beg;
    int end;
    double sum;
    double average;
    double d;
};
int main()
{
    int n, p, cur_p;
    double d_sum = 0.0;
    double pnts[500];
    group grps[500];

    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; ++i)
        scanf("%lf", &pnts[i]);
    grps[0].beg = 0;
    grps[0].end = 0;
    grps[0].sum += pnts[0];     
    cur_p = p - 1; 
    for(int i = 1; cur_p != n - i && i < n - 1; i++)
    {
        if((pnts[i] - pnts[i - 1]) < (pnts[i + 1] - pnts[i]))
        {    
            grps[p - cur_p - 1].end++;
            grps[p - cur_p - 1].sum += pnts[i];
        }
        if((pnts[i] - pnts[i - 1]) == (pnts[i + 1] - pnts[i]))
        {
            if(grps[p - cur_p - 1].beg == grps[p - cur_p - 1].end)
            {    
                grps[p - cur_p - 1].end++;
                grps[p - cur_p - 1].sum += pnts[i];            
            }
            else
            {    
                if(cur_p > 0)
                {       
                    cur_p--;
                    grps[p - cur_p - 1].beg = i;
                    grps[p - cur_p - 1].end = i;     
                    grps[p - cur_p - 1].sum += pnts[i];  
                }
                else
                {    
                    grps[p - cur_p - 1].end++;
                    grps[p - cur_p - 1].sum += pnts[i];      
                } 
            }
        }     
        
        if((pnts[i] - pnts[i - 1]) > (pnts[i + 1] - pnts[i]))
        {    
            if(cur_p > 0)
            {    
                cur_p--;
                grps[p - cur_p - 1].beg = i;
                grps[p - cur_p - 1].end = i;     
                grps[p - cur_p - 1].sum += pnts[i];
            }
            else
            {    
                grps[p - cur_p - 1].end++;
                
            }
        }
        
    }
    if(cur_p == 0)
    {
        grps[p - 1].end++;
        grps[p - 1].sum += pnts[n-1];          
    }
    
    
    int temp = p - cur_p;
    for(int i = 0; i < temp; i++)
    {
        grps[i].average = grps[i].sum / (grps[i].end - grps[i].beg + 1);
        for(int j = grps[i].beg; j <= grps[i].end; ++j)
            d_sum += (pnts[j] - grps[i].average) * (pnts[j] - grps[i].average);
    }
    printf("%.4lf\n", d_sum);
    
    return 0;
}
