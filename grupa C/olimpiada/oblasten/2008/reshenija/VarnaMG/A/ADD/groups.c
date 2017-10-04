#include<stdio.h>

double chisla[1024] = {0};
int breakpoint[1024] = {0};
double razlika[1024] = {0};
double sortrazlika[1024] = {0};

int main()
{
    double sum = 0, di = 0;
    int br = 0;
    int n, p;
    int i, j, ind, temp;
    double a, b, max;
    
    scanf("%d %d", &n, &p);
    scanf("%lf", &a);
    chisla[0] = a;
    
    for(i = 0; i < n-1; i++)
    {
        scanf("%lf", &b);
        chisla[i+1] = b;
        razlika[i] = b-a;
        a = b;
    }
    
    for(i = 0; i < n - 1; i++)
    {
        sortrazlika[i] = razlika[i];
    }
    
    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)
        {
            if(sortrazlika[j] > max) {max = sortrazlika[i]; ind = j;}
        }
        
        temp = sortrazlika[i];
        sortrazlika[i] = sortrazlika[ind];
        sortrazlika[ind] = temp;
        max = 0;
    }            
            
    for(j = 0; j < p-1; j++)
    {
        for(i = 0; i < n-1; i++)
        {
            if(razlika[i] == sortrazlika[j]) {breakpoint[i+1] = 1; breakpoint[i+2] = 1;}
        }
    }

    for(i = 0; i <= n; i++)
    {
        if(breakpoint[i] == 1) br++;
    }

    if(br % 2 == 0){

    br = 0;
    for(i = 0; i  < n; i++)
    {
        sum = sum + chisla[i];
        br++;
        if((breakpoint[i+1] == 1 && breakpoint[i+2] == 1) || i == n-1)
        {
                sum = sum/br;
                for(j = i; br > 0; j--, br--)
                {
                        di = di + (sum-chisla[j])*(sum-chisla[j]);
                }
                sum = 0;
        }
    }
    }
    else
    {
    br = 0;
    for(i = 0; i  < n; i++)
    {
        sum = sum + chisla[i];
        br++;
        if((breakpoint[i+1] == 1 && breakpoint[i+2] == 1) || i == n-1)
        {
                sum = sum/br;
                for(j = i; br > 0; j--, br--)
                {
                        di = di + (sum-chisla[j])*(sum-chisla[j]);
                }
                sum = 0;
                if(razlika[i-1] == razlika[i] || i == 0) breakpoint[i+2] = 0;
        }
    }
    }

    printf("%.4lf\n", di);
    
    return 0;
}
