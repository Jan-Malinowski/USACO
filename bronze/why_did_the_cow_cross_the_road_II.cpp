#include <iostream>
#include <string>

using namespace std;

#define rep(i, a) for(int i=0; i<a; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string cows;
    cin >> cows;
    pair<int, int> data[26];
    int ans=0;
    rep(i, 26){
        data[i].first=-1;
        data[i].second=-1;
    }
    rep(i,52){
        if(data[cows[i]-65].first==-1){
            data[cows[i]-65].first=i;
        }
        else{
            data[cows[i]-65].second=i;
        }
    }
    rep(i, 26){
        rep(j, 26){
            if(data[i].second > data[j].first && data[i].second<data[j].second && data[i].first<data[j].first){
                ans++;
            }
        }
    }
    cout << ans;
    

    return 0;
}