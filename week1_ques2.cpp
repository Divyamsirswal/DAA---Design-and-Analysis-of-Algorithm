/* Divyam Sirswal */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lld = long double;
using ull = unsigned long long;
using mi = unordered_map<ll,ll>;
using pi = pair<ll,ll>;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define vvi(x,y) vector<vector<ll>>(x,vector<ll>(y));
#define rep(i,s,e) for(long long int i=s;i<e;i++)
#define repi(i,s,e) for(long long int i=s;i<=e;i++)
#define repr(i,e,s) for(long long int i=e-1;i>=s;i--)
#define fora(a) for(auto u:a)
#define ld long double
#define all(a) (a).begin(), (a).end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define mp make_pair
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef map<int, int> mii;
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
void google(int t) {cout << "Case #" << t << ": ";}
const ll N = 2000000;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

void solve(){
    ll n;
    cin>>n;

    //assuming i have sorted array as question says that
    vi v(n);

    rep(i,0,n) cin>>v[i];

    ll key;
    cin>>key;

    auto bs = binary_search(all(v),key);
    auto lb = lower_bound(all(v),key);

    ll idx = lb - v.begin();

    if(bs){
        cout << "Present " << idx+1 << endl;
    }else{
        cout << "Not Present" << endl;
    }


    // if you want to show the total no of comparison like its a binary search so lets do that

    // ll start = 0;
    // ll end = n - 1;
    // ll comp = 0;
    // while(start<end){
    //     ll mid = (start+end)/2;
    //     if(v[mid]==key){
    //         cout << mid+1 << endl;
    //         break;
    //     }else if(key>v[mid]){
    //         start=mid+1;
    //     }else{
    //         end=mid-1;
    //     }
    //     comp++;
    // }

    // cout << "Total comparison : " << comp << endl;


}

int main(){
    fastio();

    ll tt=1;
    cin>>tt;

    while(tt--){
        solve(); //don't worry i dont care about rating keep grinding
    }
}
