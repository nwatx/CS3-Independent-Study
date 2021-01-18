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

int N, Q;
int pfx[1001][1001];
int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    // comments are for implementation without arr

    F0R(i, N) {
        F0R(j, N) {
            char a; cin >> a;
            if(a == '*') arr[i+1][j+1]++; // pfx[i+1][j+1]++
        }
    }

    FOR(i, 1, N+1) {
        FOR(j, 1, N+1){ 
            pfx[i][j] = arr[i][j] + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
            // pfx[i][j] += pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        }
    }

    F0R(i, Q) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pfx[x2][y2] - pfx[x1-1][y2] - pfx[x2][y1-1] + pfx[x1-1][y1-1] << "\n";
    }
}