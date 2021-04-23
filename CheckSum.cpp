#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int n, s;
int x[MAX];
int dp[MAX];

// dp[i] = 1 thì có s, dp[i] = 0 thì ko có s

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[x[i]] = 1;
        for(int j = s; j >= x[i]; j--) {
            if(dp[j-x[i]] == 1) dp[j] = 1;
        }
    }
    if(dp[s] == 1) cout << "YES";
    else cout << "NO";

    return 0;
}