#include<iostream>
using namespace std;
int main()
{
    int n,m,br=0;
    bool plate=false;
    cin >> m >> n;
    if((m<1)||(m>1000))return 0;
    if((n<1)||(n>30))return 0;
    int a[m][n][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++)
    {cin >> a[i][j][k];
    }
    /**********************************1**********************************/
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {      
            if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[i][l][k]==a[j][n-l][n-k])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************2**********************************/
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[i][l][k]==a[j][n-k][l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }  
    /**********************************3**********************************/
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[i][l][k]==a[j][k][n-l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************4**********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[i][n-l][n-k]==a[j][n-k][l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************5*********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[i][n-l][n-k]==a[j][k][n-l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************6**********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[j][n-k][l]==a[j][k][n-l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************7**********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[i][l][k]==a[i][l][k])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************8**********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[j][n-l][n-k]==a[j][n-l][n-k])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************9**********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[j][n-k][l]==a[j][n-k][l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    /**********************************10**********************************/    
    for(int i=0;i<m;i++)
    for(int j=m;j>=0;j--)
    {       if(plate==true)br++;
            plate=true;
            for(int l=0;l<n;l++)
            {if(plate==false)break;
                               for(int k=0;k<n;k++)
                               {       if(a[j][k][n-l]==a[j][k][n-l])plate=true;
                                       else {
                                            plate=false;
                                            break;
                                            }
                               }
            }
    }
    
    
    cout << br << endl;
   // system("pause");
    return 0;
}
