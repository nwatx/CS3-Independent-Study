#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

typedef pair<int,int> pii;
typedef pair<long, long> pll;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub uppber_bound

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

int sizes[MAX_N];
int parent[MAX_N];
int cities;
int largest = -INF;

int find(int a) {
    if(a != parent[a]) {
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void unite(int a, int b) {
    if(a==b) return;
    else {
        int rA = find(a);
        int rB = find(b);
        if(rA == rB) return;
        if(rand() % 2) {
            parent[rA] = rB;
            sizes[rA] += sizes[rB];
            sizes[rB] = sizes[rA];
        } else {
            parent[rB] = rA;
            sizes[rB] += sizes[rA];
            sizes[rA] = sizes[rB];
        }
        if(rA != rB) {
           cities--; 
        }

        largest = max(sizes[rA], largest);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");

    int N,M; cin >> N >> M;
    cities = N;
    for(int i = 0; i < MAX_N; i++) {
        parent[i] = i;
    } 

    fill(begin(sizes), begin(sizes)+MAX_N, 1);

    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        unite(a,b);
        cout << cities << " " << largest << "\n";
    }
}