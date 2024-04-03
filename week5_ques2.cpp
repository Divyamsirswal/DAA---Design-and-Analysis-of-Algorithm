//Divyam Sirswal ----> keep pushing the limits

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl "\n"
#define all(x) x.begin(),x.end()
#define pi pair<int,int>
#define umpi unordered_map<int,int>
#define umpc unordered_map<char,int>
#define vvi(x,y) vector<vector<ll>>(x,vector<ll>(y))
#define rep(i,s,e) for(int i=s;i<e;i++)
#define repi(i,s,e) for(int i=s;i<=e;i++)
#define repr(i,e,s) for(int i=e-1;i>=s;i--)
#define ff first
#define ss second
#define pb push_back
#define divyam() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 20000005;
const int MOD = 1e9 + 7;
const int INF = 1e9;


auto solve = [](){
    int n;
    cin>>n;

    vi v(n);

    rep(i,0,n) cin>>v[i];

    int target; cin>>target;

    pair<int,int> p;

    sort(all(v));

    int start=0;
    int end = n-1;

    while(start<end){
        if(v[start]+v[end]==target){
            p.ff=v[start];
            p.ss=v[end];
            break;
        }else if(v[start]+v[end] < target){
            start++;
        }else{
            end--;
        }
    }
    cout << p.ff << " " << p.ss << endl;
};

int32_t main(){
    divyam();

    int tt=1;
    cin>>tt;

    for(int i=0;i<tt;i++)
        solve();
}
