#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, x) for(int i=0; i<x; i++)
typedef long long ll;

int N, M, R;
ll cows[100005], farmers[100005];
pair<ll,ll> stores[100005];
ll value[100005];

int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    long long ans=0;
    int x, y;
    cin >> N >> M >> R;
    rep(i, N){
        cin >> cows[i];
    }
    rep(i, M){
        cin >> x >> y;
        stores[i]=make_pair(y, x);
    }
    rep(i, R){
        cin >> farmers[i];
    }
    sort(cows, cows + N, greater<>());
    sort(stores, stores + M, greater<>());
    sort(farmers, farmers + R, greater<>());

    int idxS=0, idxC=0;

    while(1){
        if(idxC == N || idxS == M){
            break;
        }
        if(stores[idxS].second > cows[idxC]){
            value[idxC]+= cows[idxC] * stores[idxS].first;
            stores[idxS].second -= cows[idxC];
            idxC++;
        }
        else{
            cows[idxC]-=stores[idxS].second;
            value[idxC] += stores[idxS].second * stores[idxS].first;
            idxS++;
        }
    }
    sort(value, value+N);
    rep(i, R){
        value[i]= max(farmers[i], value[i]);
    }
    rep(i, N){
        ans += value[i];
    }

    cout << ans;

    return 0;
}

