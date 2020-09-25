#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; cin >> n;

    for(int t = 0; t < n; t++) {
        int digits, num; cin >> digits >> num;

        int ee = 0;
        int eo = 0;
        int oe = 0;
        int oo = 0;

        for(int i = 0; i < digits; i++) {
            int rem = num % 10;
            if(i % 2 == 0) {
                if(rem % 2 == 0) {
                    ee++;  
                } else {
                    eo++;
                }
            } else {
                if(rem % 2 == 0) {
                    oe++;
                } else {
                    oo++;
                }
            }
            num /= 10;
        }

        if((ee + eo) > (oe + oo)) {
            if(ee > eo) {
                cout << 2 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else {
            if(oe > oo) {
                cout << 2 << "\n";
            } else {
                cout << 1 << "\n";
            }
        }
        
    }
}