#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    
    int t; cin >> t;
    while(t--){
        string num; cin >> num;
        int sz = num.size();
        int countZero = 0;
        int maxZero = 0;
        for(int i = 0; i<sz; i++){
            if(num[i]=='0'){
                countZero++;
            }else{
                maxZero = max(maxZero, countZero);
            }
        }
        cout << sz - maxZero - 1 << "\n";
    }
 
    return 0;
}