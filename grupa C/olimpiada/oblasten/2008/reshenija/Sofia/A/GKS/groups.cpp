#include<iostream>
using namespace std;
int T[500];
int main ()
{
    double arr[500];
    int n, p;
    cin>>n>>p;
    for (int i=1; i<=n; i++)
        cin>>arr[i];
    int i_max;
    double p_max;
    for (int x=1; x<p; x++)
    {
        p_max=0; i_max=0;
    for (int i=1; i<=n-1; i++)
           if ((T[i]!=1) && (arr[i+1]-arr[i]>=p_max))
           {
              p_max=arr[i+1]-arr[i];
              i_max=i;
           }
    T[i_max]=1;
    }    
    double dis=0;
    int j=1;
    for(int h=1; h<=n; h++)
    {
            if (T[h]==1)
            {
               double temp=0;
               for (int b=j; b<=h; b++)
                   temp=temp+arr[b];
               temp=temp/(h-j+1);
               for (int b=j; b<=h; b++)
                   dis=dis+(arr[b]-temp)*(arr[b]-temp);
               j=h+1;
            }
    }
    double temp=0;
    for (int b=n; b>=j; b--)
    temp=temp+arr[b];
               temp=temp/(n-j+1);
               for (int b=j; b<=n; b++)
                   dis=dis+(arr[b]-temp)*(arr[b]-temp);
    printf("%.4f\n", dis);        
    return 0;
}
