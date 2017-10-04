# include <iostream>
# include <cmath>
using namespace std;
int main ()
{
    int masiv[5000];
    long long a,b,k,p;
    cin >> a >> b >> k >> p;
    int s;
    int q,r;
    for (int i = 0 ; i <= k+p;i++)
    {
        
        if (a<b)
    
        { 
          q=a*10;
          s=q/b;
          masiv[i]=s;      
          a=q-s*b; 
         
        }
        else
        {
         s=a/b;
         masiv[i]=s;
         a=a-s*b;       
           }
                
        }
       for (int j=k-1 ; j<k+p-1; j++)
        {
            cout << masiv[j];}
         cout << endl;
         return 0;
          
          
}
