//triang
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b+c&&b<c+a&&c<b+a&&a!=b&&a!=c&&b!=c){
                                              cout<<a+b+c<<" "<<3<<endl;
                                              }
    if(a<b+c&&b<c+a&&c<b+a&&a==b&&b!=c&&a!=c||a!=b&&b==c&&a!=c||a!=b&&b!=c&&a==c){
                                                                                  cout<<a+b+c<<" "<<2<<endl;
                                                                                  }
    if(a<b+c&&b<c+a&&c<b+a&&a==b&&b==c&&a==c){
                                              cout<<a+b+c<<" "<<1<<endl;
                                              }
    if(a>b+c||b>a+c||c>a+b){
                            cout<<"No"<<endl;
                            }
    system("pause");
    return 0;
}                                          
