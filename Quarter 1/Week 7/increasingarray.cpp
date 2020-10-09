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

    int tc; cin >> tc;
    vector<int> a(tc);
    
    for(int i = 0; i < tc; i++) {
        cin >> a[i];
    }

    long long ret = 0;

    for(int i = 1; i < a.size(); i++) {
        if(a[i] < a[i-1]) {
            ret += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }

    cout << ret;
}