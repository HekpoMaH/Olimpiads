
/*
 * ihack solution
 *
 * Time: O(NK)
 * Memory: O(N)
 * Author: Emil Ibrishimov <emil.ibrishimov@gmail.com>
 */

#include <iostream>
#include <cstring>
#include <cassert>

const int MAX_N = 2000;
const int MOD = 30011;

int N, K;
int a[MAX_N]; // number of fingerprints in each column

// Reads N, K and a[]
void read_input() {
    memset(a, 0, sizeof a);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char fingerprint;
            std::cin >> fingerprint;
            if (fingerprint == '1') {
                ++a[j];
            } else {
                assert(fingerprint == '0');
            }
        }
    }
    std::cin >> K;
}

// Returns the number of password that start with a given direction
const int LEFT = -1;
const int RIGHT = 1;
int count_passwords(int start_direction) {
    assert(start_direction == LEFT || start_direction == RIGHT);

    int dir = start_direction; // current direction
    int f[MAX_N]; // f[j] contains the number of passwords that end at j
    int sum; // running sum of f[] up to j (inner loop optimization)
    // For K == 1, each fingerprint corresponds to exactly one password,
    // so initialize f[] to be equal a[]
    memcpy(f, a, sizeof a);

    for (int i = 0; i < K; ++i) {
        sum = 0;

        // Iterate from 0 to N-1 if dir is RIGHT or from N-1 to 0 if dir
        // is LEFT
        int j;
        if (dir == RIGHT) {
            j = 0;
        } else {
            j = N-1;
        }
         
        int new_f;
        while (j < N && j >= 0) {
            // compute the next f and advance the running sum
            new_f = sum * a[j] % MOD;
            sum = (sum + f[j]) % MOD;
            std::cout<<new_f<<" "<<sum<<" "<<a[j]<<" "<<f[j]<<"\n";
            f[j] = new_f;

            j += dir;
        }
         for(int k=0;k<N;k++)std::cout<<f[k]<<" ";std::cout<<"\n";
        // Invert direction for the next iteration to alternate fingers
        dir = -dir;
    }

    return sum;
}

int main() {
    read_input();

    int all_passwords = count_passwords(LEFT) + count_passwords(RIGHT);
    // If K == 1, we double count because single digit codes are the same
    // no matter which thumb you use
    if (K == 1) {
        assert(all_passwords % 2 == 0);
        all_passwords /= 2;
    }
    std::cout << all_passwords % MOD << std::endl;

    return 0;
}

