#include <bits/stdc++.h>
using namespace std;
long long t,n,a;
int main() {
	cin >> t;
    while(t--){
    	cin >> n;
    	long long minval=LLONG_MAX, maxval=0;
    	for(int i = 0; i<n; i++) {
    		cin >> a;
    		minval = min(minval, a);
    		maxval = max(maxval, a);
    	}
 
    	cout << maxval - minval << "\n";
    }
    return 0;
}