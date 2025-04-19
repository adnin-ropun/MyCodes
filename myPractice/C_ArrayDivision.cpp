#include <bits/stdc++.h>
using namespace std;

#define sort1a(p) sort(p.begin(), p.end())
#define sort1d(p) sort(p.begin(), p.end(), greater<>())
#define sort2a(p) sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.second < b.second; })
#define sort2d(p) sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.second > b.second; })
#define sort1a_2d(p) sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.first < b.first || (a.first == b.first && a.second > b.second); })
#define sort1d_2a(p) sort(p.begin(), p.end(), [](auto &a, auto &b) { return a.first > b.first || (a.first == b.first && a.second < b.second); })

struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << " "; }; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
#define Add(x, y) ((x + (y)) % mod)
#define Sub(x, y) ((x - (y) + mod) % mod)
#define Mult(x, y) (((x) % mod * (y) % mod) % mod)
#define Pow(x, y) ([](int a, int b) { int r = 1; while (b) { if (b & 1) r = (r * a) % mod; a = (a * a) % mod; b >>= 1; } return r; })(x, y)
#define Inv(x) Pow(x, mod - 2)
#define Div(x, y) Mult(x, Inv(y))

vector<int> prefix_sum(vector<int>& v){
    vector<int>p(v.size()+1);

    for(int i=0;i<v.size();i++){
        p[i+1]=p[i]+v[i];
    }
    return p;
}

signed main(){
    int n,m;cin>>n>>m;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>r;
    int x=ceil(n/(float)m);

    if(n%m!=0){auto it=(max_element(v.begin(),v.end()));r.push_back(*it);v.erase(it);}
    // vdebug(r);
    vector<int> p=prefix_sum(v);
    // vdebug(p);

    for(int i=0;i<p.size()-x;i+=x){
        r.push_back(p[i+x]-p[i]);
    }
    // vdebug(r);
    cout<<*(max_element(r.begin(),r.end()));
}