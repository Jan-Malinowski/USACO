#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
const int INF=1e9;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> tab(n);
    vector<int> above(n);
    vector<int> below(n);

    rep(i, n){
        cin >> tab[i];
    }
    sort(tab.begin(), tab.end());

    int i1=0;
    int i2=0;
    while(i2<n){
        if(tab[i2]-tab[i1]<=k){
            above[i1]=i2-i1+1;
            below[i2]=i2-i1+1;
            i2++;
        }
        else{
            i1++;
        }
    }

    int ans = 0;
    int maxbelow = 0;

    for(int i=1; i<n; i++){
        maxbelow = max(maxbelow, below[i-1]);
        ans = max(ans, above[i]+maxbelow);
    }

    cout << ans;

    return 0;
}

