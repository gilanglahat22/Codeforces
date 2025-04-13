#include <bits/stdc++.h>
using namespace std;
 
const int MAX_A = 1e5 + 5;
vector<int> spf;
 
void sieve() {
    spf.resize(MAX_A);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < MAX_A; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_A; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
 
vector<pair<int, int>> factor(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        res.emplace_back(p, cnt);
    }
    return res;
}
 
inline int power(int p, int exp) {
    int res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= p;
    }
    return res;
}
 
int main() {
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<vector<pair<int, int>>> a_factors(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a_factors[i] = factor(x);
        }
        while (q--) {
            int k, l, r;
            cin >> k >> l >> r;
            l--; r--;
 
            auto primes_k = factor(k);
            unordered_map<int, int> prime_counts;
            for (auto &[p, cnt] : primes_k) {
                prime_counts[p] = cnt;
            }
 
            int current_k = k;
            long long sum = 0;
 
            for (int i = l; i <= r; ++i) {
                const auto &factors = a_factors[i];
                bool has_all = true;
                for (const auto &[p, _] : factors) {
                    if (!prime_counts.count(p)) {
                        has_all = false;
                        break;
                    }
                }
                if (!has_all) {
                    sum += current_k;
                    continue;
                }
 
                int e_max = INT_MAX;
                for (const auto &[p, e_p] : factors) {
                    int available = prime_counts[p];
                    e_max = min(e_max, available / e_p);
                }
 
                if (e_max == 0) {
                    sum += current_k;
                    continue;
                }
 
                int divisor = 1;
                for (const auto &[p, e_p] : factors) {
                    divisor *= power(p, e_p * e_max);
                }
 
                current_k /= divisor;
                sum += current_k;
 
                for (const auto &[p, e_p] : factors) {
                    prime_counts[p] -= e_p * e_max;
                    if (prime_counts[p] == 0) {
                        prime_counts.erase(p);
                    }
                }
            }
            cout << sum << '\n';
        }
    }
    return 0;
}