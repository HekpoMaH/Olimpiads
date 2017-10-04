//gadost
#include<iostream>
using namespace std;
int main()
{
    int k,kod;
    cin>>kod;
    if(kod==1){
               cout<<"     ((__))"<<endl;
               cout<<"      (00)"<<endl;
               cout<<"-NN--(O__O)--NN-"<<endl;
               cout<<"      ----"<<endl;
               }
    if(kod==3){
               cout<<"     ((^^))"<<endl;
               cout<<"      (00)"<<endl;
               cout<<"-nn--(o^^o)--nn-"<<endl;
               cout<<"      ----"<<endl;
              }
    if(kod==2)
    {
              cin>>k;
              int x=k-2;
              for(int i=1;i<=x+5;i++) cout<<" ";
              cout<<"((__))"<<endl;
              for(int i=1;i<=x+6;i++) cout<<" ";
              cout<<"(00)"<<endl;
              cout<<"-";
              for(int i=1;i<=k;i++) cout<<"n";
              cout<<"--(o__o)--";
              for(int i=1;i<=k;i++) cout<<"n";
              cout<<"-"<<endl;
              for(int i=1;i<=x+6;i++) cout<<" ";
              cout<<"----"<<endl;
    }
    system("pause");
    return 0;
}
