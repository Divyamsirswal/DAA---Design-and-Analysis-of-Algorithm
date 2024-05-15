#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define vi vector<ll>
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define N 2000005
#define mod 1e9+7
#define sz(x) sizeof(x)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"


ll prim(vector<vector<pair<ll,ll>>> &adj){
    ll res = 0;
    unordered_set<ll> vis;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    ll s=0;
    vis.insert(s);

    for(auto i : adj[s]){
        pq.push(i);
    }

    while(!pq.empty()){
        ll w = pq.top().ff;
        ll src = pq.top().ss;
        pq.pop();

        if(vis.find(src)!=vis.end()){
            continue;
        }
        vis.insert(src);
        res += w;

        for(auto i : adj[src]){
            ll k = i.ss;
            if(vis.find(k)==vis.end()){
                pq.push(i);
            }
        }
    }
    return res;
}

void divyam(){
    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>> adj(n);

    rep(i,0,m){
        ll s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back({w, d});
        adj[d].push_back({w, s});
    }

    ll mn = prim(adj);

    cout << mn << endl;
}

int32_t main(){
    ll tt=1;
    // cin>>tt;

    for(ll _=0;_<tt;_++){
        divyam();
    }
}
