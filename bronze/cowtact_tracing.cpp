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
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    string status;
    int n, t, x=0, y=INF, z=0;
    cin >> n >> t;
    cin >> status;
    vector<vector<int>> interactions(t, vector<int>(3));
    rep(i, t){
        cin >> interactions[i][0] >> interactions[i][1] >> interactions[i][2];
        --interactions[i][1];
        --interactions[i][2];
    }
    sort(interactions.begin(), interactions.end());
    rep(i, n){
        if(status[i]=='1'){
            bool possible=false;
            rep(j, t+1){
                string temp(n, '0');
                vector<int> time(n, j);
                temp[i]='1';
                rep(x, t){
                    bool firstins=false;
                    if(temp[interactions[x][1]]=='1' && time[interactions[x][1]]>0){
                        if(temp[interactions[x][2]]=='0'){
                            firstins=true;
                        }
                        temp[interactions[x][2]]='1';
                        time[interactions[x][1]]--;
                    }
                    if(temp[interactions[x][2]]=='1' && !firstins && time[interactions[x][2]]>0){
                        temp[interactions[x][1]]='1';
                        time[interactions[x][2]]--;
                    }
                }   

                if(temp==status){
                    possible=true;
                    y=min(y, j);
                    z=max(z, j);
                }
            }
            if(possible){
                x++;
            }
        }
    }

    cout << x << " " << y << " ";
    if(z==t){
        cout << "Infinity";
    } 
    else{
        cout << z;
    }

    return 0;
}