#include <iostream>
using namespace std;
int n;
int line[10000];
bool twin = false;
int now = 0;

bool checkpal(int mid)
{
      bool isall = true;
      for(int i = 0; i <= n/2; i++)
      {
            if(line[mid - i] != line[mid + i]) {isall = false; break;}
      }
      return isall;
}

int findpal(int mid)
{
      int lenght = 0, checks;
      if(mid%2 == 1 &&mid > n/2+1) checks = n - 1 -mid;
      else if( mid%2 == 1 &&mid <= n/2+1) checks = mid;
      else if (mid%2 == 0 && mid < n/2) checks = mid;
      else if (mid%2 == 0 && mid >= n/2) checks = n - 1 - mid;
      //cout << "checking " << checks << " at " << mid << "result ";
      for(int i = 1; i <= checks; i++)
      {
            if(line[mid-i] == line[mid + i]) {lenght++; if(mid + lenght - 1 == n) {twin = true; return lenght;}}
            else break;
      }
      int len = 0;
      for(int i = 0; i <= checks - 1; i++)
      {
            if(line[mid - i] == line[mid + i + 1]) {len++; if(mid+len - 1 == n) {twin = false; return len;}}
            else break;
      }
      if(len > lenght){twin = false; return len;}
      else {twin = true; return lenght;}

}

int main()
{
      cin >> n;
      int pals[n], divisions[n];
      for(int i = 0; i < n; i++) {cin >> line[i]; pals[i] = 0; divisions[i] = 0;}
      if(n == 3 && line[0] == line[2]) {cout << "1"; return 0;}
      if(n%2 != 0 && n != 3) {

            if(checkpal(n / 2) == true) {cout << "1"; return 0;}
      }
      else{
      bool ispal = true;
      for(int i = 0; i < n/2; i++) if(line[i] != line[n-1 - i]) {ispal = false; break;}
      if(ispal == true) {cout << "1"; return 0;}
      } // nachalni proverki
      pals[0] = 1;
      if(line[1] == line[0]) pals[0] = 2;
      if(line[0] == line[2]) pals[0] = 3;
      pals[n - 1] = 1;
      if (line[n - 1] == line[n - 2]) pals[n-2] = 2;
      if (line[n - 1] == line[n - 3]) pals[n-3] = 3;
      int count = 0;
      while(n != -1){
            if(n == 0) count++;
            pals[0] = 1;
            int calco = 0;
            for(int i = 0; i < n; i++) pals[i] = 0;
            for(int i = 0; i < n; i++) {
            findpal(i);
            if(twin == true){pals[i - findpal(i)] = 2*findpal(i) + 1;}
            else{pals[i - findpal(i) + 1] = 2*findpal(i);}
            }//zadavane na maks. st-sti na pals
            int last;
            for(int i = 0; i < n; i++) {
                  //cout << i << " " <<pals[i] << endl;
            }
            for(int i = 0; i < n; i++) {
                  if(pals[i] + i == n) {last = i; count++; break;}
            }

            n = last - 1;
            divisions[now] = last + calco;
            //if(now > 0) divisions[now]++;
            now++;
            twin = false;
      }
      cout << count  << endl;
      for(int i = count; i >= 0; i--) if(divisions[i] != 0)cout << divisions[i] << " ";


      return 0;
}
