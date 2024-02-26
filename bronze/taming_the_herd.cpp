#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> tab(n);
    rep(i, n){
        cin >> tab[i];
    }
    int minv=0, maxv=0;
    if(tab[0]!=-1 && tab[0]!=0){
        cout << "-1\n";
        return 0;
    }
    tab[0]=0;
    for(int i=0; i<n; i++){
        if(tab[i]!=-1){
            tab[i-tab[i]]=0;
        }
    }
    int last=0;
    for(int i=0; i<n; i++){
        if(tab[i]==0){
            minv++;
            last=i;
        }
        if(tab[i]!=-1 && tab[i]!=0 && i-tab[i]<last){
            cout << "-1\n";
            return 0;
        }
    }
    for(int i=0; i<n; i++){
		int j = i;

		for( ; tab[j]==-1; j++);

		if(tab[j]==0){
			maxv += j-i;
        }

		i = j;
	}
    cout << minv << " " << minv+maxv << endl;
    return 0;
}