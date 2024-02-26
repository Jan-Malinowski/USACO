#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n;
    cin >> n;

    set<int> deck;

    rep(i, 2*n){
        deck.insert(i+1);
    }
    int x;
    vector<int> f(n/2), s(n/2);
    rep(i, n/2){
        cin >> x;
        deck.erase(x);
        f[i]=x;
    }
    rep(i, n/2){
        cin >> x;
        deck.erase(x);
        s[i]=x;
    }

    set<int> lower_half;
    set<int> upper_half;

    int i = 0;
    for (int card : deck) {
        if (i < n / 2) lower_half.insert(card);
        else if (i < n) upper_half.insert(card);
        else break;
        i++;
    }

    int ans=0;
    for(int i=0; i<n/2; i++){
        auto it = upper_half.upper_bound(f[i]);
        if(it!=upper_half.end()){
            ans++;
            upper_half.erase(it);
        }
        else{
            upper_half.erase(upper_half.begin());
        }
    }

    for(int i=0; i<n/2; i++){
        auto it = lower_half.upper_bound(s[i]);
        if(it!=lower_half.begin()){
            it--;
            ans++;
            lower_half.erase(it);
        }
        else{
            lower_half.erase(prev(lower_half.end()));
        }
    }

    cout << ans;



    return 0;
}