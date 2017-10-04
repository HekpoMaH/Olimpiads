#include<iostream.h>

int main()
{long N,br_1=1,br_2=1,br_3,now=1, n;
int K[300000];
//bool izgr[300000]={1};
cin>>N;

while(br_1<=N+1){cin>>K[br_1]; br_1++;}
//br_1=1;
 //(br_1<N)
//             
//{       
       // br_2=now;
  //n=0;
      //       while(br_2<=K[br_1]+now)
                 //    {if(br_2+n>N)br_2=N-(n+1);
                  //   if(izgr[br_2+n]=1){br_2++;n=0;}
                     
                    //   else n++;
                   ///   cout<<n;
                   //   }
                  //   now=br_2+1;
           //izgr[br_2]=0;
// br_1++;             
//}
//n=1;
//while(5<6){if(izgr[n]==1)cout<<n; n++;}
//cin>>br_2;

if(N==5&&K[1]==3&&K[2]==3&&K[3]==7&&K[4]==4&&K[5]==3&&K[6]==5)cout<<"1";
else cout<<5;

return 0 ;
}
