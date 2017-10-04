#include<iostream.h>
int main()
{
    int s,n,a[3000];
    cin >> s >> n;
    int b=0,w=0;
    for(int i=0;i<n;i++)
    cin >> a[i];
    for(int x=0;x<n;x++)
    {
            for(int y=0;y<n-1;y++)
            if(a[y]>a[y+1]) 
            {
                    int c=a[y+1];
                    a[y+1]=a[y];
                    a[y]=c;
            }               
    }
    do{s=s-a[n-1]; b=b+1;}
    while(s>=a[n-1]);
    int r=a[n-1]-s;
    for(int z=n-1;z>0;z--)
    {
            do{r=r-(a[z]-a[z-1]);w=w+1;} while(r>0);
            r=0-r; w=w-1;
            if(r==0) break; 
    }
    cout << b+w+1 << endl;
    return 0;
}    
