#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long tab[n+1];
    tab[0]=0;
    int x;
    for(int i=1; i<n+1; i++){
        cin >> x;
        tab[i]=(tab[i-1]+x)%7;
    }
    int ans=0;
    vector<int> left(7), right(7);

    for(int i=1; i<n+1; i++){
        right[tab[i]]=i;
    }
    for(int i=n; i>0; i--){
        left[tab[i]]=i;
    }
    rep(i, 7){
        ans = max(ans, right[i]-left[i]);
    }

    cout << ans;

    return 0;
}

