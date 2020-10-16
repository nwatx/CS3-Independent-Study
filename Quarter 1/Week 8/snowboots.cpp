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

int N, B, F[250], S[250], D[250];
bool beenthere[250][250];  // set of (location, boot) states we can reach

int solve(void) {
    for(int b = 0; b < B; b++) {
        for(int i = 0; i < N; i++) {
            if(F[i] > S[b]) { beenthere[i][b] = false; continue; }
            //cout << weights[i] << " ";
            if (i==0 && b==0) beenthere[i][b] = true;

            for(int i2 = 0; i2 < i; i2++) {
                if(beenthere[i2][b] && i2+D[b] >= i)  { beenthere[i][b] = true; }
            }

            for(int b2 = 0; b2 < b; b2++) {
                //cout << "fires";
                if(beenthere[i][b2]) beenthere[i][b] = true;
            }

            if(i==N-1 && beenthere[i][b]) {
                return b;
            }
        }
    }
}
     
int main(void)
{
    setIO("snowboots");
   
   cin >> N >> B;
   for (int i=0; i<N; i++) cin >> F[i];
   for (int i=0; i<B; i++) cin >> S[i] >> D[i];

   cout << solve() << "\n"; 
   return 0;
}