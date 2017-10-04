#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int getSmallestSimple(int n);
vector<int> getAllSimpleNumbers(int n);

int main(int argc, char *argv[])
{
    int n = 0;
    int p = 0;
    int S = 0;
    
    cout << "N = ";
    cin >> n;
    
    vector<int> simple;
    simple = getAllSimpleNumbers(n);
    
    p = getSmallestSimple(n);   
        
    for(int i = simple.size() - 1; i >= 0;i--)
    {    
        int current_sum = simple[i];
        int j = i;
        for(int j = i;j >= 0;j--)
        {
                int current_num2 = simple[j];
             for( ; ; )
             {
                if(current_sum + current_num2 == n || current_sum + current_num2 < n - 1)
                {
                    current_sum += current_num2; 
                }
                else
                    break;
                
                
                
                if(current_sum == n)
                {
                   S++;
                   current_sum = simple[i];
                   break;
                }
    
             }
        }      
    }
        cout << S % p << endl;
    system("PAUSE");
    
    return 0;
}
vector<int> getAllSimpleNumbers(int n)
{
     vector<int> simple;       
    /* Looping to n - 1 because the lowest simple number is 2 and we require
    at least two numbers for combination to exist */
    for(int i = 0; i < n - 1;i++)
    {
         int j = 2;
         for(j = 2;j <= n;j++)
         {
            if( i % j == 0)
               break;
         }  
         if( i == j)
             simple.push_back(i); 
    }    
    
    return simple;       
}
int getSmallestSimple(int n)
{
    for(int i = n+1; i < 50000;i++)
    {
         int j = 2;
         for(j = 2;j <= 50000;j++)
         {
            if( i % j == 0)
               break;
         }  
         if( i == j)
             return i;
     }
}

