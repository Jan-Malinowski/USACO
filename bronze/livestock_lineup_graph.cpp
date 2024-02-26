#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;
vector<string> COWS{"Beatrice", "Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup"};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sort(COWS.begin(), COWS.end());

    map<string, int> cow_inds;
	for (int i = 0; i < COWS.size(); i++) { cow_inds[COWS[i]] = i; }

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;
    string cow1, cow2, trash;
    vector<vector<int> > neighbors(COWS.size());

    rep(i, n){
        cin >> cow1 >> trash >>  trash >> trash >> trash >> cow2;

        int c1= cow_inds[cow1];
        int c2 = cow_inds[cow2];
        neighbors[c1].push_back(c2);
        neighbors[c2].push_back(c1);
    }

    vector<int> order;
    vector<bool> added(COWS.size());

    rep(i, COWS.size()){
        if(!added[i] && neighbors[i].size() <= 1){
            added[i]=true;
            order.push_back(i);

            if(neighbors[i].size() == 1){
                int prev = i;
                int at = neighbors[i][0];
                while(neighbors[at].size() == 2){
                    added[at] = true;
                    order.push_back(at);

                    int a = neighbors[at][0];
                    int b = neighbors[at][1];
                    int temp_at = a == prev ? b : a;
                    prev = at;
                    at = temp_at;
                }
                added[at]=true;
                order.push_back(at);
            }
        }

    }

    for(int c : order){
        cout << COWS[c] << endl;
    }
    

    return 0;
}