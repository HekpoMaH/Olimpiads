#include <stdio.h>

#define pause system("pause")
#define fi stdin
#define sq(x) (x)*(x)

 double points[512],t[512][512],precomp[512];
 
 int n,p;
 
 double calc(int l, int r)
 {
  int i;
  double sra=0,sum=0;
  
  if(l>r)return 10000000.0;
  
  //printf("%d %d",l,r);
  for(i=l;i<=r;i++)
   sra+=points[i];      
  
  sra/=(r-l+1);
  
//  printf("sra %lf\n",sra);
  
  for(i=l;i<=r;i++)
   sum+=sq(sra-points[i]);
  
 // printf("%lf\n",sum);
  
  return sum;        
 }
 
 void dp()
 {
  int i,j,g;
  double tmp;
  //pause;
//  printf("\n \n");
  for(i=0;i<n-1;i++)
  {
   t[0][i]=calc(0,i); //+calc(i+1,n-1);
   //printf("%lf %lf \n",calc(i+1,n-1),calc(0,i));
  }
   
   
  for(i=1;i<p-1;i++)
  {
   for(j=i;j<n-1;j++)
   {
    t[i][j]=t[i-1][j];
//    printf("t %lf\n",t[i][j]);
    for(g=0;g<j;g++)
    {
     tmp=calc(g+1,j); //printf("tmp %lf\n",tmp);
     if(t[i-1][g]+tmp<t[i][j])t[i][j]=tmp+t[i-1][g];                
    }
//    printf("t %lf\n",t[i][j]);
   }
   
  }
  
//  for(i=0;i<n;i++)
//   printf("%lf ",t[p-2][i]);
  
  tmp=t[p-2][0]+precomp[0];
  for(i=1;i<n-1;i++)
   if(tmp>precomp[i]+t[p-2][i])tmp=precomp[i]+t[p-2][i];
   
  printf("%.4lf\n",tmp);
      
  return;     
 }
 
 void prec()
 {
  int i,j;
//  double r;
  //pause;
//  printf("%d\n ",n);
  for(j=0;j<n-2;j++)
  {
   precomp[j]=calc(j+1,n-1);
   //printf("%lf ",precomp[j]);
  }
   return;     
 }
 
 int main()
 {
  FILE *f=fi;
  int i;

  if(!f){printf("Fatal Error\n"); pause;}

  fscanf(f,"%d %d",&n,&p);

  for(i=0;i<n;i++)
  {
   fscanf(f,"%lf",&points[i]);   
  // printf("%lf ",points[i]);
  }

  prec();
  //pause;
  dp();   
     
  //pause;
  
  return 0;
 }
