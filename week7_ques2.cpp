#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF LLONG_MAX
#define endl "\n"
#define vi vector<ll>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repi(i, a, b) for (ll i = a; i <= b; i++)

struct Edge {
    ll s, d, w;
};

void bellmanFord(vector<ll> &dist, vector<Edge> &edges, ll src, ll n) {
    dist[src] = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (Edge e : edges) {
            ll u = e.s;
            ll v = e.d;
            ll weight = e.w;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (Edge e : edges) {
        ll u = e.s;
        ll v = e.d;
        ll weight = e.w;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative cycle" << endl;
            return;
        }
    }
}

void solve() {
    ll n, src;
    cin >> n >> src;

    vector<Edge> edges;
    vector<ll> dist(n, INF);

    repi(i, 1, n) {
        repi(j, 1, n) {
            ll we;
            cin >> we;
            if (we != 0) {
                edges.push_back({i, j, we});
            }
        }
    }

    bellmanFord(dist, edges, src, n);

    repi(i, 1, n) {
        if (dist[i] == INF) {
            cout << "No path" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    ll tt = 1;
    // cin >> tt;

    rep(_, 0, tt) {
        solve();
    }
}
