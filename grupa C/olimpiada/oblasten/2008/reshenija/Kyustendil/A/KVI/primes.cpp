// primes.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<conio.h>
using namespace std;
int Prosto(int x)
{int j;
	cin>>x;
    j=2;
	while(x%j!=0)
	{j++;}
	if(j==x) return x;
}
int main()
{int n,S=1,p=0,A[50000],x,i=0,j=1,C=0,D;
	cin>>n;
	for(x=2;x<n;x++)
	{j=2;
	while(x%j!=0)
	{j++;}
	if(j==x){i++;A[i]=x;}
	}
	int k=i;
	int m=(n/A[1])-1;
	for(int q=1;q<k;q++)
	    for(j=0;j<m;j++)
 	       for(i=0;i<k;i++)
	          {C=0;
		       C=(m-j)*A[q]+A[i];
               if(C==n)S++;
	    }
	p=n;x=1;
	do{p++;
       j=1;
	   do{j++;}while(p%j!=0);
	    if(j==p)x=p;
	  }while(x==1);
	D=S%p;
	cout<<D;
//	getch();
	return 0;
}

