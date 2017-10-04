#include <stdio.h>
#include <string.h>
char rebus[1028];
int values[26];
int digits[10];
char left[1024],right[1024],ne[1024];
char res[5];

void add(char *s)
{
   int q=0,x,i;
   for(i=1023;i>=1;i--)
   {
      x=s[i]+ne[i]+q;
      q=x/10;s[i]=x%10;
   }
}
int main(int argc, char *argv[])
{
   FILE *in,*ou,*log;
   int i,j,k,l,n;
   if (argc != 4)
   { printf("Argument number error \n");
     return 0;
   }

   // input file
   if((in=fopen(argv[1],"r"))==NULL)
   { 
     printf("Cannot open input file \n");
     return 0;
   }
   fscanf(in,"%s",rebus);
   fclose(in);
   n=strlen(rebus);rebus[n]='.';
   for(i=0;i<26;i++) values[i]=-2;
   for(i=0;i<10;i++) digits[i]=0;
   for(i=0;i<n;i++) values[rebus[i]-'A']= -1;
   for(j=0;j<1024;j++) left[j]=right[j]=0;

   // log file
   log=stdout;//fopen(argv[4],"w");
   
   // output file
   if((ou=fopen(argv[2],"r"))==NULL)
   { 
     fprintf(log,"0\n");
     fprintf(log,"No output file!\n");
     return 0;
   }
   while((i=fscanf(ou,"%s",res))!= -1)
   {
      if(strlen(res)!=3) 
      { 
        fprintf(log,"0\n");
        fprintf(log,"Wrong line length!\n");
        return 0;
      }
      if(res[0]<'A'||res[0]>'Z'||res[1]!='='||res[2]<'0'||res[2]>'9') 
      { 
        fprintf(log,"0\n");
        fprintf(log,"Illegal character!\n");
        return 0;
      }
      if(values[res[0]-'A']==-2) 
      { 
        fprintf(log,"0\n");
        fprintf(log,"Letter is not in the rebus!\n");
        return 0;
      }
      if(values[res[0]-'A']!= -1) 
      { 
        fprintf(log,"0\n");
        fprintf(log,"Letter %c redefined!\n",res[0]);
        return 0;
      }
      if(digits[res[2]-'0']!=0) 
      { 
        fprintf(log,"0\n");
        fprintf(log,"Repeted digit!\n");
        return 0;
      }
      else {values[res[0]-'A']=res[2]-'0';digits[res[2]-'0']=1;} 
   }

   i=0;int sgn=1;int flag=0;
   while(1)
   {
      for(j=0;j<1024;j++) ne[j]=0;
      j=i;while(rebus[j]>='A'&&rebus[j]<='Z'){j++;}
	  l=1023;for(k=j-1;k>=i;k--) 
	  	  ne[l--]=values[rebus[k]-'A'];

      if(flag==0) if(sgn==1) add(left); else add(right);
      else if(sgn==1) add(right); else add(left);
      if(rebus[j]=='+')sgn=1;
      if(rebus[j]=='-')sgn=-1;
      if(rebus[j]=='='){sgn=1;flag=1;}
	  if(rebus[j]=='.')break;
	  i=j+1;
   }
   for(j=0;j<1024;j++)
      if(left[j]!=right[j])
      { 
        fprintf(log,"0\n");
        fprintf(log,"Wrong assignement!\n");
        return 0;
      }
    fprintf(log,"10\n");
    fprintf(log,"OK!\n");
 
 return 0;
   
}

