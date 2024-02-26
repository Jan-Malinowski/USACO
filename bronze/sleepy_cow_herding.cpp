#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    int l=(b-a-1), r=(c-b-1);

    if(l==0 && r==0){
        cout << "0\n";
    }
    else if(l==1 || r==1){
        cout << "1\n";
    }
    else{
        cout << "2\n";
    }
    cout << max(l, r);
    

    return 0;
}