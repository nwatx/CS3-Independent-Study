#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

void DBG() { cerr << "]" << endl; }
template<class T, class ...U> void DBG(const T& t, const U&... u) {
    cerr << t; if (sizeof...(u)) cerr << ", ";
    DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
            << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
    #define dbg(...) 0
    #define chk(...) 0
#endif

int N;

const int MX = 1001;

int A[MX][MX];
int B[MX][MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    F0R(i, N) F0R(j, N) { cin >> A[i][j]; B[j][i] = A[i][j]; }

    int ret = 0;
    int curr = 0;

    F0R(i, N) {
        int oS = 0;
        int eS = 0;

        F0R(j, N) {
            if(j % 2) oS += A[i][j];
            else eS += A[i][j];           
        }

        curr += max(oS, eS);
    }

    curr = 0;
    
    F0R(j, N) {
        int oS = 0;
        int eS = 0;

        F0R(i, N) {
            if(i % 2) oS += A[i][j];
            else eS += A[i][j];           
        }

        curr += max(oS, eS);
    }
    ret = max(ret, curr);

    curr = 0;
    
    F0R(j, N) {
        int oS = 0;
        int eS = 0;

        F0R(i, N) {
            if(i % 2) oS += B[i][j];
            else eS += B[i][j];           
        }

        curr += max(oS, eS);
    }
    ret = max(ret, curr);

    cout << ret;
}