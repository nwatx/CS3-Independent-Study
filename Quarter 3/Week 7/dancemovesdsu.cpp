#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

/**
 * Description: Disjoint Set Union with path compression
	 * and union by size. Add edges and test connectivity. 
	 * Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int N, K;

const int MX = 1e5+1;

int P[MX]; // successor
unordered_set<int> trav[MX]; // all nodes traversed
unordered_set<int> components[MX];

int main() {
	setIO("");

	cin >> N >> K;

	for(int i = 1; i <= N; i++) { P[i] = i; trav[i].insert(i); }

	for(int i = 0; i < K; i++) {
		int a, b; cin >> a >> b; // swap a and b, then add to whichever node visited those.

		trav[P[a]].insert(b);
		trav[P[b]].insert(a);
		swap(P[a], P[b]);
	}

	// for(int i = 1; i <= N; i++) cerr << "P[i]: " << P[i] << "\n";

	DSU dsu;
	dsu.init(N+1);

	for(int i = 1; i <= N; i++) dsu.unite(i, P[i]);
	for(int i = 1; i <= N; i++) 
		for(int a: trav[i]) components[dsu.get(i)].insert(a);

	for(int i = 1; i <= N; i++) cout << components[dsu.get(i)].size() << "\n";
}