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
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, ans=0;
    cin >> n;
    vector<tuple<int, string, int>> data;
    int a, c;
    string b;
    rep(i, n){
        cin >> a >> b >> c;
        data.push_back(make_tuple(a,b,c));
    }
    sort(data.begin(), data.end());
    int bessie=7, elsie=7, mildred=7;
    string wall="BEM", temp;

    rep(i, n){
        a = get<0>(data[i]);
        b = get<1>(data[i]);
        c = get<2>(data[i]);
        if(b=="Bessie"){
            bessie+=c;
        }
        else if(b=="Elsie"){
            elsie+=c;
        }
        else{
            mildred+=c;
        }
        int maxi=max(bessie, max(elsie, mildred));
        temp="";
        if(bessie==maxi){
            temp+='B';
        }
        if(elsie==maxi){
            temp+='E';
        }
        if(mildred==maxi){
            temp+='M';
        }
        if(temp!=wall){
            ans++;
            wall=temp;
        }
    }

    cout << ans;

    return 0;
}