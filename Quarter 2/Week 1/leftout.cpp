#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

#define mp make_pair
#define sz(x) (int)x.size()

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

char mat[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");

    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            cin >> mat[i][j];
        }
    }

    int rows[1000];
    int cols[1000];

    for(int i = 0; i < t; i++) {
        int rowCR = 0, rowCL = 0;
        int colCR = 0, colCL = 0;

        for(int j = 0; j < t; j++) {
            if(mat[i][j] == 'R') rowCR++;
            if(mat[i][j] == 'L') rowCL++;
            if(mat[j][i] == 'R') colCR++;
            if(mat[j][i] == 'L') colCL++;
        }

        if(rowCR == 1) row
        if(rowCL == 1) rows[i] == -1;
        if(colCR == 1) cols[i] == 1;
        if(colCL == 1) cols[i] == -1;
    }

    for(int i = 0; i < t; i++) {
        cout << rows[i] << " ";
        cout << cols[i] << " ";
    }

    int r = 0;
    int c = 0;

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++ ){
            if(rows[i] == 0 || rows[j] == 0) continue;
            if(rows[i] == cols[j]) {
                r = i + 1;
                c = j + 1;
                break;
            }
        }
    }

    cout << r << " " << c << "\n";
}