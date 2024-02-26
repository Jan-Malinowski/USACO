#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

struct boot
{
    int depth, step, index;
};

bool com(boot a, boot b){
    return b.depth < a.depth;
}

int main(){
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, b;
    cin >> n >> b;
    vector<int> snow(n);
    rep(i, n){
        cin >> snow[i];
    }

    vector<boot> boots(b);
    rep(i, b){
        cin >> boots[i].depth >> boots[i].step;
        boots[i].index = i;
    }
    sort(boots.begin(), boots.end(), com);

    vector<int> tiles_by_depth;
    for(int i=1; i<n-1; i++){
        tiles_by_depth.push_back(i);
    }
    sort(tiles_by_depth.begin(), tiles_by_depth.end(),[&](int a, int b) { return snow[a] > snow[b]; });

    set<int> valid_tiles;
    rep(i,n){
        valid_tiles.insert(i);
    }

    int tile_at=0, needed_step=1;
    vector<bool> can_reach(b);

    for(const boot &b : boots){
        while(tile_at < tiles_by_depth.size() && snow[tiles_by_depth[tile_at]]>b.depth){
            auto removed = valid_tiles.find(tiles_by_depth[tile_at]);
			needed_step = max(needed_step, *next(removed) - *prev(removed));
			valid_tiles.erase(removed);
			tile_at++;
        }
        can_reach[b.index] = b.step >= needed_step;
    }
    for (bool b : can_reach) { cout << b << '\n'; }


    return 0;
}