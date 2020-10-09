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

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int C, N, M;
int dp[51][1001];

// int count(int row) {
//     int ret = 0;
//     for(int i = 0; i < N; i++) {
//         ret += (dp[row][i] + C - 1) / C;
//     }
//     return ret;
// }

ll sumRow(int row) {
    ll ret = 0;
    for(int i = 0; i < 51; i++) {
        ret += dp[row][i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");
    cin >> C >> N >> M;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        dp[0][a]++;
    }

    for(int i = 0; i < 51; i++) {
        for(int j = 1; j <= C; j++) {
            if(j <= C/2) {
                dp[i+1][j*2] += dp[i][j];
            } else {
                dp[i+1][j] += dp[i][j]*2;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        cout << sumRow(a) << "\n";
    }

    

    // for(int i = 1; i <= M; i++) {
    //     for(int j = 0; j < N; j++) {
    //         dp[i][j] = dp[i-1][j] * 2;
    //     }
    // }

    // for(int i = 0; i < M; i++) {
    //     int row; cin >> row;
    //     cout << count(row) << "\n";
    // }

    return 0;
}