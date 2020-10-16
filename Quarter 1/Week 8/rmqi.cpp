#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

#define mp make_pair
#define sz(x) (int)x.size()

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int st[MAX_N][21];
int lg[MAX_N+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    lg[1]=0;

    for(int i = 2; i <= MAX_N; i++) {
        lg[i] = lg[i/2]+1;
    }
    
    //setIO("");

    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> st[i][0];
    }

    for(int j = 1; j <= 21; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i+ (1<<(j-1))][j-1]);
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < 10; j++) {
    //         cout << st[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 0; i < q; i++) {
        int lhs, rhs; cin >> lhs >> rhs;
        lhs--; rhs--;
        int j = lg[rhs-lhs+1];
        int minimum = min(st[lhs][j], st[rhs-(1<<j)+1][j]);
        cout << minimum << "\n";
    }
}