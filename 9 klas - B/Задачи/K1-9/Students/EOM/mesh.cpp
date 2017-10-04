#include<iostream.h>
long long z,t,x,y,a,b,c,i,j,k,br;
int main()
{ cin>>z>>t;
  if (z>t) { x=z;y=t;}
  else { x=t;y=z;}
  a=0-y;
  b=x-0;
  c=0;
  i=1;
  j=1;
  br=1;
  while(1!=2)
  { k=a*i+b*j+c;
    if (k>0) 
    { br++;
      if (i<x) i++;
      else j++;
    }
    else
    if (k<0) 
    { br++;
      if (j<y) j++;
      else i++;
    }
    else
    if (k==0) 
    { br+=2;
      //if (i<x && j<y) {i++;j++;}
     // else
      if (j<y) j++;
      else
      if (i<x) i++;
    }
    if (i==x && j==y) break;
  }
  cout<<br<<endl;
return 0;
}
  
