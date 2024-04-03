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

int partition(vi &v,int start,int end,int &cmp,int &swp){
    int sz = start + rand() % (end-start+1);
    swap(v[sz],v[end]);
    int pivot = v[end];
    int i = start-1;

    for(int j=start;j<end;j++){
        cmp++;
        if(v[j]<pivot){
            i++;
            swp++;
            swap(v[i],v[j]);
        }
    }
    swp++;
    swap(v[i+1],v[end]);
    return i+1;
}

void quickSort(vi &v,int start,int end,int &cmp,int &swp){
    if(start<end){
        int p = partition(v,start,end,cmp,swp);
        quickSort(v,start,p-1,cmp,swp);
        quickSort(v,p+1,end,cmp,swp);
    }
}

auto solve = [](){
    int n;
    cin>>n;

    vi v(n);

    rep(i,0,n) cin>>v[i];

    int cmp=0,swp=0;

    quickSort(v,0,n-1,cmp,swp);

    cout << cmp << " " << swp << endl;

    for(auto i : v) cout << i << " ";
    cout << endl;
};

int32_t main(){
    divyam();

    int tt=1;
    // cin>>tt;

    for(int i=0;i<tt;i++)
        solve();
}
