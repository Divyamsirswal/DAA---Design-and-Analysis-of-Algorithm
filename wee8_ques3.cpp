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


struct Edge {
    ll s, d, w;
};

class DisjointSet {
private:
    vector<ll> parent, rank;

public:
    DisjointSet(ll n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ll find(ll u) {
        return (parent[u] == u) ? u : (parent[u] = find(parent[u]));
    }

    void merge(ll u, ll v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv])
                swap(pu, pv);
            parent[pv] = pu;
            if (rank[pu] == rank[pv])
                ++rank[pu];
        }
    }
};

ll kruskal(vector<Edge>& edges, ll n) {
    sort(edges.begin(), edges.end(), [](Edge& a,Edge& b) {
        return a.w < b.w;
    });

    DisjointSet ds(n);
    ll mn = 0;

    for (auto i : edges) {
        int u = i.s, v = i.d, w = i.w;
        if (ds.find(u) != ds.find(v)) {
            mn += w;
            ds.merge(u, v);
        }
    }

    return mn;
}


void divyam(){
    ll n;
    cin >> n;

    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll wt;
            cin >> wt;
            if (wt != 0) {
                edges.push_back({i, j, wt});
            }
        }
    }

    ll res = kruskal(edges, n);
    cout << res << endl;
}

int32_t main(){
    ll tt=1;
    // cin>>tt;

    for(ll _=0;_<tt;_++){
        divyam();
    }
}
