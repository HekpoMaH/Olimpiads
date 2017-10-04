#include<iostream>
using namespace std;
int main()
{
    double x,y;
    int s=0;
    cin>>x>>y;
    while(x<=3&&x>=-3&&y<=3&&y>=-3)
    {
                                   if(((x>=-3&&x<-2)||(x<=3&&x>2))||((y>=-3&&y<-2)||(y>2&&y<=3)))s+=2;
                                   else{
                                        if(((x>=-2&&x<-1)||(x<=2&&x>1))||((y>=-2&&y<-1)||(y>1&&y<=2)))s+=5;
                                        else{
                                             if(x>=-1&&x<=1&&y>=-1&&y<=1)s+=10;
                                             }
                                        }
                                   cin>>x>>y;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
