#include <bits/stdc++.h>

using namespace std;

#define vt vector

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}

int N;

pair<int, int> dp[101][101];
int A[101];


void solve(int n) {
    F0R(i, N) F0R(j, N) dp[i][j].second = 1000000007;
    // store two numbers (the current number and the cell diff)
    dp[0][0] = {0, A[0] != 0};
    FOR(i, 0, N+1) {
        FOR(j, 1, N+1) {
            int stay = dp[i][j-1].second + (dp[i][j-1].first + 1 == A[i] ? 0 : 1); 
            int reset = dp[i-1][j-1].second + (dp[i-1][j-1].first + 1 == A[i] ? 0 : 1);
            if(stay < reset) {
                dp[i][j] = {dp[i][j-1].first + 1, stay};
            } else {
                dp[i][j] = {0, reset};
            }
        }
    }

    F0R(i, N+1) {
        F0R(j, N+1) {
            cerr << dp[i][j].second << " ";
        }
        cerr << "\n";
    }


    F0R(i, N) {
        cout << dp[i+1][N-1].second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("taming");
    cin >> N;

    F0R(i, N) cin >> A[i];
    solve(0);
}