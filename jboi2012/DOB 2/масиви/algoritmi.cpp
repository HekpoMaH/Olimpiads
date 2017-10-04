//алгоритми с масиви
#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;//n-броя на числата, които ще въведем
    //въвеждане на числата
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    cout<<endl;
    //извеждане на числата
    for(int i=0;i<n;i++)
    {
            cout<<a[i]<<" ";
    }    
    cout<<endl;
    //сума на масив
    int s=0;
    for(int i=0;i<n;i++)
    {
            s+=a[i];
    }    
    cout<<s<<endl;
    //произведение на масив
    int p=1;
    for(int i=0;i<n;i++)
    {
            p*=a[i];
    }    
    cout<<p<<endl; 
    //наи- голям елемент и наи- малък елемент на масив
    int max=a[0],min=a[0];
    for(int i=0;i<n;i++)
    {
            if(a[i]>max){max=a[i];}
            if(a[i]<min){min=a[i];}
    }    
    cout<<max<<" "<<min<<endl;
    //търсене на елемент по стоиност
    int x;
    cin>>x;
    int num;
    int l=0;
    int i=0;
    while(i<n&&l==0)
    {
            
            if(x==a[i]){    
                            l=1;
                            num=i;
                       }
            i++;
    }
    if(l==0){cout<<"No"<<endl;}
    else{cout<<"Yes"<<" "<<x<<" "<<num<<endl;}
    system("pause");
    return 0;
}
            
                   
