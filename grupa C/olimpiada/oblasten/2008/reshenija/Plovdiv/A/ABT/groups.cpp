#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;
struct razlika { float d; int n;};
int operator <  (razlika a, razlika b)
{
         return a.d<b.d;
}

int operator ==  (razlika a, razlika b)
{
         return a.d==b.d;
}

priority_queue <razlika> r;
razlika all[512];
float points[512],s[512],d[512],eps=0.00001,ss[512];
int n,p,l;

float calc()
{
float res=0,s; int i,j,br;
/*printf("calc ->\n");
for(i=0;i<(n-1);i++)
    {
      printf("%.3f ",d[i]);
    }
printf("\n");    */
for(i=0;i<n;i++)
 if (d[i]==0) 
   {j=i;

    s=points[i];br=1;
    while (((--j) >=0) && d[j]!=0) {s+=points[j];br++;}
    s=s/(float)br;
   // printf("begin -> end = %d->%d \n",i,(i-br+1));
    for(j=(i-br+1);j<=i;j++) res+=(s-points[j])*(s-points[j]);
    }
//printf("\n res %.3f\n",res);
return res;    
}


float calc_2(int k)
{
float res=0,s; int i,j,begin,end,br;
i=k-1;
while(d[i]!=0 && i>=0) i--;
begin = i+1;
i=k+1;
while(d[i]!=0 && i<n) i++;
end = i;
//printf("calc v2 begin=%d, k=%d, end=%d\n",begin,k,end);
s=points[begin];br=1;
for(i=begin+1;i<=k;i++) {s+=points[i];br++;}
s=s/(float)(br);
for (j=begin;j<=k;j++)res+=(s-points[j])*(s-points[j]);

//printf("res1->%.4f\n",res);
s=points[k+1];br=1;
for(i=k+2;i<=end;i++) {s+=points[i];br++;}
s=s/(float)(br);
for (j=k+1;j<=end;j++)res+=(s-points[j])*(s-points[j]);

//printf("res1->%.4f\n",res);

for(i=0;i<begin;i++)res+=ss[i];
 //printf("res1->%.4f\n",res);
for(i=end+1;i<n;i++)res+=ss[i];
// printf("res1->%.4f\n",res);
return res;    
}

void recalc(int k)
{
float res=0,s; int i,j,begin,end,br;
i=k-1;
while(d[i]!=0 && i>=0) i--;
begin = i+1;
i=k+1;
while(d[i]!=0 && i<n) i++;
end = i;
//printf("recalc v2 begin=%d, k=%d, end=%d\n",begin,k,end);
s=points[begin];br=1;
for(i=begin+1;i<=k;i++) {s+=points[i];br++;}
s=s/(float)(br);
res=0;
for (j=begin;j<=k;j++)res+=(s-points[j])*(s-points[j]);
for (j=begin;j<=k;j++)ss[j]=(s-points[j])*(s-points[j]);

//printf("res1->%.4f\n",res);
s=points[k+1];br=1;
for(i=k+2;i<=end;i++) {s+=points[i];br++;}
s=s/(float)(br);
res=0;
for (j=k+1;j<=end;j++)res+=(s-points[j])*(s-points[j]);
for (j=k+1;j<=end;j++)ss[j]=(s-points[j])*(s-points[j]);
d[k]=0;
//res+=s;
//printf("res1->%.4f\n",res);

}



int main()
{
    scanf("%d%d",&n,&p);
    int i;
    float sredno;
    for(i=0;i<n;i++)
     scanf("%f",&points[i]);
     razlika temp;
    for(i=0;i<(n-1);i++)
    {
      d[i]=points[i+1]-points[i];
      temp.d=d[i];
      temp.n=i;
      r.push(temp);
    }
d[n-1]=0;
//n=500;p=499;
sredno=0;
float otg;
for(i=0;i<n;i++)sredno+=points[i];
sredno=sredno/(float)n;
for(i=0;i<n;i++)ss[i]=sredno;

float max=0,t,res,min,f;
int pos;
p--;
while(p!=0)
{
max=0;
l=0;
all[l++]=r.top();
r.pop();

while((r.top()==all[0])&& (!r.empty()))
{
all[l++]=r.top();
r.pop();
}


 f=0;
for(i=0;i<l;i++)
   {
 //  printf("probvame %d\n", all[i].n);
   t=d[all[i].n];
   d[all[i].n]=0;
   //res=calc();
   res=calc_2(all[i].n);
//   printf("%.4f %.4f\n",res,calc_2(all[i].n));
  // system("pause");
   if (f==1) if (res<min) {min=res;pos=all[i].n;}
   if (f==0) {min=res;f=1;pos=all[i].n;}
   d[all[i].n]=t;
   }
d[pos]=0; 
for(i=0;i<l;i++) if (all[i].n!=pos) r.push(all[i]);
/*printf("mahame %d\npredi:\n",pos);
for(i=0;i<n;i++) printf("%.3f ",ss[i]);
printf("\nsled:\n");*/
recalc(pos);
/*for(i=0;i<n;i++) printf("%.3f ",ss[i]);
printf("\n");*/
p--;
}
     
    
printf("%.4f\n",min);    
//system("pause");
    return 0;
}
