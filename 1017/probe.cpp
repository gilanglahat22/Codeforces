#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> bits_count(30, 0);
        for (int num : a) {
            for (int j = 0; j < 30; ++j) {
                if (num & (1LL << j)) {
                    bits_count[j]++;
                }
            }
        }
        ll max_sum = 0;
        for (int num : a) {
            ll sum = 0;
            for (int j = 0; j < 30; ++j) {
                if (num & (1LL << j)) {
                    sum += (ll)(n - bits_count[j]) * (1LL << j);
                } else {
                    sum += (ll)bits_count[j] * (1LL << j);
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        cout << max_sum << '\n';
    }

    return 0;
}