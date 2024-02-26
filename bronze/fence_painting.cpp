#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>


using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d,ans;
    cin >> a >> b >> c >> d;
    ans=min(max(b,d)-min(a, c), b-a+d-c); 

    cout << ans;

    return 0;
}