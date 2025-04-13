#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll m = *min_element(a.begin(), a.end());
    vector<ll> S;
    int cnt_m = 0;
    
    for (int i = 0; i < n; ++i) {
        ll x = a[i];
        if (x % m == 0) {
            S.push_back(x);
            if (x == m) {
                cnt_m++;
            }
        }
    }
    
    ll g = 0;
    for (int i = 0; i < S.size(); ++i) {
        g = gcd(g, S[i]);
    }
    
    if (g != m) {
        return false;
    }
    
    for (int i = 0; i < n; ++i) {
        ll x = a[i];
        if (x % m != 0 && x < m) {
            return false;
        }
    }
    
    if (cnt_m >= 2) {
        return true;
    } else {
        if (S.size() == 1) {
            return false;
        }
        vector<ll> S_prime;
        bool removed = false;
        for (int i = 0; i < S.size(); ++i) {
            ll x = S[i];
            if (x == m && !removed) {
                removed = true;
            } else {
                S_prime.push_back(x);
            }
        }
        ll g_prime = 0;
        for (int i = 0; i < S_prime.size(); ++i) {
            g_prime = gcd(g_prime, S_prime[i]);
        }
        return g_prime == m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "Yes" : "No") << '\n';
    }
    
    return 0;
}