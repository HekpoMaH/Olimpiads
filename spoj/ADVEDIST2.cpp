#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
using namespace std;
int H[1005][1005];
int DamerauLevenshteinDistance(string source, string target)
{   //memset(H,0,sizeof(H));
    int m = source.length();
    int n = target.length();
    
    if(m==0)
    {
        if (n==0) return 0;
        else      return n;
    }
    else if(n==0)
    {    return m;  } 
    
    int INF = m + n;
    
    H[0][0] = INF;
    for (int i = 0; i <= m; i++) { H[i + 1][ 1] = i; H[i + 1][ 0] = INF; }
    for (int j = 0; j <= n; j++) { H[1][ j + 1] = j; H[0][ j + 1] = INF; }
 
    map<char,int> sd; 
    for(int L=0;L<256;L++)
    {
        sd.insert(make_pair(char(L),0));
    }
    
    /*
    SortedDictionary<Char, int> sd = new SortedDictionary<Char, int>();
    foreach (Char Letter in (source + target))
    {
        if (!sd.ContainsKey(Letter))
            sd.Add(Letter, 0);
    }
    */
    for (int i = 1; i <= m; i++)
    {
        int DB = 0;
        for (int j = 1; j <= n; j++)
        {
            int i1 = sd[target[j - 1]];
            int j1 = DB;
 
            if (source[i - 1] == target[j - 1])
            {
                H[i + 1][ j + 1] = H[i][ j];
                DB = j;
            }
            else
            {
                H[i + 1][ j + 1] = min(H[i][ j], min(H[i + 1][ j], H[i][ j + 1])) + 1;
            }
 
            H[i + 1][ j + 1] = min(H[i + 1][ j + 1], H[i1][ j1] + (i - i1 - 1) + 1 + (j - j1 - 1));
        }
 
        sd[source[i - 1]] = i;
    }
    for (int i = 1; i <= m+1; i++)
    {
        int DB = 0;
        for (int j = 1; j <= n+1; j++)
        {
           cout<<H[i][j]<<" ";
        }
        cout<<"\n";
 
        sd[source[i - 1]] = i;
    }
 
    return H[m + 1][ n + 1];
}
main()
{  string a,b;
   while(cin>>a>>b)
   {  if(a=="*" && b=="*") break;
      cout<<DamerauLevenshteinDistance(a,b)<<endl;
   } 
   //system("pause");
}
 
