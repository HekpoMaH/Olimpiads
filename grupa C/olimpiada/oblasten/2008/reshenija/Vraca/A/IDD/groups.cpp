#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;


int main()
{
    float numbers[500];
    int n,p;
    cin >> n >> p;
    for(int i=0; i<n; ++i)
            cin >> numbers[i];
    
    float diffs[500];
    
    diffs[0] = 0;
    for(int i = 1; i < n; ++i)
    {
            diffs[i] = numbers[i] - numbers[i-1];
    }
    
    int marked[500];
    for(int i = 0; i < n; ++i)
            marked[i] = 0;
    
    
    while(p)
    {
            int md = 0;
            for(int i=2; i < n; ++i)
            {
                    if(diffs[i] > diffs[md] && !marked[i])
                                md = i; 
            }
            //cout << "marking " << md << " : " << numbers[md-1] << " - " << numbers[md] << endl;
            marked[md] = 1;
            --p;
    }
    
    float d=0,ms=0;
    int count=0 , s = 0;
    for(int i = 0; i < n; ++i)
    {
            //cout << "num " << numbers[i] << "MS " << ms << endl;
            if(!marked[i+1])
            {
                        count++;
                        ms+=numbers[i];
            }
            else
            {
                float ma = ms/count;
                                cout << ma << endl;
                for(int k=s; k < i; ++k)
                        d+= (ma - numbers[i]) * (ma - numbers[i]);
                count = 1;
                s = i;
                ms = numbers[i];
            }
    }
    
    cout << d << endl;
          
  //  for(int i = 1; i < n; ++i)
    //        cout << diffs[i] << " ";
            
    
//    system("pause");
    
}
