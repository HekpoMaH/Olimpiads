#include <iostream>

using namespace std;




/*
CHECKS
      checks are: 90 -90 180 Mir Mir90 Mir-90 Flip
      90          |  ni = n-j          nj = i    
      -90         |  ni = j            nj = n-i
      180         |  ni = n-i          nj = n-j
      Mir         |  mi=ni = i         mj=nj = n-j
      Mir90       |  ni = n-mj=j       nj = mi=i
      Mir-90      |  ni = n-j          nj = n-i
      Flip(Mir180)|  ni = n-i          nj = j

*/






int main() {
    int m, N, red, max=0, ident=1;
    cin >> m >> N;
     
    int plates[m][N][N];
    
    for (int i=0;i<m;i++) {
        for (int j=0;j<N;j++) {
            cin >> red;
            for (int p=N-1;p>=0;p--) {
                plates[i][j][p] = red%10;
                red /= 10;
            }                    
        }    
    } 
    
    for (int k=0;k<m;k++) {
        for (int p=k+1;p<m;p++) {
             
              bool idnidn = true;    
               // obhozda plo4kata        ident
                for(int i=0;i<N;i++) {
                   for (int j=0;j<N;j++) {
                     if (plates[k][i][j] != plates[p][i][j]) {
                        idnidn = false;
                           break;
                     }
                   }
              }
     
     bool idn90 = true;
     // obhozda plo4kata        90
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][N-j][i]) {
                  idn90 = false;
                  break;
               }
           }
     }

     
     bool idn_90 = true;
     // obhozda plo4kata        -90
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][j][N-i]) {
                  idn_90 = false;
                  break;
               }
           }
     }

     
     bool idn180 = true;
     // obhozda plo4kata        180
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][N-i][N-j]) {
                  idn180 = false;
                  break;
               }
           }
     }

     
     bool Miridn = true;
     // obhozda plo4kata        Mir
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][i][N-j]) {
                  Miridn = false;
                  break;
               }
           }
     }

     
     bool Mir90idn = true;
     // obhozda plo4kata        Mir90
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][j][i]) {
                  Mir90idn = false;
                  break;
               }
           }
     }

     
     bool Mir_90idn = true;
     // obhozda plo4kata        Mir-90
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][N-j][N-i]) {
                  Mir_90idn = false;
                  break;
               }
           }
     }

     
     bool Flipidn = true;
     // obhozda plo4kata        Flip
     for(int i=0;i<N;i++) {
           for (int j=0;j<N;j++) {
               if (plates[k][i][j] != plates[p][N-i][j]) {
                  Flipidn = false;
                  break;
               }
           }
     }


            
            if (idnidn || idn90 || idn_90 || idn180 || Miridn || Mir90idn || Mir_90idn || Flipidn) {
               ident +=1;
            }
            //cout << ident << endl;
            // Ako sa identi4ni ident+=1;      */    
        }
        
        if (ident>max) {
           max = ident;
        }
        
        ident=1;
    }
    
    cout << max << endl;
    /*
    for (int p=0;p<m;p++) {
         for (int i=0;i<N;i++) {
             for (int j=0;j<N;j++) {
                 cout << plates[p][i][j] << " ";
             }
             cout << endl;
         }
         cout << endl;
    }
    */
    

return 0;
}
