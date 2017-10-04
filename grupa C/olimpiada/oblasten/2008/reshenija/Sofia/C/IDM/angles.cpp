#include<iostream>
using namespace std;
int arr[1000][1000],n,k,x,y;
int angle(int a,int b)
{
    int i,j=b,sum=arr[a][b];
    j=b;
    for( i=a;i<=a+k;i++)
    sum=sum+arr[i][j];
    j=a;
    for(i=b;i<=b+k;i++)
    sum=sum+arr[i][j];
    return sum;
}
int main()
{
    int i,j,max=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       {
          cin>>arr[i][j];
          }
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       {
          if(angle(i,j)>max)
          {
             max=angle(i,j);
             x=i;y=j;
          }
       }
    cout<<x+1<<" "<<y+1<<endl;
    system("pause");
    return 0;
}
          
    
    
