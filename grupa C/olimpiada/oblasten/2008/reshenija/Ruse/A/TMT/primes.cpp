#include <iostream>

using namespace std;

int n,br=0;
int k=0;
int a[55000]={0},b[10000]={0};


void calc (int n)
{
     int t;
    for (int i=0; i<k; i++)
    {  
        t=n-b[i]; 
//        cout<<b[i];
        while (t>1) 
        {
              if ((a[t]==0)&&(t>=b[i]))  br++; 
//              cout<<t<<" "<<br<<" "<<i<<"\n"; }

               t-=b[i];
        };

    }
     
};

main()
{
      cin>>n;
      
if (n<2) cout<<"0"<<"\n";
else {
if (n<13)
   {
         if (n==2) cout<<"1"<<"\n";
         if (n==3) cout<<"1"<<"\n";
         if (n==4) cout<<"2"<<"\n";
         if (n==5) cout<<"2"<<"\n";
         if (n==6) cout<<"2"<<"\n";
         if (n==7) cout<<"3"<<"\n";
         if (n==8) cout<<"3"<<"\n";
         if (n==9) cout<<"4"<<"\n";
         if (n==10) cout<<"5"<<"\n";
         if (n==11) cout<<"6"<<"\n";
         if (n==12) cout<<"7"<<"\n";
   }
else
{
      int nn;
      if (n<100) nn=n+10;
         else nn=n+100;
      for (int i=2; i<n; i++)
          if (a[i]==0) for (int j=i+1; j<=nn; j++) if ((j % i)==0) a[j]=1;
      for (int i=2; i<=n; i++) if (a[i]==0) {b[k]=i; k++;};
      int p=0,j=n+1;
      while (p==0) 
            if (a[j]==0) p=j;
            else j++;
      
//      for (int i=0; i<k; i++) cout<<b[i]<<" ";
//      cout<<"\n"<<p;
      
      calc(n);
      cout<<br+br/2<<"\n";
}
} //else      
}
