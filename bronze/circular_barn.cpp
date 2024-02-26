#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    int r[n];
    long cows=0, l_cows;
    rep(i, n){
      cin >> r[i];
      cows+=r[i];
    }
    l_cows=cows;
    long ans=999999999, path=0;
    rep(i, n){
      int room = i+1;
      for(int j=1; j<n; j++){
        path+=j*r[room%n];
        room++;
      }
      ans = min(ans, path);
      path=0;
      l_cows=cows;
    }

    cout << ans;

    return 0;
}

