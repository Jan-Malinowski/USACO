#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    char a;
    int n, x, y;
    vector<pair<int, int>> north, east;
    cin >> n;
    int order[n];
    map<int, int> ans;

    rep(i, n){
        cin >> a >> x >> y;
        ans[x]=-1;
        order[i]=x;
        if(a=='N'){
            north.push_back(make_pair(x, y));
        }
        else{
            east.push_back(make_pair(y, x));
        }
    }
    sort(north.begin(), north.end());
    sort(east.begin(), east.end());
    int time_north, time_east;
    for(auto i:east){
        for(auto j:north){
            if(ans[j.first]!=-1) {
				continue;
			}
            if(i.second<j.first && i.first>j.second){
                time_north=j.first-i.second;
                time_east=i.first-j.second;
                if(time_north>time_east){
                    ans[i.second]=time_north;
                    break;
                }
                else if(time_north<time_east){
                    ans[j.first]=time_east;
                }
            }
            
        }
    }
    for(auto i:order){
        if(ans[i]==-1){
            cout << "Infinity\n";
        }
        else{
            cout << ans[i] << "\n";
        }
    }

    return 0;
}