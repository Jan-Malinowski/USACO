#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int n;
vector<int> A;

bool work_right(int start, int rad){
    int cur=start, nex=0;
    while(cur < A.back()){
        while(nex+1 < n && A[nex+1]<=cur+rad) nex++;
        if(A[nex] == cur){
            return false;
        }
        cur = A[nex];
        rad -= 2;
    }
    return true;
}

bool work_left(int start, int rad){
    for(int &x : A) x*=-1;
    reverse(A.begin(), A.end());
    bool ans = work_right(-start, rad);
    reverse(A.begin(), A.end());
    for(int &x : A) x*=-1;
    return ans;
}

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);    

    cin >> n;
    A.resize(n);
    for(int i=0; i<n; ++i){
        cin >> A[i];
		A[i] *= 2;
    }
    sort(A.begin(), A.end());
    int low=0, hi=2e9;
    while(low<hi){
        int mid = low+(hi-low)/2;
        int l = A.front(), r=A.back();
        while(l<r){
            int m = l+(r-l)/2;
			if(work_right(m, mid)) r = m;
			else l = m+1;
        }
        if(work_left(l, mid)){
            hi = mid;
        }
        else{
            low=mid+1;
        }
    }

    cout << low/2 << '.' << (low%2 ? 5:0);
    

    return 0;
}