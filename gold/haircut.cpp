#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;

const long long MOD = 1e9+7;

int sum(vector<ll> &segtree, int a, int b){
    int c = segtree.size() /2;
    a+=c;
    b+=c;
    int s =0;
    while(a<=b){
        if(a%2) s+=segtree[a++];
        if(!(b%2)) s +=segtree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

void add(vector<ll> &segtree, int k, ll x){
    int c =segtree.size()/2;
    k+=c;
    segtree[k]+=x;
    for(k/=2;k>=1;k/=2){
        segtree[k] = segtree[2*k]+segtree[2*k+1];
    }
}

int main(){
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);
    int n;
    cin >> n;

    int c = 0;
    while((1<<c) <= n+1){
        c++;
    }
    c = 1 << c;

    vector<ll> segtree(2*c);
    vector<ll> ans(n+2);
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        ans[a+1] += sum(segtree, a+1, n+1);
        add(segtree, a, 1);
    }

    ll total=0;
    rep(i,n){
        total+=ans[i];
        cout << total << "\n";
    }

    return 0;
}