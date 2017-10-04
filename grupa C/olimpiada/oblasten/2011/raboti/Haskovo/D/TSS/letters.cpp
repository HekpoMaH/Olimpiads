#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int n;
char a;
string s1[10000];
string s2[10000];
string s3[10000];
string s4[10000];
int br[4];
bool l;
char makelittle(char a)
{
    int u = 'A' - 'a';
    a -= u;
    return a;
}
int main()
{
    cin >> n >> a;
    for(int i = 0;i < n;i++){
        cin >> s1[i] >> s2[i] >> s3[i] >> s4[i];
        for(int j = 0;j < s1[i].size();j++){
            if(s1[i][j] >= 'A' && s1[i][j] <= 'Z'){
                s1[i][j] = makelittle(s1[i][j]);
            }
        }
        for(int j = 0;j < s2[i].size();j++){
            if(s2[i][j] >= 'A' && s2[i][j] <= 'Z'){
                s2[i][j] = makelittle(s2[i][j]);
            }
        }
        for(int j = 0;j < s3[i].size();j++){
            if(s3[i][j] >= 'A' && s3[i][j] <= 'Z'){
                s3[i][j] = makelittle(s3[i][j]);
            }
        }
        for(int j = 0;j < s4[i].size();j++){
            if(s4[i][j] >= 'A' && s4[i][j] <= 'Z'){
                s4[i][j] = makelittle(s4[i][j]);
            }
        }
        if(s1[i][0] == a)br[0] ++;
        if(s4[i][s4[i].size()-1] == a)br[3]++;
        br[4] = 0;
        for(int j = 0;j < s2[i].size();j++){
            if(s2[i][j] == a)br[4]++;
        }
        if(br[4] != 0)br[1]++;
        br[4] = 0;
        for(int j = 0;j < s3[i].size();j++){
            if(s3[i][j] == a)br[4]++;
        }
        if(br[4] > 1)br[2]++;
    }
    cout << br[0] << " " << br[1] << " " << br[2] << " " << br[3] << endl;
    return 0;
}