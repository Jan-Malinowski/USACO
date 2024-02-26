#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n, q;
    cin >> n >> q;
    long long tab[n+1];
    tab[0]=0;
    long long l, r, z;
    for(int i=1; i<n+1; i++){
        cin >> z;
        tab[i] = z+tab[i-1];
    }
    rep(i, q){
        cin >> l >> r;
        cout << tab[r]-tab[l] << "\n";
    }

    return 0;
}