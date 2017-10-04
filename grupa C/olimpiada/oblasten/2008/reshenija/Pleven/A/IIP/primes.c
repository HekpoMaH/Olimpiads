#include<stdio.h>

#define pause system("pause")
#define fi stdin
//fopen("primes.txt","r")
 
 int primes[50008],np,mem[80008],p;
 
 void prime()
 {
	int i=7,j;
	primes[0]=2;
	primes[1]=3;
	primes[2]=5;
	np=3;
	for(;i<60008;i++)
	{
	 j=0;
	 while(j<np && i%primes[j]!=0)j++;
	 if(j==np){primes[np]=i;np++;}		
	}	
	
/*	for(i=0;i<np;i++)
	 printf("%d ",primes[i]);
	 */
	return;		
 }
 
 int count(int n)
 {
  int i,j,tmp;
  mem[0]=1;
  
  for(i=0;primes[i]<n;i++)
   for(j=0;j<n;j++)
   {
    tmp=j+primes[i];
    //if(tmp==n && mem[j])printf("%d\n",j);
    if(tmp<=n && mem[j]){mem[tmp]+=mem[j]; mem[tmp]%=p;}
   }
  
//  for(i=0;i<=n;i++)
//  printf("%d %d\n",i,mem[i]);
  
  return mem[n];
 }
 
 int main()
 {
  FILE *f=fi;
  int n,s,i;
  
  prime();
  
  //if(!f){printf("Fatal Error\n"); pause;}
  
  fscanf(f,"%d",&n);
  
  for(s=0;s<=n;s++)mem[s]=0;

  for(p=0;primes[p]<=n;p++);
  
  s=0;
//  if(n==primes[p-1])s--;
  p=primes[p];
  
  
//  printf("%d\n",p);
  
  s+=count(n);
  
//  printf("s %d",s);
  
//  for(i=0;i<=n;i++)
//   printf("%d ",mem[i]);
  
  s%=p;
  
  printf("%d\n",s);
  
//  pause;
  
  return 0;
 }
