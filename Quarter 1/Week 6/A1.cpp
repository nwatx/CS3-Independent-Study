#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ar array
#define ll long long
#define vt vector

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

int x = 1;

// bool cmp(pair<int, int> &a, pair<int,int> &b) {
//     if(a.first / x == b.first / x)  {
//         return a.second > b.second;
//     } else {
//         return a >= b;
//     }
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int n; cin >> n >> x;
        vector<pair<int, int>> line;
        for(int j = 1; j <= n; j++) {
            int a; cin >> a;
            //line.push_back(make_pair(a, j));
            line.push_back(make_pair((a - 1) / x + 1, j));
        }

        //sort(line.rbegin(), line.rend(), cmp);
        sort(line.begin(), line.end());

        
        for(int z = 0; z < sz(line); z++) {
            if(z == 0) {
                cout << "Case #" << i+1 << ": " << line[z].second;
            } else {
                cout << " " << line[z].second;
            }
        }
        cout << "\n";
    }
    return 0;
}