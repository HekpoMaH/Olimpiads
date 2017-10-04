//Gadost
#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    int br=0,nk;
    if(n==1)
    {
    cout<<"     ((__))     "<<endl;
    cout<<"      (00)      "<<endl;
    cout<<"-NN--(O__O)--NN-"<<endl;
    cout<<"      ----      "<<endl;
    }
    
    if(n==2)
    {cin>>k;
    nk=k-2;
    cout<<"     ";
    for(int h=1;h<=nk;h++)
    {
            
            cout<<" ";
            }
    cout<<"((__))     "<<endl;
    cout<<"      ";
     for(int h=1;h<=nk;h++)
    {
             
            cout<<" ";
            }
    cout<<"(00)      "<<endl;
    cout<<"-";                           
    for(int i=1;i<=k;i++)
    {
        cout<<"n";
    }
    cout<<"--(o__o)--";
    for(int i=1;i<=k;i++)
    {
       
       cout<<"n";
    }
    cout<<"-"<<endl;
     cout<<"      ";
     for(int h=1;h<=nk;h++)
    {
            
            cout<<" ";
            }
    cout<<"----      "<<endl;
    }

    if(n==3)
    {
    cout<<"     ((^^))     "<<endl;
    cout<<"      (00)      "<<endl;
    cout<<"-nn--(o^^o)--nn-"<<endl;
    cout<<"      ----      "<<endl;
    }
    system("pause");
    return 0;
}
              
              
              
