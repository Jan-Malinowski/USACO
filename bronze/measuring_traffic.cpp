// Problem: Problem 3. Measuring Traffic
// Contest: USACO - USACO 2019 February Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=917
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file traffic.in  
// Output: file traffic.out  
// Solved: 20223-04-12 21:59

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

ifstream in("traffic.in");
ofstream out("traffic.out");

void solve(){

    int n;
    in >> n;

    string type[100];
    int low[100];
    int high[100];

    for (int i = 0; i < n; i++){
        string t;
        int l, h;
        in >> t >> l >> h;
        type[i] = t;
        low[i] = l;
        high[i] = h;
    }

    int ans_lower = -10000, ans_higher = 10000;

    for (int i = n - 1; i >= 0; i--){
        if (type[i] == "none"){
            ans_lower = max(ans_lower, low[i]);
            ans_higher = min(ans_higher, high[i]);
        }
        else if (type[i] == "off"){
            ans_lower += low[i];
            ans_higher += high[i];
        }
        else if (type[i] == "on"){
            ans_higher -= low[i];
            ans_lower -= high[i];
        }
    }

    out << max(0, ans_lower) << ' ' << ans_higher << '\n';

    ans_lower = -10000;
    ans_higher = 10000;

    for (int i = 0; i < n; i++){
        if (type[i] == "none"){
            ans_lower = max(ans_lower, low[i]);
            ans_higher = min(ans_higher, high[i]);
        }
        else if (type[i] == "on"){
            ans_lower += low[i];
            ans_higher += high[i];
        }
        else if (type[i] == "off"){
            ans_higher -= low[i];
            ans_lower -= high[i];
        }
    }

    out << max(0, ans_lower) << ' ' << ans_higher << '\n';

}

int main(){
    solve();
    return 0;
}