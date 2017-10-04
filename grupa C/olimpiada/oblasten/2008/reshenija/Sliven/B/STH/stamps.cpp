#include<stdio.h>
#include<stdlib.h>
int main()
{
    int S,N,i,x=0,j=0,p=0,u=10000,y;
    scanf("%d %d",&S,&N);
    int a[N];
    for(i=0;i<N;i++)
     scanf("%d",&a[i]);
    for(i=0;i<N;i++)
     if(a[i]>a[i+1])
      {
         p=a[i];
         a[i]=a[i+1];
         a[i+1]=p;
      }
    p=N-1;  
    for(int k=N-1;k>-1;k--)
     { 
         while(x<S)
         {  
            x+=a[p];
            if(x>S)
            {
                  x-=a[p];
                  p--;
                  continue;
            }
            j++;
         }
         p--;
         if(j<u)
         u=j;
     }
    printf("\n");
    printf("%d\n",u);
    return 0;
}


                
         