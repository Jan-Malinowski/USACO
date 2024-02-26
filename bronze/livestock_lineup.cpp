#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    vector<pair<string, string> > pairs;
    string x[8];
    string cows[]={"Beatrice", "Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup"};
    int n,y;
    bool flag=false;

    cin >> n;
    rep(i, n){
        rep(j, 6){
            cin >> x[j];
        }
        pairs.push_back(make_pair(x[0], x[5]));
    }
    sort(cows, cows+8);
    do{
        rep(i, 8){
            rep(j, n){
                if(cows[i]==pairs[j].first && (cows[i-1]!=pairs[j].second && cows[i+1]!=pairs[j].second)){
                    flag=true;
                    break;
                }
            }
        }
        if(!flag){
            break;
        }
        flag=false;
    }while(next_permutation(cows, cows+8));

    for(auto z : cows){
        cout << z << "\n";
    }

    return 0;
}