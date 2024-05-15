/*
    Author : Divyam Sirswal
*/

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

bool dfs(vector<vector<ll>>& adj, ll v, ll u, vector<bool>& vis) {
    vis[v] = true;
    for (auto i : adj[v]) {
        if (!vis[i]) {
            if (dfs(adj, i, v, vis))
                return true;
        } else if (i != u) {
            return true;
        }
    }
    return false;
}

bool hasCycle(vector<vector<ll>>& adj) {
    ll n = adj.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (dfs(adj, i, -1, vis))
                return true;
        }
    }
    return false;
}

void divyam(){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> adj(n);

    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(hasCycle(adj)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int32_t main(){
    ll tt=1;
    // cin>>tt;

    for(ll _=0;_<tt;_++){
        divyam();
    }
}
