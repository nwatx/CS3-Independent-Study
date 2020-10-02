#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector

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
    for(int z = 0; z < n; z++) {
        int m, t; cin >> m >> t;
        vt<int> line(m);
        vt<bool> ret(m);
        vt<bool> visited(m);
        for(int i = 0; i < m; i++) {
            cin >> line[i];
        }

        for(int i = 0; i < sz(line); i++) {
            if(!visited[i]) {
                for(int j = 1; j < sz(line); j++) {
                    if(!visited[j] && ((line[i] + line[j]) != t)) {
                        ret[i], ret[j], visited[i], visited[j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < sz(ret); i++) {
            if(i == 0) {
                cout << ret[i];
            } else {
                cout << " " << ret[i];
            }
        }
        cout << "\n";
    }
}