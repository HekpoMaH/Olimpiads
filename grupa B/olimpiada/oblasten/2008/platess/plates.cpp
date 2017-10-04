#include<cstdio>

const int M_max=1000;
const int N_max=30;

int t[M_max+1][N_max+1][N_max+1];
int u[M_max+1];

int M,N;

void input()
{
 scanf("%d%d",&M, &N);  
// printf("M=%d N=%d\n",M,N);  
 for(int c=1;c<=M;c++)
 for(int i=1;i<=N;i++)
 {
   char s[N_max];
   scanf("%s",s);
   for(int j=1;j<=N;j++)
    if(s[j-1]=='1') t[c][i][j]=1;
 }    
}

void sh(int i0, int j0, int& i, int& j)
{
  i=1+N-i0;
  j=j0;     
}

void sv(int i0, int j0, int& i, int& j)
{
  i=i0;
  j=1+N-j0;     
}

void sd(int i0, int j0, int& i, int& j)
{
  i=j0;
  j=i0;     
}

void ss(int i0, int j0, int& i, int& j)
{
  sd(i0,j0,i,j);
  i0=i; j0=j;
  sh(i0,j0,i,j);
  i0=i; j0=j;
  sv(i0,j0,i,j);
}


void trans(int n, int i0, int j0, int& i, int& j)
{
  switch(n)
  {
    case 1: sh(i0, j0, i, j); return;         
    case 2: sv(i0, j0, i, j); return;  
    case 3: sd(i0, j0, i, j); return;         
    case 4: ss(i0, j0, i, j); return;         
  }    
  
  sv(i0, j0, i, j);
  i0=i; j0=j;
  
  switch(n)
  {
    case 5: sh(i0, j0, i, j); return;         
    case 6: sv(i0, j0, i, j); return;  
    case 7: sd(i0, j0, i, j); return;         
    case 8: ss(i0, j0, i, j); return;         
  }    
}


bool same(int r, int k1, int k2)
{   
  for(int i=1;i<=N;i++)
  for(int j=1;j<=N;j++)
  { int it,jt;
    trans(r,i,j,it,jt);
    if(t[k1][i][j]!=t[k2][it][jt]) return false;
  }    
  return true;   
}


void reduce()
{
 for(int r=1;r<=8;r++)    
 for(int k2=2;k2<=M;k2++)
 if(u[k2]==0)
 for(int k1=1;k1<k2;k1++)
 { 
   if(u[k1]==0)
   if(same(r,k1,k2)) {u[k2]=1; break;}
 }     
     
}

int main()
{
  input();

  
  reduce();
  int c=0;
  for(int k=1;k<=M;k++) 
   { 
     if(u[k]==0) c++;
   }

  printf("%d\n",c);
  

}
