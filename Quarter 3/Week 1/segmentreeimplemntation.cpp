#include <bits/stdc++.h>
using namespace std;

struct Seg {

    int size; 
    vector<long long> sums;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            sums[x] = v;
            return;
        }

        int m = (lx + rx) /2;
        if(i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }

        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return 0;
        if(lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2*x+1, lx, m);
        long long s2 = sum(l, r, 2*x+2, m, rx);
        return s1 + s2;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Seg st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        st.set(i, v);
    }

    // for(int i = 0; i < st.sums.size(); ++i) {
    //     cout << st.sums[i] << "|\n";
    // }

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            st.set(b, c);
        } else {
            cout << st.sum(b, c) << "\n";
        }
    }

    return 0;
}