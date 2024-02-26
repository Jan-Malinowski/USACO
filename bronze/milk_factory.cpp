#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, ans = -1;
int outdeg[105], indeg[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		outdeg[a]++;
		indeg[b]++;
	}
	for (int i = 1; i <= N; ++i) {
		if (outdeg[i] == 0 && ans != -1) {
			ans = -1;
			break;
		}
		if (outdeg[i] == 0) ans = i;
	}
	cout << ans;

    return 0;
}