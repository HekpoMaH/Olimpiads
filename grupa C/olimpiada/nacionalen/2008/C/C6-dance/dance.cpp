  #include<iostream>
  using namespace std;
  
  int main()
  {
  int x, y, i, j, temp ;
  long long t[101];

  cin>>x>>y;
  if (x>y) {temp=x; x=y; y=temp;}

  if (x%2 || y%2) { cout<<0<<endl; return 0;}
    
  x/=2;
  y/=2;
  for (i=0; i<=y; i++)
      t[i]=1;
  for (i=1; i<=y; i++)
      for (j=1; j<=x; j++)
          t[j]=t[j-1]+t[j];
      
  cout<<t[x]<<endl;

  return 0;
  }
