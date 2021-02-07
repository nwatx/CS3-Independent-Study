#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

#define f first
#define s second
#define bk back()
#define pb push_back

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

int N, Q;

const int MX = 2e5 + 5;

using T = long long; // or long long
const T EPS = 1e-9; // might want to change
using P = pair<T,T>; using vP = vector<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
    return sgn(a.f-b.f) == 0 && sgn(a.s-b.s) == 0; } 
T norm(const P& p) { return sq(p.f)+sq(p.s); }
T abs(const P& p) { return sqrt(norm(p)); }
T arg(const P& p) { return atan2(p.s,p.f); }
P conj(const P& p) { return P(p.f,-p.s); }
P perp(const P& p) { return P(-p.s,p.f); }
P dir(T ang) { return P(cos(ang),sin(ang)); }

P operator-(const P& l) { return P(-l.f,-l.s); }
P operator+(const P& l, const P& r) { 
    return P(l.f+r.f,l.s+r.s); }
P operator-(const P& l, const P& r) { 
    return P(l.f-r.f,l.s-r.s); }
P operator*(const P& l, const T& r) { 
    return P(l.f*r,l.s*r); }
P operator*(const T& l, const P& r) { return r*l; }
P operator/(const P& l, const T& r) { 
    return P(l.f/r,l.s/r); }
P operator*(const P& l, const P& r) { 
    return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
P operator/(const P& l, const P& r) { 
    return l*conj(r)/norm(r); }
P& operator+=(P& l, const P& r) { return l = l+r; }
P& operator-=(P& l, const P& r) { return l = l-r; }
P& operator*=(P& l, const T& r) { return l = l*r; }
P& operator/=(P& l, const T& r) { return l = l/r; }
P& operator*=(P& l, const P& r) { return l = l*r; }
P& operator/=(P& l, const P& r) { return l = l/r; }

P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
T cross(const P& p, const P& a, const P& b) {
    return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) { 
    P a = l.f, d = l.s-l.f;
    return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) { 
    return (p+reflect(p,l))/(T)2; }
bool p_on_seg(const P& p, const Line& l) {
    return sgn(cross(l.f,l.s,p)) == 0 && sgn(dot(p-l.f,p-l.s)) <= 0; }

using vi = vector<int>;
using vP = vector<P>;

vi hullInd(const vP& v) {
	int ind = int(min_element(all(v))-begin(v));
	vi cand, C{ind}; F0R(i,sz(v)) if (v[i] != v[ind]) cand.pb(i);
	sort(all(cand),[&](int a, int b) { // sort by angle, tiebreak by distance
		P x = v[a]-v[ind], y = v[b]-v[ind]; T t = cross(x,y);
		return t != 0 ? t > 0 : norm(x) < norm(y); }); 
	trav(c,cand) {
		while (sz(C) > 1 && cross(v[end(C)[-2]],v[C.bk],v[c]) <= 0) C.pop_back();
		C.pb(c); }
	return C;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(;;) {
        int n; cin >> n;
        if(!n) break;
        vP pts(n);
        
        F0R(i, n) {
            long long a, b;
            cin >> a >> b;
            pts[i] = P(a, b);
        }

        vi ret = hullInd(pts);
        
        cout << sz(ret) << '\n';
        trav(a, ret) {
            cout << pts[a].first << " " << pts[a].second << '\n';
        }
    }
}