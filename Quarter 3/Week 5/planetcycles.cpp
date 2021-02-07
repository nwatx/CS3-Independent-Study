#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x.size())

int N, Q;

const int MX = 2e5+5;

void dfs(int x) {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // since this a functional graph, the destination of the teleporter is equal to the length of the cycle + the length it takes to reach a cycle (if any)

    // if the planets are in a cycle, then ans = length
    // otherwise compute the distance between node and the nearest cycle


}