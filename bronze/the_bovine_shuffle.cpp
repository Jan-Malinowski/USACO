#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n, x;
    cin >> n;
    vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i]; 
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<int> v(n);
	int T = 3;
	while(T--){
		for(int i = 0; i < n; i++){
			v[i] = b[a[i]-1];
		}
		b = v;
	} 
	
	for(int i = 0; i < n; i++){
		cout << v[i] << endl;
	}

    return 0;
}