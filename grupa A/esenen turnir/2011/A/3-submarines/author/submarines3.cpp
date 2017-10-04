#include <stdio.h>
#include <stack>
#include <math.h>
#include <string.h>
#include <limits.h>
using namespace std;

const int nmax=1000000;         // ���������� ���� �� ������������
const int maxbittree=2097152;   // ���������� ������ �� ����� �� ������� �������� ����� � n �����

int bit_depth[maxbittree];      // ����� �� �������� ����� � ����������� �� ��������� �� ������������
                                // �� �� �������� �� RMQ (Range Maximum Query)
                                
int bit_sr_sum[maxbittree];     // ����� �� �������� ����� � ���� ���������� ������� �� ������������
                                // �� ������ ������� - �� �� �������� �� �������� �� ������ �� ������������ �������
                                // �� ���������� �� ������� �� i �� j 
                                
int bit_sr_max[maxbittree];     // ����� �� �������� ����� � ���� ���������� ������� �� ������������ ��
                                // ������ ������� - �� �� �������� �� �������� �� ���-������� ����
                                // ���������� �� ���������� ������� - ��� �� ���� � bit_sr_max[1].

int n,m;                        // ���� �� ������������ � ���� �� ���������

int n2;                         // ������� � �������� �� �������� �������, �� ����� �������� �������

void change_bit_depth(int i, int v) // ������� �� ������� ����������� �� ������������ �� ������� i-�� RMQ
{                                   // ������ ��������� �� �������� � ��������� v
   int j;
   j=n2+i-1; 
   bit_depth[j]=v;
   j=j/2;
   while (j>0)
   {
     if (bit_depth[2*j]<bit_depth[2*j+1])
       bit_depth[j]=bit_depth[2*j+1];
     else
       bit_depth[j]=bit_depth[2*j];
     j=j/2;    
   } 
}

void change_bit_sr_max(int i, int v) // ������� �� ������� ���� �� ���������, ���������� �� 
{                                    // ���������� �� ������� i - �� �������� �� ���������� ����;
   int j;                            // ������ ���� �� �������� � ��������� v
   j=n2+i-1; 
   bit_sr_max[j]=v;
   j=j/2;
   while (j>0)
   {
     if (bit_sr_max[2*j]<bit_sr_max[2*j+1])
       bit_sr_max[j]=bit_sr_max[2*j+1];
     else
       bit_sr_max[j]=bit_sr_max[2*j];
     j=j/2;    
   } 
}

void change_bit_sr_sum(int i, int v) // ������� �� ������� ���� �� ���������, ����������
{                                    // �� ���������� �� ������� i - �� �������� �� ������ �� ���������;
                                     // ������ ���� �� �������� � ��������� v
  int x,j;
  j=n2+i-1; 
  x=v-bit_sr_sum[j];
  bit_sr_sum[j]=v;
  j=j/2;
  while (j>0)
  {
    bit_sr_sum[j]=bit_sr_sum[j]+x;
    j=j/2;  
  }
}

int rmq_depth(int i, int j)         // �������, ����� ����� ���-�������� ��������� �� ����������,  
{                                   // �������� �� �� ������� � ��������� [i,j]
   int md; 
   int ki, kj;
   ki=n2+i-1;
   kj=n2+j-1;
   md=bit_depth[ki];
   if (md<bit_depth[kj])
     md=bit_depth[kj];
   while (ki != kj)
   {
     if (ki%2 == 1) 
     {
       ki++;
       if (ki<kj)
         if (md<bit_depth[ki])
           md=bit_depth[ki];  
     } 
     if (ki<kj)
     {    
       if (kj%2 == 0)
       {
         kj--;
         if(ki<kj)
           if (md<bit_depth[kj])  
             md=bit_depth[kj];
       }
     }
     if (ki<kj)
     {
       ki=ki/2;
       if (md<bit_depth[ki])
         md=bit_depth[ki];
       kj=kj/2;
       if (md<bit_depth[kj])
         md=bit_depth[kj]; 
     }
   }
   if (md<bit_depth[ki])
     md=bit_depth[ki];
   return md;  
}

int find_right(int i)               // �������, �������� ���-�������� ������� �� i �������,
{                                   // �� ����� ����� ���������� �� ��-������ ��������� ��
                                    // ���� �� ������� i. ��� ���� ������, �� ����� 0.
  int beg, end, k,s;
  k=n2+i-1;
  
  if (i == n)  
    return 0;
  else
  {
    beg=i+1;
    end=n;       
    if (rmq_depth(beg,end)<bit_depth[k]) 
      return 0;
    else
    {
      while (beg<end)
      {
        s=(beg+end)/2;               
        if (rmq_depth(beg,s)>bit_depth[k])
        {
          if (beg == s)
            return s;
          else
          {
            if (rmq_depth(beg,s-1)>bit_depth[k])
              end=s-1;
            else
              return s;
          }
        }           
        else
          beg=s+1;    
      }
      return beg;  
    }     
  }  
}                                    

int find_left(int i)                // �������, �������� ���-�������� ������ �� i �������,
{                                   // �� ����� ����� ���������� �� ��-������ ��������� ��
                                    // ���� �� ������� i. ��� ���� ������, �� ����� 0.
  int beg, end, k,s;
  k=n2+i-1;
  if (i == 1)  
    return 0;
  else
  {
    beg=1;
    end=i-1;
    if (rmq_depth(beg,end)<bit_depth[k]) 
      return 0;
    else
    {
      while (beg<end)
      {
        s=(beg+end)/2;        
        if (rmq_depth(s,end)>bit_depth[k])
        {
          if (rmq_depth(s+1,end)>bit_depth[k]) 
            beg=s+1;
          else
            return s;   
        }
        else
          end=s-1;
      }
      return beg;
    }     
  }  
}                      

int calc_sr_sum(int i, int j)       // �������, �����, ��� �������� ������� i<=j �����
{                                   // ������ �� ������ �������, �������� �� ����������
   int k;                           // �� ������� �� i+1 �� j-1; ��� i>=j-1, ����� 0
   int si=0, sj=0;                  // � si �� �������� ������ �� ���������, �������� ��
                                    // ���������� �� ������� �� 1 �� i; � sj �� ��������
                                    // ������ �� ���������, �������� �� ���������� �� 1 �� j-1
                                    // ��������� �������� � s=sj-si.
   if (i>=(j-1))  
     return 0;
   else
     {
       k=n2+j-1;                    // ���������� �� sj
       while (k>1)
       {
         if ((k%2)==1)              // ��� ��� � ����� ���,
           sj=sj+bit_sr_sum[k-1];   // �������� ���������� �� ����� �� ����
         k=k/2;  
       }
                                    // ���������� si
       k=n2+i;                      // ���� ���� �� ������, ����� �� ������ �� ������� i+1
       while (k>1)
       {
         if ((k%2)==1)
           si=si+bit_sr_sum[k-1];
         k=k/2;    
       } 
       return sj-si; 
     } 
}

void init()
{
  stack<int> st;
  int i,d,p;
  memset(bit_depth,0,maxbittree);
  memset(bit_sr_max,0,maxbittree);
  memset(bit_sr_sum,0,maxbittree);
  
  scanf("%d%d",&n,&m);  
  n2=log2(n);
  n2=1<<n2;
  if (n2<n)
    n2 = 2*n2;
    
  st.push(INT_MAX);
  
  for ( i = 1; i <= n; i++ )
  {
    scanf("%d", &d);
    change_bit_depth(i,d); 
    p=0; 
    while ( st.top() < d )
    {
      st.pop();
      p++;      
    }
    st.push(d);
    if (p>0)
    {
      change_bit_sr_max(i,p); 
      change_bit_sr_sum(i,p); 
    }
      
  }
}




int main()
{
  int i,j,command,x,y,z,r;  
  init();
  for (i=1;i<=m;i++)
  {
    scanf("%d", &command);
    if (command == 0)
      printf("%d\n", bit_sr_max[1]);
    else
    {
      j=n2+command-1;
      x=bit_depth[j]; 
      r=find_right(command+1); 
           
      change_bit_depth(command, bit_depth[j+1]); 
      change_bit_depth(command+1,x); 
      
      if (bit_depth[j]>bit_depth[j+1]) 
      {
        x=bit_sr_max[j]+bit_sr_max[j+1]-1;
        change_bit_sr_max(command+1,0);
        change_bit_sr_max(command,x);
        change_bit_sr_sum(command+1,0);
        change_bit_sr_sum(command,x);
        x=find_right(command+1);
        if (x>0)
        {
          change_bit_sr_max(x, bit_sr_max[n2+x-1]+1);
          change_bit_sr_sum(x, bit_sr_sum[n2+x-1]+1);  
        }          
      } 
      else
      {
        x=find_left(command);
        y=(command-x-1)-calc_sr_sum(x,command);
        z=bit_sr_sum[n2+command-1]-y+1;        
        change_bit_sr_max(command,y);
        change_bit_sr_max(command+1,z);
        change_bit_sr_sum(command,y);
        change_bit_sr_sum(command+1,z);        
        if (r>0)
        {
          change_bit_sr_max(r,bit_sr_max[n2+r-1]-1);
          change_bit_sr_sum(r,bit_sr_sum[n2+r-1]-1);  
        }
          
      }
    }    
  }
  return 0;
}  