#include<iostream>
#include<string>
using namespace std;
string a[10],b[10000];
string es;
int cmp (string x, string y)
{
    return x<y;
}

int main()
{
    string ts,tss;
    int m,n,i,j,k;
    cin>>m>>n;
    for (i=0;i<m;i++)
        {
        a[0]=es;
        for (j=0;j<n;j++)
                {cin>>ts;
                a[0]+=ts;}
        //cout<<a[0]<<" "<<endl; //system("pause");
        int t=0,r;
        for (r=1;r<4;r++)
            {a[r]=a[r-1];
            t=0;
            for (j=n-1;j>=0;j--)
                for (k=j;k<(n*n);k+=n)
                    {//cout<<"sa"<<a[r][t]<<" "<<a[r][k]<<"    ";
                    a[r][t]=a[r-1][k];
                    t++;
                    }
            }
        //for (j=0;j<4;j++) cout<<"obr:"<<a[j]<<endl;
        a[r]=a[r-1];
        for (j=0;j<n;j++)
                {
                for (k=0;k<n;k++)
                    {//cout<<"saAS"<<k<<" "<<j*n+(n-k-1)<<"    ";
                    a[r][j*n+k]=a[r-1][j*n+(n-k-1)];
                    t++;
                    }
                }
        //cout<<"raaa";
        //cout<<a[4]<<endl;
        r++;t=0;       
        for (;r<8;r++)
            {a[r]=a[r-1];
            t=0;
            for (j=n-1;j>=0;j--)
                for (k=j;k<(n*n);k+=n)
                    {//cout<<"sa"<<a[r][t]<<" "<<a[r][k]<<"    ";
                    a[r][t]=a[r-1][k];
                    t++;
                    }
            }
        
        sort(a,a+8,cmp);
        
        b[i]=a[0];
        //cout<<"kr:"<<a[0]<<endl;
    }
    sort(b,b+m,cmp);
    int br=0;
        for (i=0;i<m-1;i++)
            {if(b[i]!=b[i+1]) br++;}
        cout<<br+1<<endl;
        return 0;
    
}
