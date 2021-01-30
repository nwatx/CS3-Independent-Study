#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define R0F(i, a) for(int i = a-1; i >=0; i--)
#define trav(a, x) for (auto &a : x)
#define sz(x) (int)x.size()
#define pb push_back
#define rsz resize
 
int N, Q;
 
const int MX = 2e5 + 5;
const int MS = 18;
 
using vi = vector<int>;
 
struct LCA {
	int N; vector<vi> par, adj;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) d++;
		par.assign(d,vi(N)); adj.rsz(N);
	}
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void dfs(int x = 0) {
		FOR(i,1,MS) par[i][x] = par[i-1][par[i-1][x]];
		trav(y,adj[x]) if (y != par[0][x]) 
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		F0R(i,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		R0F(i,sz(par)) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { // # edges on path
		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> N >> Q;
    LCA lca;
    lca.init(MX);

    cerr << sz(lca.par);
 
    FOR(i, 2, N+1) {
        int a; cin >> a;
        lca.ae(a, i);
    }
 
    lca.dfs(1);
 
    F0R(i, Q) {
        int a, b;
        cin >> a >> b;
        int ret = lca.jmp(a, b);
        if(!ret) ret--;
        cout << ret << "\n";
    }
}