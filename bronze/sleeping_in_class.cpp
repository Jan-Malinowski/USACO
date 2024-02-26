#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

const int INF=1e9;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int maxint=0, sum=0;
    rep(i, n){
        cin >> a[i];
        maxint = max(maxint, a[i]);
        sum += a[i];
    }
    vector<int> factors;
    if(sum==0){
        cout << 0 << "\n";
        return;
    }
    else{
        for(int i=maxint; i<=sum/2; i++){
            if(sum%i==0){
                factors.push_back(i);
            }
        }
    }
    factors.push_back(sum);
    int ans=INF,temp=0, ch;
    bool good=true;
    for(auto x:factors){
        maxint=x;
        good=true;
        ch=0;
        temp=0;
        rep(i, n){
            temp+=a[i];
            if(temp>=maxint){
                if(temp==maxint){
                    temp=0;
                    ch++;
                }
                else{
                    good=false;
                    break;
                }
               
            }

        }
        if(good && ch==sum/x){
            ans = min(ans, n-ch);
        }
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}





