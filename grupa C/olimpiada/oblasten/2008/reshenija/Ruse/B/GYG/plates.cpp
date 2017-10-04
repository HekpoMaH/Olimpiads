#include<iostream>
using namespace std;
int n,m;
int main(){
    int br=0;
    cin >> m >> n;
    char a[1024][32][32];
    for(int k=0;k<m;k++){
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) cin >> a[br][i][j];
            bool b=false;
            if(br==0) b=true;
            for(int l=0;l<br;l++){
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
     if(a[l][i][j]!=a[br][i][j]){b=true;break;}
     if(b==false) break;
     //cout << "PASS 1\n";system("pause");
     b=false;
     int i1=n-1,j1=n-1;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++){
           if(a[l][i][j]!=a[br][i1][j1]){b=true;break;}
           j1--;
           if(j1<0){i1--;j1=n-1;}
           }
     if(b==false) break;
     //cout << "PASS 2\n";system("pause");
     b=false;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
     if(a[l][i][j]!=a[br][j][i]){b=true;break;}
     if(b==false) break;
     //cout << "PASS 3\n";system("pause");
     b=false;
     i1=n-1;j1=n-1;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++){
           if(a[l][i][j]!=a[br][j1][i1]){b=true;break;}
           j1--;
           if(j1<0){i1--;j1=n-1;}
           }
     if(b==false) break;
     //cout << "PASS 4\n";system("pause");
     b=false;
     j1=n-1;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++){
           if(a[l][i][j]!=a[br][i][j1]){b=true;break;}
           j1--;
           if(j1<0) j1=n-1;
           }
     if(b==false) break;
     //cout << "PASS 5\n";system("pause");
     b=false;
     i1=n-1;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++){
           if(a[l][i][j]!=a[br][i1][j]){b=true;break;}
           if(j==n-1) i1--;
           }
     if(b==false) break;
     //cout << "PASS 6\n";system("pause");
     b=false;
     j1=n-1;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++){
           if(a[l][i][j]!=a[br][j1][i]){b=true;break;}
           j1--;
           if(j1<0) j1=n-1;
           }
     if(b==false) break;
     //cout << "PASS 7\n";system("pause");
     b=false;
     i1=n-1;
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++){
           if(a[l][i][j]!=a[br][j][i1]){b=true;break;}
           i1--;
           if(i1<0) i1=n-1;
           }//cout << "PASS 8\n";system("pause");
           }
                    
            if(b==true) br++;//cout << k << endl;
            }
    //for(int i=0;i<n;i++){
    //for(int j=0;j<n;j++) cout<<a[0][i][j];cout << endl;} 
    cout << br << endl;
    return 0;
}
