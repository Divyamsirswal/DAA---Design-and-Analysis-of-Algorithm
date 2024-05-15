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

#define INF INT_MAX

struct Edge {
    int to;
    int weight;
};

void dij(vector<vector<Edge>>& adj, int s, vector<int>& dis) {
    int n = adj.size();
    dis.assign(n, INF);
    dis[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll a = pq.top().ss;
        ll b = pq.top().ff;
        pq.pop();

        for (Edge e : adj[a]) {
            int v = e.to;
            int q = e.weight;

            if (b + q < dis[v]) {
                dis[v] = b + q;
                pq.push({dis[v], v});
            }
        }
    }
}

void divyam(){
    ll n,m;
    cin>>n>>m;

    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll s; cin>> s;

    vector<int> dis;

    dij(adj, s, dis);

    for (int i = 0; i < n; ++i) {
        if (i != s) {
            if (dis[i] == INF)
                cout << "No path exist" << endl;
            else
                cout << dis[i] << endl;
        }
    }
}

int32_t main(){
    ll tt=1;
    // cin>>tt;

    for(ll _=0;_<tt;_++){
        divyam();
    }
}
