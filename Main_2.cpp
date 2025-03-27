#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define int long long 
#define pb push_back
#define pi pair<int,int> 
#define fr(i,a,b) for(int i=a;i<b;i++)
#define take(a,b) for(int i=0;i<b;i++){int xx;cin>>xx;a.pb(xx);}
#define all(x) x.begin(),x.end()
#define svz(x) (int)(x).size()
#define mems(t,x) memset(t , x , sizeof(t)) ;
#define vl vector<int> 
#define endl '\n'
const int inf = 1e18;
const int MOD = 1000000007;
const int maxN = 1e7;

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x<<"= "; _print(x); cerr << endl;
#define deb2(x, y) cerr << #x << "= " << x << "," << #y << "= " << y << endl;
#else
#define deb(x)
#define deb2(x, y)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int modMul(long long a, long long b){long long res = 0;a %= MOD;while (b) {if (b & 1)res = (res + a) %MOD ;a = (2 * a) % MOD;b >>= 1;}return res;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
int power(int a, int b,int mod) { int res = 1; while (b > 0) {if (b & 1) res = (res * a)%mod; a = (a * a)%mod; b >>= 1;} return res%mod;}
int ceil_div(int a, int b){return a % b == 0 ? a / b : a / b + 1;}
int inv(int x,int MOD){return power(x,MOD-2,MOD);}

int grid[2004][2004];
int n,m,d;
int vis[2004][2004];
int rec(int i,int j,int lim,int d){
    // deb2(i,j);
    vis[i][j] = 1;
    // deb(vis[i][j]);
    int curr = (i==1 ? 1 : 0);
    for(int k=1;k<=m;k++){
        if(i!=1){
            if(vis[i][k]==1)continue;
        }
        if(abs(k-j)>d || !grid[i][k])continue;
        curr+=rec(i,k,lim,d);
    }
    if(i==1)return curr;
    for(int k=1;k<=m;k++){
        if(abs(k-j)>lim || !grid[i-1][k])continue;
        curr+=rec(i-1,k,lim,d);
    }
    return curr;
}
void solve(){
    cin>>n>>m>>d;
    mems(grid,0);
    mems(vis,0);
    fr(i,1,n+1){
        fr(j,1,m+1){
            char x;
            cin>>x;
            grid[i][j] = (x=='#' ? 0 : 1);
        }
    }
    int ans = 0;
    int lim = d*d-1;    
    lim = sqrt(lim);
    fr(i,1,m+1){
        if(grid[n][i])
        ans+=rec(n,i,lim,d);
    }
    cout<<ans;
}   

int32_t main(void){
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tests=1;
    // pre();
    cin>>tests; 
    for(int i=0;i<tests;i++){solve();cout<<endl;}   
};