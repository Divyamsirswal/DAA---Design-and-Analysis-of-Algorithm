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

bool dfs(vector<vector<ll>> &adj,vector<bool> &vis,ll s,ll d){
    if(s == d) return true;
    vis[s]=true;

    for(auto i : adj[s]){
        if(!vis[i]){
            if(dfs(adj,vis,i,d)){
                return true;
            }
        }
    }
    return false;
}

void divyam(){
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1);
    vector<bool> vis(n+1,false);

    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll s; cin>>s;
    ll d; cin>>d;

    if(dfs(adj,vis,s,d)){
        cout << "Yes path exist" << endl;
    }else{
        cout << "No path exist" << endl;
    }

}

int32_t main(){
    ll tt=1;
    // cin>>tt;

    for(ll _=0;_<tt;_++){
        divyam();
    }
}
