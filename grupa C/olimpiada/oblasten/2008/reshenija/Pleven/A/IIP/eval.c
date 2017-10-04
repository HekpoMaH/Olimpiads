#include <stdio.h>

#define pause system("pause")
//#define fi 

 char s[32];
 int n;
 
 int fact(int a)
 {
  int res=1;
  for(;a>1;a--)
   res*=a;    
  return res;    
 }
 
 int recurs(char *t,int l)
 {
  int i,j,r=0,v=0;
  char k[16];
  
  printf("t %s\n",t);
  
  if(l==1)return 1;
  
  for(i=0;i<l;i++)
  {
   if(t[i]=='-' && ((i>0 && t[i-1]!='-') || i==0)){
    r=0;
    for(j=0;j<l;j++)
     if(j!=i){
      k[r++]=t[j];
     }
   }
   else {
    for(j=i;i<l;j++)
     if(t[j]!='-')break;
      else {
       for(r=j;r<l;r++)t[r]=t[r+1]; 
        //printf("ch %c ",s[i]); 
       j--; 
       l--;          
      }
        
    r=0;    
    for(j=0;j<l;j++)
     if(j!=i-1){
      k[r++]=t[j];      
     }
          
   }
   k[r]='\0';  
   v+=recurs(k,l-1);                  
  }
    
  return v;     
 } 
 
 int main()
 {
  FILE* fi=stdin; //=fopen("eval.txt","r");
  int i,j;
  
  if(!fi){printf("Error\n"); return 1;}
  
  fscanf(fi,"%s",s);
  n=strlen(s);

  for(i=0;i<n;i++)
   if(s[i]>='a' && s[i]<='z'){
    for(j=i;j<n;j++)s[j]=s[j+1]; 
    //printf("ch %c ",s[i]); 
    i--; 
    n--; 
  }
  
//  printf("%d\n",n);
  s[n]='\0';    
  
  for(i=0;i<n;i++)
   if(s[i]!='*')break;
  if(i==n){
   printf("%d\n",fact(n)); 
//   pause;
   return 0;
  }  
  
  for(i=0;i<n;i++)
   if(s[i]!='/')break;
  if(i==n){
   printf("1\n"); 
//   pause; 
   return 0;
  }
  
  for(i=0;i<n;i++)
   if(s[i]!='^')break;
  if(i==n){
   printf("1\n"); 
//   pause; 
   return 0;
  }  
  
  for(i=0;i<n;i++)
   if(s[i]=='(')break;
  if(i!=n){
   printf("2\n"); 
//   pause; 
   return 0;
  }

  for(i=0;i<n;i++)
   if(s[i]=='/' || s[i]=='*' || s[i]=='^'){
    for(j=i;j<n;j++)s[j]=s[j+1]; 
    i--; 
    n--; 
  }
  
//  printf("%d\n",n);
  s[n]='\0';    
  
  for(i=0;i<n;i++)
   if(s[i]!='-')break;
  if(i==n){
   printf("1\n"); 
//   pause; 
   return 0;
  }
  
  for(i=0;i<n;i++)
   if(s[i]!='+')break;
  if(i==n){
   printf("%d\n",fact(n)); 
//   pause;
   return 0;
  }

//    printf("%s\n",s);   
  
  //printf("%d\n",recurs(s,n));
  
  printf("%d\n",fact(n));   
  
//  pause;
     
  return;
 }
