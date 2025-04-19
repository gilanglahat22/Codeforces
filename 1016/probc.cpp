#include <bits/stdc++.h>
using namespace std;
 
// Constants
const int MAX_SIEVE = 100000000;  // 10^8 - reasonable size for memory
const int SQRT_MAX_N = 31623;     // sqrt(10^9)
 
// For bit operations
#define GET_BIT(ar, i) (((ar[(i) >> 6]) >> (((i) >> 1) & 31)) & 1)
#define SET_BIT(ar, i) (ar[(i) >> 6] |= (1 << (((i) >> 1) & 31)))

vector<uint32_t> bitSieve;
vector<int> primes;

void computeSieve() {
    bitSieve.resize(MAX_SIEVE / 64 + 1, 0);

    for (int i = 3; i * i <= MAX_SIEVE; i += 2) {
        if (!GET_BIT(bitSieve, i)) {
            for (long long j = (long long)i * i; j <= MAX_SIEVE; j += 2 * i) {
                SET_BIT(bitSieve, j);
            }
        }
    }

    primes.push_back(2);

    for (int i = 3; i <= SQRT_MAX_N; i += 2) {
        if (!GET_BIT(bitSieve, i)) {
            primes.push_back(i);
        }
    }
}
 
bool isPrime(long long x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    
    if (x <= MAX_SIEVE) {
        return !GET_BIT(bitSieve, x);
    } else {
        for (int prime : primes) {
            if ((long long)prime * prime > x) break;
            if (x % prime == 0) return false;
        }
        return true;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computeSieve();
    
    int t;
    cin >> t;
    
    while (t--) {
        long long x, k;
        cin >> x >> k;
 
        cout << (((k==1 && isPrime(x)) || (x==1 && k==2)) ? "YES" : "NO") << endl;
    }
    
    return 0;
}