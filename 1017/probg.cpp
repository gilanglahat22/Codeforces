#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        deque<int> dq;
        long long sum_total = 0;
        long long S = 0;
        int current_length = 0;
        bool reversed = false;

        while (q--) {
            int s;
            cin >> s;
            if (s == 1) {
                int last_element;
                if (reversed) {
                    last_element = dq.front();
                    dq.pop_front();
                    dq.push_back(last_element);
                } else {
                    last_element = dq.back();
                    dq.pop_back();
                    dq.push_front(last_element);
                }
                S += sum_total - last_element * current_length;
                cout << S << '\n';
            } else if (s == 2) {
                S = sum_total * (current_length + 1) - S;
                reversed = !reversed;
                cout << S << '\n';
            } else {
                int k;
                cin >> k;
                current_length++;
                sum_total += k;
                S += k * current_length;
                if (reversed) {
                    dq.push_front(k);
                } else {
                    dq.push_back(k);
                }
                cout << S << '\n';
            }
        }
    }

    return 0;
}