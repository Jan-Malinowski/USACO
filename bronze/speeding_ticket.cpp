#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ifstream in("speeding.in");
    ofstream out("speeding.out");
    int ans=0, cow_miles=0, miles=0, n, m;
    in >> n >> m;
    int road_segment[n], speed_limit[n], cow_segment[m], cow_speed[m];
    rep(i, n){
        in >> road_segment[i] >> speed_limit[i];
    }
    int j=0;
    miles=road_segment[0];
    rep(i, m){
        in >> cow_segment[i] >> cow_speed[i];
        cow_miles+=cow_segment[i];
        ans=max(ans, cow_speed[i]-speed_limit[j]);
        while(cow_miles>miles){
            j++;
            miles+=road_segment[j];
            ans=max(ans, cow_speed[i]-speed_limit[j]);
        }
        ans=max(ans, cow_speed[i]-speed_limit[j]);
        if(cow_miles==miles){
            j++;
            miles+=road_segment[j];
        }
    }
    out << ans;

    return 0;
}