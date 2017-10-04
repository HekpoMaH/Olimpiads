//PASSWD
#include<iostream>
using namespace std;
int main()
{
    long long int n,br=0,sc=0,snc=0;
    int c,min=9,max=0;
    cin>>n;
    while(n!=0)
    {
               c=n%10;
               if(c%2==0){br++;sc=sc+c;}
               else{snc=snc+c;}
               if(c<min){min=c;}
               if(c>max){max=c;}
               if(sc>=10){sc=sc%10+sc/10;}
               if(snc>=10){snc=snc%10+snc/10;}
               n=n/10;
    }
    cout<<br<<sc<<snc<<max-min<<endl;
    system("pause");
    return 0;
}
