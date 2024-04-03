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

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pos = partition(arr, low, high);
        if (pos - low == k - 1)
            return arr[pos];
        if (pos - low > k - 1)
            return kthSmallest(arr, low, pos - 1, k);
        return kthSmallest(arr, pos + 1, high, k - (pos - low + 1));
    }
    return INT_MAX;
}

auto solve = [](){
    int n;
    cin>>n;

    vi v(n);

    rep(i,0,n) cin>>v[i];

    int k; cin>>k;

    int result = kthSmallest(arr, 0, n - 1, k);

    if(result!=INT_MAX){
        cout << result << endl;
    }else{
        cout << -1 << endl;
    }

};

int32_t main(){
    divyam();

    int tt=1;
    cin>>tt;

    for(int i=0;i<tt;i++)
        solve();
}
