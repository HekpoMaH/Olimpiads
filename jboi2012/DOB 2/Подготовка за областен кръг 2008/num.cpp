//num
#include<iostream>
using namespace std;
int main()
{
    long int m;
    long int s=0;
    long int min=10000,r,c,num,br=0;
    cin>>m;
    while(s<10000)
    {
                  cin>>c;
                  br++;
                  s=s+c;
                  r=abs(m-c);
                  if(r<min){
                            min=r;
                            num=br;
                            }
        }
     cout<<num<<endl;
     system("pause");
     return 0;
     }   
