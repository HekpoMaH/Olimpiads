//��������� � ������
#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;//n-���� �� �������, ����� �� �������
    //��������� �� �������
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    cout<<endl;
    //��������� �� �������
    for(int i=0;i<n;i++)
    {
            cout<<a[i]<<" ";
    }    
    cout<<endl;
    //���� �� �����
    int s=0;
    for(int i=0;i<n;i++)
    {
            s+=a[i];
    }    
    cout<<s<<endl;
    //������������ �� �����
    int p=1;
    for(int i=0;i<n;i++)
    {
            p*=a[i];
    }    
    cout<<p<<endl; 
    //���- ����� ������� � ���- ����� ������� �� �����
    int max=a[0],min=a[0];
    for(int i=0;i<n;i++)
    {
            if(a[i]>max){max=a[i];}
            if(a[i]<min){min=a[i];}
    }    
    cout<<max<<" "<<min<<endl;
    //������� �� ������� �� ��������
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
            
                   
