#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> tab(n+1);
    int x, y;
    rep(i, k){
        cin >> x >> y;
        --x;
        --y;
        tab[x]++;
        tab[y+1]--;
    }
    for(int i=1; i<n; i++){
        tab[i]+=tab[i-1];
    }


    sort(tab.begin(), tab.end());

    cout << tab[n/2 + 1];
    


    return 0;
}

