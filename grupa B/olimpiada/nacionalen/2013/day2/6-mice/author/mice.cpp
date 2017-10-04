//Task: mice
//Author: Rusko Shikov

// ����� �������, ���������� ������ ���� ��� merge sort
// �� ������ �� ���������� � ���������

#include <cstdio>

const int nmax=100001;
int h[nmax];
int a[nmax], b[nmax];

int n,k;

void input()
{
  int i;
  scanf( "%d %d", &n, &k );
  for ( i = 1; i <= n; i++ )
	scanf( "%d", &h[i] );  
}

int merge(int a[], int beg, int mid, int end)
// ����� ��� ��������� �������� �� ������ �� ������ a ����� beg � end
// � � ci ���� ���������� ����� �������� �� ����� ��������. ����� ci.
{
  int ci=0;  
  int count, i1, i2, j;
  count=end-beg+1;
  i1=beg;
  i2=mid+1;
  j=1;
  while((i1<=mid) && (i2<=end))
  {
     if (a[i1]<a[i2]) 
       {
         b[j]=a[i1];i1++;  
       }
     else  
       {
         b[j]=a[i2];i2++;ci=ci+(mid-i1+1);  
       }
     j++;  
  }
  while (i1<=mid)
  {
     b[j]=a[i1];i1++;j++; 
  }
  while (i2<=end)
  {
     b[j]=a[i2];i2++;j++; 
  }
  for (j=1;j<=count;j++)
    a[beg+j-1]=b[j];
    
  return ci;  
}

int merge_sort(int a[], int beg, int end)
// ����� merge sort �� ������ �� ����� a ����� beg � end
// � ���� � ci ���������� � ���� ���� �� ������. ����� ci.
{
  int mid, ci=0;  
  if (beg==end) return 0;
  mid=(beg+end)/2;
  ci=ci+merge_sort(a, beg,mid);
  ci=ci+merge_sort(a, mid+1, end);
  ci=ci+merge(a, beg, mid, end);
  return ci;
}

bool checkinv(int line)
{
 // �������� � ����� a ���������� �� ����� h, ����� �� �� �������
 // ���� k, ���������� �� ���e�� line
 // ������� ��, ���� ��������� � ����������
 // ����� ����������� ��������� �� a � h
 // ����� false, ��� ����� �� ���������� � �������, � true - ��� � �����
  int i,j=0,ic,m;
  i=line;
  while (i<=n)
  {
     j++;
     a[j]=h[i];
     i=i+k; 
  }
  ic=merge_sort(a,1,j);
  m=line;
  for (i=1;i<=j;i++)
  {
     h[m]=a[i];
     m=m+k; 
  }
  return (ic%2==0);   
} 

int main()
{
   int i; 
   bool par,x;
   input();
   par=checkinv(1);
   x=par;
   for(i=2;((i<=k)&&(x==par));i++)
     x=checkinv(i);
   if (x!=par)
     printf("%d\n",0);
   else
   {
     for(i=1;i<n;i++)
       if (h[i]>h[i+1])
       {
         printf("%d\n",0);
         break;  
       } 
     if (i==n) printf("%d\n",1);    
   }    
   return 0; 
}