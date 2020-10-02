#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector

const int MAX_N = 2e5 + 2;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

int apps[MAX_N];
vt<int> apts;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> apps[i];
        //cout << apps[i];
    }

    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        apts.push_back(a);
        //cout << apts[i];
    }

    int ret = 0;

    for(int i = 0; i < n; i++) {
        int index = -1;
        ll diff = LINF;
        if(sz(apts) == 0) break;
        for(int j = 0; j < sz(apts); j++) {
            ll currDiff = abs(1L * apps[i] - apts[j]);
            if(currDiff <= k) {
                if(currDiff < diff) {
                    //cout << "currDiff: " << currDiff << "\n";
                    index = j;
                    diff = currDiff;
                }
            }
        }
        
        if(index >= 0) {
            //cout << "Erased: " << index << "\n";
            apts.erase(apts.begin() + index);
            ret++;
        }
    }

    cout << ret << "\n";
}