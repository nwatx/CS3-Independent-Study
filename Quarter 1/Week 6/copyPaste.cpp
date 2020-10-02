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

    int t; cin >> t;
    for(int i = 0; i < t ; i++) {
        int n, k; cin >> n >> k;
        vector<int> line(n, 0);
        for(int j = 0; j < n; j++) {
            cin >> line[j];
        }

        int ret = 0;

        sort(line.begin(), line.end());

        for(int i = 1; i < sz(line); i++) {
            if(line[i] > k) break;
            ret += (k-line[i])/line[0];
        }

        // while(true) {
        //     //cout << "i: " << i << " " << line[0] << "\n";
        //     if(line[0] < k) {
        //         if(line[1] + line[0] > k) break;
        //         line[1] += line[0];
        //         ret++;
        //     } else {
        //         break;
        //     }
        // }

        cout << ret << "\n";
    }
}