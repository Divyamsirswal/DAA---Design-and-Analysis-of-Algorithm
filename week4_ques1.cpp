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

int comp = 0;
int inv = 0;

void merge(vi &v,int mid,int start,int end){
    int left = mid - start + 1;
    int right = end - mid;

    vi l(left),r(right);

    int i=0,j=0,k;

    for(i=0;i<left;i++){
        l[i] = v[start + i];
    }
    for(j=0;j<right;j++){
        r[j] = v[mid+j+1];
    }
    i=0,j=0,k=start;


    while(i<left && j<right){
        comp++;
        if(l[i]<r[j]){
            v[k++]=l[i];
            i++;
        }else{
            v[k++]=r[j];
            j++;
            inv+=(mid-start+1)-i;
        }
    }
    while(i<left){
        v[k++]=l[i];
        i++;
    }
    while(j<right){
        v[k++]=r[j];
        j++;
    }
}

void mergeSort(vi &v,int start,int end){
    if(start<end){
        int mid = start + (end - start)/2;
        mergeSort(v,start,mid);
        mergeSort(v,mid+1,end);
        merge(v,mid,start,end);
    }
}

auto solve = [](){
    int n;
    cin>>n;

    vi v(n);

    rep(i,0,n) cin>>v[i];

    int start = 0;
    int end = n - 1;

    comp = 0;
    inv = 0;

    mergeSort(v,start,end);

    rep(i,0,n) cout << v[i] << " ";
    cout << endl;

    cout << comp << " " << inv << endl;
};

int32_t main(){
    divyam();

    int tt=1;
    cin>>tt;

    for(int i=0;i<tt;i++)
        solve();
}
