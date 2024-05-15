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

bool solver(vector<vector<ll>> &adj,ll s){
    ll n = adj.size();
    vector<ll> color(n,-1);
    queue<ll> q;

    q.push(s);
    color[s] = 0;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for(auto i : adj[u]){
            if(color[i] == -1){
                color[i] = 1 - color[u];
                q.push(i);
            }else if(color[i] == color[u]){
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<ll>> &adj){
    ll n = adj.size();
    for(int i=0;i<n;i++){
        if(!solver(adj,i)){
            return 0;
        }
    }
    return 1;
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

    if(helper(adj)){
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
