/*
TASK: diet
LANG: C++
*/
#include<cstdio>
#include<algorithm>

using namespace std;

int f(int a)
  {
  if(a%3==0)return (a/3*2);
  if(a%3==1)return (a/3*2+1);
  if(a%3==2)return (a/3*2+2);
  }
int g(int a)
  {
  if(a%3==0)return (a/3*2);
  if(a%3==1)return (a/3*2+1);
  if(a%3==2)return (a/3*2+1);
  }
int init(int c1,int*a,int*A)
  {
  if(*a<c1)
    {
    *A=c1-*a;
    *a=0;
    }
  else 
    {
    *A=0;
    *a=*a-c1;
    }
  return 0;
  }

int main()
  {
  int a,b,c,c1,c2,A,B,C,ans=0;
  scanf("%d %d %d",&a,&b,&c);
  
  c1=(a*1+b*2+c*3)/6;
  
  init(c1,&a,&A);
  init(c1,&b,&B);
  init(c1,&c,&C);
  
       if(b==0 && c==0)
    {
    ans=0;
    }
  else if(a==0 && b==0)
    {
    c2=min(A,B);
    A-=c2;
    B-=c2;
    ans+=c2;
    ans+=f(A);
    ans+=f(B);
    }
  else if(a==0 && c==0)
    {
    ans+=(A+C+1)/2;
    }
  else if(a==0)
    {
    c2=b*2;
    if(c2>=A)
      {
      ans+=(A+1)/2;
      }
    else
      {
      A-=c2;
      ans+=b;
      ans+=f(A);
      }
    }
  else if(b==0)
    {
    c2=a/2;
    a%=2;
    if(c2<B)
      {
      B-=c2;
      if(a)ans+=g(B);
      else ans+=f(B);
      }
    else 
      {
      ans=0;
      }
    }
  else if(c==0)
    {
    c2=min(a,min(b,C));
    C-=c2;
    b-=c2;
    a-=c2;
    if(b)ans+=(C+1)/2;
    }
  printf("%d %d\n",c1,ans);
  return 0;
  }  


