#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int primes[10000],n,res[51000],MAX=50000;

int main()
{
    
    int i,j,f,k;
    scanf("%d",&MAX);
    
    n=1;
    primes[0]=2;
    
    for (i=3;i<51000;i++)
     {
     f=0;
     j=0;
     while( (primes[j]<=sqrt(i)) && (j<n))
      if (i%primes[j++]==0) f=1;
      
     if(f==0) {primes[n++] = i;
               if (i>MAX) break;}
     }
     
  //   printf("prime gen finished\n");
     //system("pause");
    res[0]=1;
    for(i=0;i<n;i++)
    {
   //  printf("prime %d (%d of %d)-->\n",primes[i],i,n);
    // for(j=0;j<MAX;j++) printf("%d ",res[j]);
    // printf("\n");
     for(j=MAX;j>=0;j--)
      if (res[j]>0)
      {
     //  printf("catch %d \n",j);
       for(k=j+primes[i];k<=MAX;k+=primes[i])
        {
        res[k]++;
      //  printf("mark %d ",k);
        }
    //   printf("<end>\n"); 
      } 
    }   
        
/*    FILE *stream;
    stream = fopen("C:\\DOCUME~1\\STUDEN~1.116\\DESKTOP\\ABT\\answer1.cpp", "w+"); 
    int l=0;
    for(i=0;i<MAX;i++) {if (i==primes[l]) l++;
                       fprintf(stream,"%d,\n",res[i]%primes[l]);
                       printf("%d,\n",res[i]%primes[l]);
                       }
     printf("end\n",n);
     fclose(stream); */
     printf("%d\n",res[MAX]%primes[n-1]);
   // system("pause");
    return 0;
}
