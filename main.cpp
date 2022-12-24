#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define int long long
#define pb push_back
#define pi pair<int,int> 
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define take(a,b) for(int i=0;i<b;i++){int x;cin>>x;a.pb(x);}
#define all(x) x.begin(),x.end()
#define svz(x) (int)(x).size()
#define umap unordered_map<int,int,custom_hash>
#define vl vector<int> 
#define endl '\n'
// typedef tree<int, null_type,greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;
const int MOD =  998244353,inf = 1e18 + 5;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
int power(int a, int b,int mod) { int res = 1; while (b > 0) {if (b & 1) res = (res * a)%mod; a = (a * a)%mod; b >>= 1;} return res%mod;}
int ceil_div(int a, int b){return a % b == 0 ? a / b : a / b + 1;}
bool sortbylen(string &s1,string &s2){return s1.size() < s2.size();}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> dp(1001,vector<int>(1001,0)),arr(1001,vector<int>(1001,0));
    fr(i,0,n){
        int h,w;
        cin>>h>>w;
        arr[h][w]+=h*w;
    }
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            dp[i][j] = arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    while(q--){
        int hs,ws,hb,wb,ans=0;
        cin>>hs>>ws>>hb>>wb;
        int sum = dp[hb-1][wb-1]-dp[hb-1][ws]-dp[hs][wb-1]+dp[hs][ws];
        cout<<sum<<endl;
    }
}
int32_t main(void)
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tests=1;
    cin>>tests;
    for(int i=0;i<tests;i++){solve();}   
};