#include <bits/stdc++.h>

using namespace std;

#define ar array
#define vt vector
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a, x) for (auto& a : x)

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef pair<double, double> pd;

typedef vt<int> vi;
typedef vt<ld> vd;
typedef vt<ll> vl;
typedef vt<pi> vpi;
typedef vt<pl> vpl;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int d4i[] = {0, 1, 0, -1}; int d4j[] = {1, 0, -1, 0};
char d4c[] = {'R', 'D', 'L', 'U'};

int N, M;
char maze[1000][1000];
int prevs[1000][1000];
vpi monsters;
pi start;
vpi exits;

bool inBounds(int a, int b) {
    return !(a < 0 || b < 0 || a >= N || b >= M);
}

int dist(int i, int j, bool a, int eI, int eJ) {
    queue<pi> q;
    bool visited[1000][1000]; memset(visited, 0, sizeof visited);
    vt<vi> dist(1000, vi(1000, 0));
    q.push(mp(i, j));
    while(!q.empty()) {
        pi curr = q.front(); q.pop();
        visited[curr.f][curr.s] = true;
        if(maze[curr.f][curr.s] == '#' || maze[curr.f][curr.s] == 'M') continue;
        F0R(k, 4) {
            if(curr.f == eI && curr.s == eJ) return dist[eI][eJ];
            pi next = mp(curr.f + d4i[k], curr.s + d4j[k]);
            if(!visited[next.f][next.s] && inBounds(next.f, next.s) && maze[next.f][next.s] != '#') {
                q.push(mp(curr.f + d4i[k], curr.s + d4j[k]));
                if(a) prevs[curr.f + d4i[k]][curr.s + d4j[k]] = k+1;
                dist[curr.f+d4i[k]][curr.s + d4j[k]] = dist[curr.f][curr.s] + 1;
            }
        }
    }

    //F0R(i, 10) { F0R(j, 10) cout << dist[i][j] << " "; cout << "\n"; };
    return INF;
}

int mDiste(int eI, int eJ) {
    bool visited[1000][1000]; memset(visited, 0, sizeof visited);
    queue<pi> q;
    q.push(mp(eI, eJ));
    vt<vi> dist(1000, vi(1000,0));
    while(!q.empty()) {
        pi curr = q.front(); q.pop();
        visited[curr.f][curr.s] = true;
        if(maze[curr.f][curr.s] == '#') continue;
        if(maze[curr.f][curr.s] == 'M') return dist[curr.f][curr.s];
        F0R(k, 4) {
            pi next = mp(curr.f + d4i[k], curr.s + d4j[k]);
            if(!visited[next.f][next.s] && inBounds(next.f, next.s) && maze[next.f][next.s] != '#') {
                q.push(mp(curr.f + d4i[k], curr.s + d4j[k]));
                dist[curr.f+d4i[k]][curr.s + d4j[k]] = dist[curr.f][curr.s] + 1;
            }
        }
    }
    return INF;
}

void printRec(int i, int j) {
    // cout << "\n";
    // F0R(i, 10) {
    //     F0R(j, 10) {
    //         cout << prevs[i][j] << "|";
    //     } cout << "\n";
    // }

    if(i == start.f && j == start.s) return;
    else {
        printRec(i - d4i[prevs[i][j]-1], j - d4j[prevs[i][j]-1]);
        cout << d4c[prevs[i][j]-1];
    }

    // while(i != start.f || j != start.s) {
    //     pr(mp(i, j));
    //     cout << d4c[prevs[i][j]];
    //     i -= d4i[prevs[i][j]-1];
    //     j -= d4j[prevs[i][j]-1];
    // }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO(""); cin >> N >> M;

    F0R(i, N) {
        F0R(j, M) {
            cin >> maze[i][j];
            if(maze[i][j] == 'M') { monsters.pb(mp(i, j)); }; //we can move through monsters
            if(maze[i][j] == 'A') start = mp(i, j);
            if((i == 0 || j == 0 || i == N-1 || j == M-1) && maze[i][j] == '.') exits.pb(mp(i, j));
        }
    }

    if(start.f == 0 || start.s == 0 || start.f == N-1 || start.s == M-1)  { cout << "YES\n0"; return 0; };

    prevs[start.f][start.s] = 'A';

    if(sz(exits) >= 1000) {
        cout << "NO";
        return 0;
    }

    trav(ex, exits) {
        int aDist = dist(start.f, start.s, true, ex.f, ex.s);
        int mD = mDiste(ex.f, ex.s);
        if(aDist < mD) {
            cout << "YES\n" << aDist << "\n";
            printRec(ex.f, ex.s);
            return 0;
        }
    }

    cout << "NO";
}