//Task: salaries
//Author: Rusko Shikov
//Solution: O(N)
#include<bits/stdc++.h>
using namespace std;

const int nmax=100000;
const int smax=100000;

int sal[2][nmax+2];
vector<int> salgroups[2][smax+1];
int b[nmax+2];
int ukb;
int n;
int salgroups_count[2];

void clear_salgroups(int p)
{
    int i;
    for (i=1;i<=smax;i++)
      salgroups[p][i].clear();
    salgroups_count[p]=0;  
}

void make_salgroups(int p, int k)
{
    int i;
    clear_salgroups(p);
    for (i=1;i<=n;i++)
    {
      salgroups[p][sal[k][i]].push_back(i);  
      if (salgroups[p][sal[k][i]].size()==1) salgroups_count[p]++;
    }
}


bool compare_salgroups()
{
    int i,j;
    int sal0=300, sal1=300;
    if (salgroups_count[0]!=salgroups_count[1]) return false;
    for (i=1;i<=salgroups_count[1];i++)
    {
        while (salgroups[0][sal0].size()==0) sal0++;
        while (salgroups[1][sal1].size()==0) sal1++;
        if (salgroups[0][sal0].size()!=salgroups[1][sal1].size()) return false;
        for (j=0;j<salgroups[0][sal0].size();j++)
          if (salgroups[0][sal0][j]!=salgroups[1][sal1][j]) return false;
        sal0++;sal1++;  
    }
    return true;
      
}


void input()
{
  int i;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&sal[0][i]);  
}

int main()
{
  //clock_t begin, end;
  //double time_spent;

 // begin = clock();
/* here, do your time-consuming job */

  int i,j,k=0,it=0;
  bool finish=false;
  bool eq;
  input();
  
  make_salgroups(0,0);
  
  while (!finish)
  {        
    ukb=n;
    b[n]=sal[k][n];
    sal[1-k][n]=sal[k][n];
    eq=true;
    it++;
    for (i=(n-1);i>0;i--)
    {
       j=ukb;
       while ((j<=n) && (sal[k][i]>=b[j])) j++;
       if (j<=n)
       {
         sal[1-k][i]=(sal[k][i]+b[j])/2;   
         ukb=j-1; b[ukb]=sal[k][i];        
       }
       else
       {
         sal[1-k][i]=sal[k][i];  
         ukb=n; b[n]=sal[k][i];  
       }   
       if (sal[0][i]!=sal[1][i]) eq=false;    
    }
    k=1-k;
    
    if (eq || (it==13))
    {
      finish=true;
    }
    else
    {
       make_salgroups(1,k);
       if (!compare_salgroups()) finish=true;  
    }      
  }
  
  for (i=1;i<=n;i++)
    printf("%d\n", sal[1-k][i]);
    
  //printf("%d\n",it);
  //end = clock();
  //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  //cout << time_spent;
  return 0;
}
