#include <stdio.h>
#include <stack>
#include <limits.h>
using namespace std;

const int nmax=1000000;         // максимален брой на подводниците


int sub_depth[nmax+1];          // масив с дълбочините на позициите на подводниците

int n,m;                        // брой на подводниците и брой на командите

int calc_sub_max()
{
  stack<int> st;
  int i,p;
  int sub_max=0;
      
  st.push(INT_MAX);
  
  for ( i = 1; i <= n; i++ )
  {
    p=0; 
    while ( st.top() < sub_depth[i] )
    {
      st.pop();
      p++;      
    }
    st.push(sub_depth[i]);
    if (p>sub_max)
      sub_max=p;
  }
  return sub_max;
}

int main()
{
  int i,c,x;  
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d",&sub_depth[i]);  
  for (i=1;i<=m;i++)  
  {
    scanf("%d",&c);
    if (c==0)
      printf("%d\n",calc_sub_max());
    else
      {
        x=sub_depth[c];
        sub_depth[c]=sub_depth[c+1];
        sub_depth[c+1]=x;          
      }    
  }    
  return 0;
}  