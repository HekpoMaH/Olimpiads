#include <iostream>

using namespace std;

int main()
{
    int n,s=0;
    cin>>n;
    int a[n+2][n+2];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    int p=n-1,br=0,k=0;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<p;j++)
            {
                    if(a[i][j]==a[n-j-1][n-i-1])br++;
            }
    }
   if(br==n*n-n)
   {
                 for(int i=0;i<n;i++)
                 {
                        for(int j=0;j<n;j++)
                        {
                                if(k==0){if(a[i][j]%3==0&&a[i][j]){cout<<a[i][j];k++;}}
                                else {if(a[i][j]%3==0&&a[i][j])cout<<" "<<a[i][j];}
                        }
                }
  }
  else
  {
      for(int i=0;i<n;i++)
      {
              for(int j=0;j<n;j++)
              if((i+1)%2==1)s=s+a[i][j];
      }
      cout<<s;
  }
  cout<<"\n";
  

    
    
    
   
    return 0;
}
